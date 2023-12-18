const express = require('express');
const path = require('path');
const axios = require('axios');

const app = express();

app.set('view engine', 'ejs');

app.use(express.static(path.join(__dirname, 'public')));

app.set('views', path.join(__dirname, 'views'));

app.get('/', async (req, res) => {
  try {
    const response = await axios.get('http://localhost:3000/customers'); // Sostituisci con il percorso dell'API

    console.log(response.data); // Controlla la struttura dei dati

    res.render('index', { title: 'Web App con EJS e Tailwind CSS', customers: response.data });
  } catch (error) {
    console.error('Errore durante la richiesta all\'API:', error);
    res.render('error', { error: 'Errore durante il recupero dei dati dai clienti' });
  }
});

app.listen(3001, () => {
  console.log(`Server in esecuzione sulla porta 3001`);
});
