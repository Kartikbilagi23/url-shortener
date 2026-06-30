const { Kafka } = require("kafkajs");
const prisma = require("../config/prisma");
const { kafkapconsumedcounter } = require("../config/metric");

const kafka = new Kafka({
    clientId: "analytics-consumer",
    brokers: ["kafka:9092"]
});

const consumer = kafka.consumer({
    groupId: "click-group"
});

async function startConsumer() {
    try {
        // Create topic if it doesn't exist
        const admin = kafka.admin();
        await admin.connect();
        await admin.createTopics({
            waitForLeaders: true,
            topics: [{
                topic: "url-clicks",
                numPartitions: 1,
                replicationFactor: 1
            }]
        });
        await admin.disconnect();

        console.log("Connecting consumer...");
        await consumer.connect();

        console.log("Subscribing...");
        await consumer.subscribe({
            topic: "url-clicks",
            fromBeginning: true
        });

        console.log("Running consumer...");
        await consumer.run({
            eachMessage: async ({ message }) => {
                const data = JSON.parse(message.value.toString());

                await prisma.url.update({
                    where: { shortCode: data.shortCode },
                    data: { clicks: { increment: 1 } }
                });

                console.log("Updated", data.shortCode);
                kafkapconsumedcounter.inc();
            }
        });

    } catch (err) {
        console.error("START CONSUMER ERROR");
        console.error(err);
        throw err;
    }
}

module.exports = { startConsumer };