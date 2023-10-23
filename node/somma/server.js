const dgram = require("dgram");

// Crea server UDP
const server = dgram.createSocket("udp4");


server.on('message', (msg, info) => {
    const data = JSON.parse(msg.toString())
    console.log(data)


    /* 
    - caso 0:
    numero random
    - caso 1:
    somma
    - caso 2:
    sottrazione
    - caso 3:
    moltiplicazione
    - caso 4: 
    divisione
    

    */

    switch(msg.type){
        case 0:
            break;
        case 1:
            break;
        case 2:
    }
        
    
    const result = generateRandomNumber(data);
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


const generateRandomNumber = (data) => {
    
    const {num1, num2} = data;


    const min = Math.min(num1, num2);
    const max = Math.max(num1, num2);

    return Math.floor(Math.random() * (max - min + 1)) + min;


}

const somma = (data) => {
    const {num1, num2} = data;
    return num+num2;
};

const sottrazione = (data) => {
    const {num1, num2} = data;
    return num1-num2;

}

//Inizio ad ascoltare sulla port 12345
server.bind(12345);