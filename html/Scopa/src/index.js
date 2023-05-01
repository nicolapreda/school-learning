
let content = document.getElementById('content');


function setGame() {

    content.innerHTML = `
    <input type="text" id="name" class="rounded-xl border-2 border-gray-300 p-4" placeholder="Nome">
    <div class="flex gap-4">
    <input type="checkbox" id="isVisible" class="rounded-xl border-2 border-gray-300">

        <p class="text-xl my-auto">Visibile</p>
    </div>

    <button id="create" class="rounded-xl bg-green-600 hover:bg-green-700 transition text-white p-4" onclick="getInputValue()">Crea</button>
    <button class="group h-12 px-6 border-2 border-gray-300 rounded-full transition duration-300 hover:border-green-700 focus:bg-blue-50 active:bg-blue-100" onclick="createMenu()">
        <div class="relative flex items-center space-x-4 justify-center">
            <a>
                <span class="block w-max font-semibold tracking-wide text-gray-700 text-sm transition duration-300 group-hover:text-green-700 sm:text-base">
                                                Indietro</span>
            </a>
        </div>
    </button>
    `

}


function getInputValue() {
    let name = document.getElementById('name').value;
    let isVisible = document.getElementById('isVisible').checked;
    //se true => 1
    //se false => 0
    isVisible = isVisible ? 1 : 0;
    createGame(name, isVisible);
}


function createGame(name, isVisible) {

    fetch(`https://classe5ID.altervista.org/games/partita/scopa${isVisible}_${name}`, {
        method: 'POST',

        headers: {
            'Content-type': 'application/json; charset=UTF-8',
            'Authorization': 'Basic ' + btoa('4ID:Grena')
        }
    })
        .then((response) => response.json())
        .then((json) => {
            console.log(json);
            window.location.href = "game.html?id=" + json.data.id;
        });


}


function joinLobby() {
    fetch('https://classe5ID.altervista.org/games/partita', {
        method: 'GET',

        headers: {
            'Content-type': 'application/json; charset=UTF-8',
            'Authorization': 'Basic ' + btoa('4ID:Grena')
        }
    })
        .then((res) => res.json())
        .then((json) => {
            console.log(json);
            content.innerHTML = `<input type="text" id="name" class="rounded-xl border-2 border-gray-300 p-4" placeholder="Nome">`;

            for (let i = 0; i < json.data.length; i++) {
                // 0 => non visibile
                // 1 => visibile
                if (json.data[i].PLAYER1.startsWith("scopa1_") && json.data[i].PLAYER2 == null) {
                    json.data[i].PLAYER1 = json.data[i].PLAYER1.replace("scopa1_", "");
                    json.data[i].PLAYER1 = json.data[i].PLAYER1.replace(/%20/g, " ");
                    content.innerHTML += `
                    <div class="grid grid-cols-2 gap-4">
                    <p class="text-xl my-auto">${json.data[i].PLAYER1}</p>
                    <button id="join" class="rounded-xl bg-green-600 hover:bg-green-700 transition text-white p-4" onclick="joinGame(${json.data[i].ID})">Unisciti</button>
                </div>
                    `
                }
            }

            //se non ci sono partite disponibili
            if (content.innerHTML == '<input type="text" id="name" class="rounded-xl border-2 border-gray-300 p-4" placeholder="Nome">') {
                content.innerHTML += `
                <p class="text-xl text-center">Non ci sono partite disponibili</p>
                `
            }

            //inserisci un input per inserire manualmente l'id
            content.innerHTML += `
            <div class="border-b-2 border-gray-300 my-4"></div>
                <div class="grid grid-cols-2 gap-4">

                <input type="text" id="id" class="rounded-xl border-2 border-gray-300 p-4" placeholder="ID">
                <button id="join" class="rounded-xl bg-green-600 hover:bg-green-700 transition text-white p-4" onclick="joinGame(document.getElementById('id').value)">Unisciti</button>
            </div>
                `


            content.innerHTML += `
    <button class="group h-12 px-6 border-2 border-gray-300 rounded-full transition duration-300 hover:border-green-700 focus:bg-blue-50 active:bg-blue-100" onclick="createMenu()">
        <div class="relative flex items-center space-x-4 justify-center">
            <a>
                <span class="block w-max font-semibold tracking-wide text-gray-700 text-sm transition duration-300 group-hover:text-green-700 sm:text-base">
                                                Indietro</span>
            </a>
        </div>
    </button>
    `
        });


}


function joinGame(id) {
    idString = id.toString();
    let name = document.getElementById('name').value;


    fetch(`https://classe5ID.altervista.org/games/join/${idString}/${name}`, {
        method: 'POST',
        headers: {
            'Content-type': 'application/json; charset=UTF-8',
            'Authorization': 'Basic ' + btoa('4ID:Grena')
        }
    })

        //in caso di errore
        
        //window.location.href = "game.html?id=" + json.data.id;
        /*.catch((error) => {
            console.error(error);
            alert("Errore: " + error);
        }
    );*/




}


function createMenu() {
    content.innerHTML = '';
    //crea il menu
    content.innerHTML = `

    <button class="group h-12 px-6 border-2 border-gray-300 rounded-full transition duration-300 
    hover:border-green-700 focus:bg-blue-50 active:bg-blue-100" onclick="setGame()">
                                
                               <div class="relative flex items-center space-x-4 justify-center">
                                   <a>
                                       <span
                                           class="block w-max font-semibold tracking-wide text-gray-700 text-sm transition duration-300 group-hover:text-green-700 sm:text-base">
                                           Crea partita</span>
                                   </a>
                               </div>
                           </button>
                           <button class="group h-12 px-6 border-2 border-gray-300 rounded-full transition duration-300 
                           hover:border-green-700 focus:bg-blue-50 active:bg-blue-100" onclick="joinLobby()">
                               <div class="relative flex items-center space-x-4 justify-center">

                                   <a>
                                       <span
                                           class="block w-max font-semibold  text-gray-700 text-sm transition duration-300 group-hover:text-green-700 sm:text-base">Cerca Partita</span>
                                   </a>
                               </div>
                           </button>
                           <button class="group h-12 px-6 border-2 border-gray-300 rounded-full transition duration-300 
                           hover:border-green-700 focus:bg-blue-50 active:bg-blue-100" onclick="settings()">
                               <div class="relative flex items-center space-x-4 justify-center">

                                   <a
                                       <span
                                           class="block w-max font-semibold tracking-wide text-gray-700 text-sm transition duration-300 group-hover:text-green-700 sm:text-base">Impostazioni</span>
                                   </a>
                               </div>
                           </button>
                           
    `
}


function settings() {
    content.innerHTML = '';
    //crea impostazioni
    content.innerHTML = `
    <button class="group h-12 px-6 border-2 border-gray-300 rounded-full transition duration-300 hover:border-green-700 focus:bg-blue-50 active:bg-blue-100" onclick="createMenu()">
        <div class="relative flex items-center space-x-4 justify-center">
            <a>
                <span class="block w-max font-semibold tracking-wide text-gray-700 text-sm transition duration-300 group-hover:text-green-700 sm:text-base">
                                                Indietro</span>
            </a>
        </div>
    </button>
    `
}



window.addEventListener('load', function () {
    createMenu();
})

