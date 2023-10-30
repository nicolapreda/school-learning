const dgram = require("dgram");

// Crea server UDP
const server = dgram.createSocket("udp4");

const translate = require('translate-google')




server.on('message', (msg, info) => {
    const data = JSON.parse(msg.toString())
    console.log(data)


    
    const result = translateText(data);
    console.log(result)
    const response = {
        risultato: result
    }
    
    //Inoltra il messaggio 
    server.send(JSON.stringify(response), info.port, info.address)
    console.log("inviato")

})

// Connessione avviata
server.on("listening", () => {
    const address = server.address();
    console.log(`Server UDP in ascolto su ${address.address}:${address.port}`);
})


const translateText = (data) => {
    
    const {text, lang1, lang2} = data;

    translate(text, {from: lang1, to: lang2}).then(res => {
        console.log(res);
        return res;
    }).catch(err => {
        console.error(err);
    })
    

}

//Inizio ad ascoltare sulla port 12345
server.bind(12345);