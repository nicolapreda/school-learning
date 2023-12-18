const express = require('express')
const cors = require('cors');
const fs = require("fs")

const YAML = require('yamljs');
const swaggerUi = require('swagger-ui-express');


const app = express()

app.use(express.json());
app.use(cors("*")); // Abilita CORS


let customers = require("./db.json");

const swaggerDocument = YAML.load('./swagger.yaml'); // Assicurati di avere un file YAML con la descrizione delle API
app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerDocument));


//GET Customers
app.get('/customers', async (req, res) => {
  try {
    const rawData = fs.readFileSync('./db.json');
    const parsedData = JSON.parse(rawData);

    if (parsedData.length === 0) {
      return res.sendStatus(204); // Nessun contenuto
    }

    res.status(200).json(parsedData);
  } catch (error) {
    console.error('Errore durante la lettura dei dati:', error);
    res.status(500).json({ error: 'Errore interno del server' });
  }
});


//GET Customer
app.get('/customers/:customerId', async (req, res) => {
  const customerId = req.params.customerId;

  try {
    const rawData = fs.readFileSync('./db.json');
    const data = JSON.parse(rawData);

    const customersArray = data.customers;

    const customer = customersArray.find(cust => cust.customerId === customerId);

    if (!customer) {
      return res.status(404).json({ error: 'Cliente non trovato' });
    }

    res.status(200).json(customer);
  } catch (error) {
    console.error('Errore durante la lettura dei dati:', error);
    res.status(500).json({ error: 'Errore interno del server' });
  }
});


//POST Customer
app.post('/customers', async (req, res) => {
  const {
    customerId,
    companyName,
    contactName,
    contactTitle,
    address,
    city,
    postalCode,
    country,
    phone,
    region,
    fax
  } = req.body;

  const customerArray = customers.customers;

  const isIdUnique = customerArray.some(customer => customer.customerId === customerId);
  if (isIdUnique) {
    return res.status(400).json({ error: 'ID del cliente non univoco' });
  }

  const newCustomer = {
    customerId,
    companyName,
    contactName,
    contactTitle,
    address,
    city,
    postalCode,
    country,
    phone,
    region,
    fax
  };

  customerArray.push(newCustomer);

  fs.writeFile('./db.json', JSON.stringify(customers, null, 2), err => {
    if (err) {
      console.error('Errore durante il salvataggio dei dati:', err);
      return res.status(500).json({ error: 'Errore interno del server' });
    }
    res.status(201).json(newCustomer);
  });
});


//UPDATE Customer
app.put('/customers/:customerId', (req, res) => {
  const customerId = req.params.customerId;
  const customerArray = customers.customers;

  const customerIndex = customerArray.findIndex(customer => customer.customerId === customerId);

  if (customerIndex === -1) {
    return res.status(404).json({ error: 'Cliente non trovato' });
  }

  const {
    companyName,
    contactName,
    contactTitle,
    address,
    city,
    postalCode,
    country,
    phone,
    region,
    fax
  } = req.body;

  customerArray[customerIndex] = {
    ...customerArray[customerIndex],
    companyName,
    contactName,
    contactTitle,
    address,
    city,
    postalCode,
    country,
    phone,
    region,
    fax
  };

  fs.writeFile('./db.json', JSON.stringify(customers, null, 2), err => {
    if (err) {
      console.error('Errore durante il salvataggio dei dati:', err);
      return res.status(500).json({ error: 'Errore interno del server' });
    }
    res.status(200).json(customerArray[customerIndex]);
  });
});

//DELETE Customer
app.delete('/customers/:customerId', (req, res) => {
  const customerId = req.params.customerId;

  const customerArray = customers.customers;

  const index = customerArray.findIndex(customer => customer.customerId === customerId);

  if (index === -1) {
    return res.status(404).json({ error: 'Cliente non trovato' });
  }

  customerArray.splice(index, 1);

  fs.writeFile('./db.json', JSON.stringify(customers, null, 2), err => {
    if (err) {
      console.error('Errore durante il salvataggio dei dati:', err);
      return res.status(500).json({ error: 'Errore interno del server' });
    }
    res.status(200).json({ message: 'Cliente eliminato con successo' });
  });
});


app.listen(3000, () => {
  console.log(`Example app listening on port 3000`)
})

