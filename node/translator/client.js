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
    let tipo, text, lang1, lang2;

    while (true) {
            tipo = await rl.questionAsync("(0 = cerca/sostituisci, 1 = traduci)")
        switch(tipo){
            case 0:
                text = await rl.questionAsync("Inserisci il testo")

                break;
            case 1:
                lang1 = await rl.questionAsync("Inserisci la lingua di partenza")
                text = await rl.questionAsync("Inserisci il testo da tradurre")
                lang2 = await rl.questionAsync("Inserisci la lingua con cui tradurre ")
        
                message = JSON.stringify({
                    text: text,
                    lang1: lang1,
                    lang2: lang2
                });
        
                break;
        }


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

