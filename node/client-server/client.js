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

let username = '';

const Main = async () => {
    username = await rl.questionAsync("Inserisci il tuo nome utente: ")
    client.send(username, serverPort, serverAddress);
    while(true) {
        const input = await rl.questionAsync("> ");
        const message = `${username}: ${input}`;
        client.send(message, serverPort, serverAddress);
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
    console.log(`>>>>>>>>>>>>>>>>> ${msg.toString()}`);
    process.stdout.write('> ');
});

process.on("SIGINT", () => {
    console.log("Chiusura del client")
    client.close();
    process.exit(0);
})