const prisma=require("../config/prisma")
const bcrypt=require("bcrypt")
const jwt=require("jsonwebtoken")

const register=async (req,res) => {
    try {
        const {username,email,password}=req.body;
        const existing=await prisma.user.findUnique({
            where:{
                email,
            }
        })
        if(existing){
            return res.status(400).json({
                message:"User already exists"
            })
        }
        const hashed=await bcrypt.hash(password,10);
        const user=await prisma.user.create({
            data:{
                username,
                email,
                password:hashed
            }
        })
        res.status(201).json({
            message:"User created",
            id:user.id
        })

    } catch (err) {
        res.status(500).json({
            error:err.message
        })
    }
}

const login=async (req,res) => {
try {
    const {email,password}=req.body;
    if(!email||!password){
        return res.status(400).json({
            error:"Please provide valid credentials"
        })
    }
    const user=await prisma.user.findUnique({
        where:{
            email
        }
    })
    if(!user){
        return res.status(404).json({message:"User not found"})
    }
    const ismatch=bcrypt.compare(
        password,user.password
    )
    if(!ismatch){
            return res.status(401).json({
                message:"Invalid credentials"
            });
    }
    const token=jwt.sign({
        userId:user.id,
        email:user.email
    },
    process.env.JWT_SECRET,
    {
        expiresIn:'7d'
    });

    res.status(200).json({
        message:"Login successful, You may continue",
        token
    })
} catch (err) {
    return res.status(500).json({
        error:err.message
    })
}
}

module.exports={register,login};
