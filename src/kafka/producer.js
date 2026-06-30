const {Kafka}=require("kafkajs");
const { kafkaproducedcounter } = require("../config/metric");

const kafka=new Kafka({
    clientId:"url-shortener",
    brokers:["kafka:9092"]
})

const producer=kafka.producer()

async function connectProducer() {
    await producer.connect();
}

async function produceClickEvents(shortCode) {
    await producer.send({
        topic:"url-clicks",
        messages:[
        {
            value:JSON.stringify({
                shortCode,
                timestamp:new Date()
            })
        }
        ]
    })
    console.log(`Publishing click event for ${shortCode}`)
    kafkaproducedcounter.inc();
}

module.exports={produceClickEvents,connectProducer};