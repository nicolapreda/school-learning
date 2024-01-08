
const dgram = require("dgram");

// Crea server UDP
const server = dgram.createSocket("udp4");

server.on("message", (req, reqInfo) => {
    const portaMittente = reqInfo.port || 0;
    const indirizzoMittente = reqInfo.address || "";

  try {
    // (1) mittente richiesta

    if (portaMittente !== 54321 || indirizzoMittente !== "127.0.0.1") {
      console.log("client non autorizzato");
      return;
    }

    //(2) protocollo richiesta
/*
    if (!req.service || typeof req.service !== "number") {
        throw new Error("Richiesta non valida");
      }
      if (!req.params.text || typeof req.text !== "string") {
        throw new Error("Testo non valido");
      }
  */
    const data = JSON.parse(req.toString());
    console.log(data);



    //(3) elaborazione risposta

    let resultData = null;
    let resultMex = null;

    
    switch(data.service){
        case 0:
            resultData = contaOccorrenze(data);
            resultMex = "contaOccorrenze";
            break;
        case 1:
            resultMex = "eliminaSpazi";
            resultData = eliminaSpazi(data);
            break;

    }

    //(4) risposta
    const response = {
      status: "ok",
      resultMex: resultMex,
      risultato: resultData,
    };


    const jsonRisposta = JSON.stringify(response, null, 2);
    server.send(jsonRisposta, portaMittente, indirizzoMittente);
  } catch (error) {
    const response = {
      status: "error",
      statusMex: error.message,
    };

    const jsonRisposta = JSON.stringify(response, null, 2);
    server.send(jsonRisposta, portaMittente, indirizzoMittente);
  }
});



const contaOccorrenze = (data) => {
    const {service, text} = data;
    var occorrenze = {};

    // for per ogni carattere nel testo
    for (var i = 0; i < text.length; i++) {
        var carattere = text.charAt(i);

        // Se carattere già presente, incrementa contatore
        if (occorrenze[carattere]) {
            occorrenze[carattere]++;
        } else {
            // sennò aggiungi a contatore iniziale 1
            occorrenze[carattere] = 1;
        }
    }
    return occorrenze;
};

const eliminaSpazi = (data) => {

    console.log(data.params.text, parseInt(data.params.aCapo));
    //Rimuovo le sequenze di spazi di lunghezza maggiore di 1
    let stringaDef = text.replace(/\s{2,}/g, " ");

    //controllo se l'utente vuole anche rimuovere gli "a capo"
    if(aCapo == 1){
        stringaDef = stringaDef.replace("\n", "");
    }

    return stringaDef;
}


// Connessione avviata
server.on("listening", () => {
  const address = server.address();
  console.log(`Server UDP in ascolto su ${address.address}:${address.port}`);
});



//Inizio ad ascoltare sulla port 12345
server.bind(12345);
