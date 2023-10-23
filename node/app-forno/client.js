const dgram = require("dgram");
const readlinePromise = require('readline-promise').default;


const rl = readlinePromise.createInterface({
    input: process.stdin,
    output: process.stdout,
});

const client = dgram.createSocket("udp4");

//Indirizzo o porta del server
const serverAddress = "127.0.0.1";
const serverPort = 12345;
