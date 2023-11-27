const dgram = require("dgram");

// Crea server UDP
const server = dgram.createSocket("udp4");

const translatte = require('translatte');




server.on('message', (msg, info) => {
    const data = JSON.parse(msg.toString())
    console.log(data)


    
    let result;
    
    if(data.type == 0){
        cercaSostituisci(data);
    }
    else if(data.type == 1){
        translateText(data);
    }

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
    const {type, text, lang1, lang2} = data;

    translatte(text, {to: lang2}).then(res => {
        console.log(res.text);
        return res.text;
    }).catch(err => {
        console.error(err);
        return err;
    });

}

const cercaSostituisci = (data) => {
    const {type, text, lang1, lang2} = data
    return text.replaceAll(lang1, lang2);

}

//Inizio ad ascoltare sulla port 12345
server.bind(12345);