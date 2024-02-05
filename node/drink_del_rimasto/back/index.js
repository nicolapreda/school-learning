const express = require("express");
const cors = require("cors");

const app = express();
app.use(express.json());
app.use(cors("*")); // Abilita CORS

//GET Customers
app.get("/random", async (req, res) => {
  try {
    fetch("https://www.thecocktaildb.com/api/json/v1/1/random.php")
      .then((response) => response.json())
      .then((data) => {
        console.log(data);
        res.status(200).json(data);
      })
      .catch((error) => {
        console.log(error);
        return [];
      });
  } catch (error) {
    console.error("Errore durante la lettura dei dati:", error);
    res.status(500).json({ error: "Errore interno del server" });
  }
});

app.get("/random10", async (req, res) => {

  async function fetchRandomCocktails() {
    let randomCocktails = {};
  
    for (let index = 0; index < 10; index++) {
      try {
        const response = await fetch("https://www.thecocktaildb.com/api/json/v1/1/random.php");
        const data = await response.json();
  
        console.log(data);
        randomCocktails[index] = data;
      } catch (error) {
        console.error("Errore durante la lettura dei dati:", error);
      }
    }
  
    return randomCocktails;
  }
  
  fetchRandomCocktails()
    .then((result) => {
      res.status(200).json(result);
    })
    .catch((error) => {
      res.status(500).json({ error: "Errore interno del server" });
    });
  

});


//Search by name
app.get("/search/:name", async (req, res) => {
  try {
    fetch(
      "https://www.thecocktaildb.com/api/json/v1/1/search.php?s=" +
        req.params.name
    )
      .then((response) => response.json())
      .then((data) => {
        console.log(data);
        res.status(200).json(data);
      })
      .catch((error) => {
        console.log(error);
        return [];
      });
  } catch (error) {
    console.error("Errore durante la lettura dei dati:", error);
    res.status(500).json({ error: "Errore interno del server" });
  }
});

//Return all drinks
app.get("/", async (req, res) => {
  try {
    const alphabet = 'abcdefghijklmnopqrstuvwxyz';
  
    const requests = alphabet.split('').map((letter) => {
      return fetch(`https://www.thecocktaildb.com/api/json/v1/1/search.php?f=${letter}`)
        .then((response) => response.json())
        .catch((error) => {
          console.log(`Errore nella richiesta per la lettera ${letter}:`, error);
          return [];
        });
    });
  
    Promise.all(requests)
      .then((results) => {
        const mergedData = {};
        results.forEach((data, index) => {
          mergedData[alphabet[index]] = data;
        });
  
        console.log(mergedData);
        res.status(200).json(mergedData);
      })
      .catch((error) => {
        console.error("Errore durante il recupero dei dati:", error);
        res.status(500).json({ error: "Errore interno del server" });
      });
  } catch (error) {
    console.error("Errore durante il recupero dei dati:", error);
    res.status(500).json({ error: "Errore interno del server" });
  }
  


});

app.listen(3000, () => {
  console.log(`Example app listening on port 3000`);
});
