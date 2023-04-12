
const express = require('express')
const app = express()
const port = 3000

//avvia con express la pagina ./src/index.html

app.use(express.static('src'))

app.listen(port, () => {

    console.log(`Scopa listening at http://localhost:${port}`)
    
    }
)
