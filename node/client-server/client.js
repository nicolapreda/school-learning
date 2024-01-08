const dgram = require("dgram");
const readlinePromise = require("readline-promise").default;
const fs = require("fs");
const { parse } = require("path");

const rl = readlinePromise.createInterface({
  input: process.stdin,
  output: process.stdout,
});

//Indirizzo o porta del server
const serverAddress = "127.0.0.1";
const serverPort = 12345;
const clientPort = 54321;

const client = dgram.createSocket("udp4");
client.bind(clientPort);

const Main = async () => {
  while (true) {
    try {
      const input = await rl.questionAsync(
        "Scegli il servizio(0 => Elenco occorrenze, 1 => Testo senza spazi)"
      );
      let response, text;

      switch (input) {
        //primo servizio
        case "0":
          text = await rl.questionAsync("Inserisci il testo\n");
          response = {
            service: parseInt(input),
            text: text,
          };

          break;
        //secondo servizio
        case "1":
          text = await rl.questionAsync(
            "Inserisci il percorso del file di testo\n"
          );
          aCapo = await rl.questionAsync(
            "Vuoi anche eliminare il ritorno a capo? (y,n)\n"
          );

          if (aCapo === "y") {
            aCapo = 1;
          } else if (aCapo === "n") {
            aCapo = 0;
          } else {
            aCapo = 0;
          }
          text = await fs.readFile(text, "utf8", (err, data) => {
            if (err) throw err;
            text = data;
            return text;
        });
          console.log(text);

          response = {
            service: parseInt(input),
            params: {
              aCapo: aCapo,
              text: text,
            },
          };
          console.log(response);

          break;
        default:
          break;
      }

      client.send(JSON.stringify(response), serverPort, serverAddress);
    } catch (error) {
      console.log(error);
    }
  }
};

// Avvio del client
Main()
  .then(() => {
    console.log("\nProgramma terminato");
  })
  .catch((err) => {
    console.error(`Errore: ${err}`);
  });

client.on("message", (msg) => {
  console.log(`Risposta del server: ${msg.toString()}\n`);
});
