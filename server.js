const env = require("dotenv")
env.config()
const express = require("express")
const urlRoutes = require("./src/routes/UrlRoutes")
const prisma = require("./src/config/prisma")
const authRoute = require("./src/routes/AuthRoute")
const { connectProducer } = require("./src/kafka/producer")
const { startConsumer } = require("./src/kafka/consumer")
const  {client}  = require("./src/config/metric")
const app = express()


app.use(express.json())

app.get("/metrics",async (req,res) => {
    res.set("Content-type",client.register.contentType)
    res.end(await client.register.metrics())
})

app.use("/", urlRoutes)
app.use("/auth", authRoute);

app.use((req,res,next)=>{
    client.httpcounter.inc();
    next();
})



const PORT = process.env.PORT || 3008;

async function testDB() {

    await prisma.$connect();

    console.log("Database connected");

}
async function kafka() {
    await connectProducer();
    console.log("Kafka connected");
    await startConsumer();
    console.log("Consumer connected")
}

(async () => {
    await testDB();
    try {
        await kafka();
    } catch (e) {
        console.error("Kafka failed,shutting down",e)
        process.exit(1);
    }
    app.listen(PORT, () => {
        console.log("Server running..")
    })
})();

