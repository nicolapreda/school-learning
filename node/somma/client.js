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


let message = "";

const Main = async () => {
    let num1, num2;

    while (true) {
        num1 = await rl.questionAsync("Inserisci il primo numero ")
        num2 = await rl.questionAsync("Inserisci il secondo numero ")

        message = JSON.stringify({
            num1: num1,
            num2: num2
        });

        client.send(message, serverPort, serverAddress);
        console.log("Messaggio inviato!")
    }

}


// Avvio del client
Main()
    .then(() => {
        console.log("\nProgramma terminato");
    }).catch((err) => {
        console.error(`Errore: ${err}`)
    });

client.on("message", (msg) => {
    const response = JSON.parse(msg.toString())
    console.log(`\n>>>>>>>>>>>>>>>>> ${response.risultato}`);
    
});

process.on("SIGINT", () => {
    console.log("Chiusura del client")
    client.close();
    process.exit(0);
})

