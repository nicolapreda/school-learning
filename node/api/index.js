/*
CUSTOMERS

CustomerID, CompanyName, ContactName, ContactTitle, Address, City, Region, PostalCode, Country, Phone

*/


const express = require('express')
const cors = require('cors');

const yaml = require('yamljs')
const swaggerUi = require('swagger-ui-express');


const app = express()

app.use(express.json());
app.use(cors("*")); // Abilita CORS


let customers = require("./db.json");

app.get('/customers', async (req, res) => {
  if (customers.length === 0) {
    return res.sendStatus(204); // Nessun contenuto
  }
  res.status(200).json(customers);

})

app.get('/customers/:customerId', async (req, res) => {
  if (customers.length === 0) {
    return res.sendStatus(204); // Nessun contenuto
  }

  res.status(200).json(customers.params);

})


app.post('/customers',
  async (req, res) => {



    //CustomerId, CompanyName, ContactName, ContactTitle, 
    //Address, City, Region, PostalCode, Country, Phone

    const newCustomer = {
      customerId: req.body.id,
      companyName: req.body.companyName,
      contactTitle: req.body.contactTitle,
      address: req.body.address,
    }

    customers.push(newCustomer);
    res.status(201).json(newCustomer);
  }
);

app.delete('/customers/:customerId', )


app.listen(3000, () => {
  console.log(`Example app listening on port 3000`)
})

