const client=require("prom-client")

client.collectDefaultMetrics()

const urlRedirectCounter=new client.Counter({
    name:"url_redirect_total",
    help:"Total redirected URLs"
})

const httpcounter=new client.Counter({
    name:"http_request_total",
    help:"Total HTTP requests"
})
const cachemisscounter=new client.Counter({
    name:"cache_miss_total",
    help:"Cache Miss Total"
})
const cachehitcounter=new client.Counter({
    name:"cache_hit_total",
    help:"Cache Hit Total"
})
const kafkaproducedcounter=new client.Counter({
    name:"kafka_messages_produced_total",
    help:"Kafka messsges produced"
})

const kafkapconsumedcounter=new client.Counter({
    name:'kafka_messages_consumed_total',
    help:"Kafka messsges consumed"
})


module.exports={client,urlRedirectCounter,
    kafkapconsumedcounter,kafkaproducedcounter
    ,httpcounter,cachehitcounter,cachemisscounter
};