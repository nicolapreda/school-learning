const dgram = require("dgram");

// Crea server UDP
const server = dgram.createSocket("udp4");

const clients = [];

server.on('message', (msg, info) => {
    const message = msg.toString();
    console.log(`Messaggio ricevuto dal client ${info.address}:${info.port}: ${message}`);

    // Aggiunge il client alla lista se non è già presente
    if(!clients.some(client => client.address === info.address && client.port === info.port)) {
        clients.push(info);
    }

    //Inoltra il messaggio a tutti i client tranne a chi lo ha inviato
    clients.forEach(clientInfo => {
        if(clientInfo.port !== info.port || clientInfo.address !== info.address){
            server.send(msg, clientInfo.port, clientInfo.address)
        }
    })
})

// Connessione avviata
server.on("listening", () => {
    const address = server.address();
    console.log(`Server UDP in ascolto su ${address.address}:${address.port}`);
})

//Inizio ad ascoltare sulla port 12345
server.bind(12345);