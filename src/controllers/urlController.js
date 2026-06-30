// const encode=require("../utils/base62")
const { nanoid } = require("nanoid")
const prisma = require("../config/prisma")
const validator = require("validator")
const redisClient = require("../config/redis")
const { produceClickEvents } = require("../kafka/producer")
const { urlRedirectCounter, cachehitcounter, cachemisscounter }=require('../config/metric')


// function solve(id) {
//     console.log(encode(id.toString().slice(-6)))
// }

// solve(13823423432)

exports.shortenUrl = async (req, res) => {
    try {
        const { longUrl, customAlias, expiresAt } = req.body;
        if (!validator.isURL(longUrl)) {
            return res.status(400).json({
                message: "Invalid Url"
            })
        }
        const userId = req.user.userId;
        const reservedAlias = [
            "auth", "login", "register", "shorten",
            "my-urls"
        ];
        let shortCode;
        if (customAlias) {
            shortCode = customAlias;
        }
        else {
            shortCode = nanoid(7);
        }
        const existing = await prisma.url.findUnique({
            where: {
                shortCode
            }
        })
        if (reservedAlias.includes(customAlias)) {
            return res.status(400).json({
                message: "Reserved alias"
            })
        }
        if (existing) {
            return res.status(409).json({
                message: "Alias already taken"
            })
        }
        //409= resource conflict with same existing data
        const url = await prisma.url.create({
            data: {
                shortCode,
                longUrl,
                expiresAt,
                userId
            }
        })
        // The "6 characters" choice comes from the huge capacity of 62^6 ≈ 56.8 billion unique URLs while keeping links short and user-friendly.
        res.status(201).json({
            shortUrl: `http://localhost:3008/${url.shortCode}`
        })
    } catch (err) {
        res.status(500).json({
            error: err.message
        })
    }
}
//410= Resource used to exist but is no longer available.
exports.redirectUrl = async (req, res) => {
    try {
        const { shortCode } = req.params;
        const cacheurl = await redisClient.get(shortCode);
        if (cacheurl) {
            console.log("Cache hit")
            cachehitcounter.inc();
            const data = JSON.parse(cacheurl);
            if (data.expiresAt && new Date() > new Date(data.expiresAt)) {
                return res.status(410).json({
                    message: "Link expired"
                })
            }
            return res.redirect(data.longUrl);
        }
        console.log("cache miss")
        cachemisscounter.inc();
        const url = await prisma.url.findUnique({
            where: {
                shortCode
            }
        });
        if (!url) {
            return res.status(404).json({
                message: "Not found",
            })
        }
        await redisClient.set(
            shortCode,
            JSON.stringify({
                longUrl: url.longUrl,
                expiresAt: url.expiresAt
            })
        )
        // await prisma.url.update({
        //     where: {
        //         id: url.id
        //     },
        //     data: {
        //         clicks: {
        //             increment: 1
        //         }
        //     }
        // })
        produceClickEvents(shortCode,
        ).catch(console.error)
        if (url.expiresAt && new Date() > url.expiresAt) {
            return res.status(410).json({
                message: "Link expired"
            })
        }
        urlRedirectCounter.inc();
        return res.redirect(url.longUrl)
    } catch (err) {
        res.status(500).json({
            error: err.message
        })
    }
}
exports.getMyUrl = async (req, res) => {
    try {
        const userId = req.user.userId;
        const urls = await prisma.url.findMany({
            where: {
                userId
            },
            select: {
                shortCode: true,
                longUrl: true,
                clicks: true,
                createdAt: true
            }
        })
        return res.status(200).json(urls);
    } catch (err) {
        return res.status(500).json({
            error: err.message
        })
    }
}
exports.deleteUrl = async (req, res) => {
    try {
        const userId = req.user.userId;
        const { id } = req.params;
        const url = await prisma.url.findUnique({
            where: {
                id
            }
        })
        if (!url) {
            return res.status(404).json({
                message: "Url not found"
            })
        }
        if (userId !== url.userId) {
            return res.status(403).json({
                message: "Forbidden"
            })
        }
        const data = await prisma.url.delete({
            where: {
                id
            }
        })
        res.status(200).json({
            message: "Deleted successfully"
        });
    } catch (err) {
        return res.status(500).json({
            error: err.message
        })
    }
}












