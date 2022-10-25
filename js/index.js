var numero = 0;

function fai() {
    var altro = document.getElementById("altro");
    //cambia colore e mettine uno casuale
    altro.style.color = "rgb(" + parseInt(Math.random() * 255) + "," + parseInt(Math.random() * 255) + "," + parseInt(Math.random() * 255) + ")";
    numero = numero + 1
    altro = altro.innerHTML = numero;
}

function crea()
{
    var out = document.getElementById("output");
    out.innerHTML = "";
    var righe = input.righe.value;
    var colonne = input.colonne.value;
    for(var i = 0; i < righe; i++){
        var row = document.createElement("div");
        row.className = "row";

        for(var x = 0; x < colonne; x++){
            
            //aggiungi un titolo in out come append
            var titolo = document.createElement("div");
            titolo.className="col-sm";
            titolo.innerHTML = "<h1 class=''>prova</h1>";
            titolo.style.color = "rgb(" + parseInt(Math.random() * 255) + "," + parseInt(Math.random() * 255) + "," + parseInt(Math.random() * 255) + ")";
            row.appendChild(titolo)
        
        }
        out.appendChild(row);
    }
}

//crea in automatico tanti elementi righe per colonne allineati 
//nel modo corretto con un colore casuale