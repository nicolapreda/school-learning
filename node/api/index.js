
const express = require('express')
const app = express()
const port = 3000

let categories = require("./db.json");

app.get('/categories', async (req, res) => {
        if(categories.length === 0){
            return res.sendStatus(204); // Nessun contenuto
        }
        res.status(200).json(categories);

})

app.post('/categories', function (req, res) {
    res.send('POST request to the homepage');
  });
  

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})

