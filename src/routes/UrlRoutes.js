const express=require("express")
const router=express.Router()
const {shortenUrl,redirectUrl, getMyUrl}=require("../controllers/urlController")
const authMiddleware=require("../middleware/authMiddleware")

router.post("/shorten",authMiddleware,shortenUrl)
router.get("/my-urls",authMiddleware,getMyUrl)
router.get("/:shortCode",redirectUrl)

module.exports=router;


