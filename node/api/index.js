/*
CUSTOMERS

CustomerID, CompanyName, ContactName, ContactTitle, Address, City, Region, PostalCode, Country, Phone

*/


const express = require('express')
const cors = require('cors');

const yaml = require('yamljs')
const swaggerUi = require('swagger-ui-express');
const openApiValidator = require('express-openai-validator');


const app = express()

app.use(express.json());
app.use(cors("*")); // Abilita CORS

const apiSpec = yaml.load("./api_spec")
app.use("/swagger", swaggerUi.serve, swaggerUi.setup(apiSpec));

const valitor = openApiValidator.middleware({
  apiSpec: "api_specs.yaml",
  validateRequest: true,
  cali
})

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

    const newId = customers.reduce((acc, c) => (c.CompanyId > acc ? c.CompanyId : acc), 0) + 1;


    //CustomerId, CompanyName, ContactName, ContactTitle, 
    //Address, City, Region, PostalCode, Country, Phone

    const newCustomer = {
      customerId: newId,
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

