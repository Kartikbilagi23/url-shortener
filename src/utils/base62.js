const chars="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

function encode(num) {
    let result="";
    while(num>0){
        result=chars[num%62]+result;
        num=Math.floor(num/62);
    }
    return result;
}


module.exports=encode;

// console.log(
// encode(25617283936262829763839201726))