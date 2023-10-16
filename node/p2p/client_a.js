const dgram = require("dgram");
const readlinePromise = require("readline-promise").default;
const readline = require('readline-sync');
const fs = require("fs");

const rl = readlinePromise.createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.setPrompt('( /exit per terminare )>')

const nomeSocket = "CLIENT-A";
const localIp = "127.0.0.1";
const localPort = 12306;

const remoteIp = '127.0.0.1';
const remotePort = 12305;

const client = dgram.createSocket("udp4");


//Gestione msg ricevuti dall'host
client.on('message', (msg, rinfo) => {
    const message = JSON.parse(msg.toString())
    const remoteAddress = rinfo.address;
    const remotePort = rinfo.port;

    console.log(`\n(Da ${remoteAddress}:${remotePort}) >>>>>>>>> ${message.text} :  ${message.content}`)

    rl.prompt();
});



const Main = async () => {
    await client.bind(localPort, localIp, () => {
        console.log(`\n${nomeSocket} in ascolto su ${client.address().address}:${client.address().port}\n`);

    })

    console.log("\nAvvio chat...");

    while(true) {
        let content;

        let input = await rl.questionAsync("( /exit per terminare, /file per inviare il contenuto di un txt )>")

        if(input.startsWith("/file")){
            
            input = input.replace("/file ", "");
            
            content =  fs.readFileSync(`./${input}`, "utf8");
            
        }
        
        if(input === "/exit")
            break;
    
    const message = JSON.stringify({
        text: input,
        content: content
    });

    client.send(message, remotePort, remoteIp, (err) => {
        if(err)
            console.err(`Errore durante l'invio del messaggio: ${err}`)
    });
    }
    

    rl.close();
    client.close();
    return;
};


Main()
    .then(() => {
        console.log("\nProgramma terminato");
    }).catch((err) => {
        console.error(`Errore: ${err}`)
    });


