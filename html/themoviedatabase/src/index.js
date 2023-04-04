var ricerca = "rambo";
var pagina = 2;


fetch('https://api.themoviedb.org/3/search/movie?api_key=7dd3351fd7dcd7de4e6bcdd502b9a4e0&query=' + ricerca + '&page=' + pagina + "&include_adult=false&language=en-it")
    .then(response => response.json())
    .then(risposta => fai(risposta))
    .catch(err => console.log('Request Failed', err)); // gestisci gli errori

var container = document.getElementById('container');

function fai(risposta) {
    var b = 0;
    risposta.results.forEach(a => {
        var immagine;

        if(a.backdrop_path != null)
            immagine = "https://image.tmdb.org/t/p/original" + risposta.results[b].poster_path;
        else
            immagine = "https://www.edizionicantagalli.com/wp-content/uploads/2020/01/Copertina-non-disponibile.jpg";

        document.getElementById("container").innerHTML += `<div class=" py-6 flex flex-col justify-center sm:py-12">
  
        <div class="py-3 sm:max-w-xl sm:mx-auto">
          <div class="bg-white shadow-lg border-gray-100 max-h-80	 border sm:rounded-3xl p-8 flex space-x-8">
            <div class=" overflow-visible w-1/2">
                <img class="rounded-3xl shadow-lg" src="${immagine}" alt="${risposta.results[b].original_title}">
            </div>
            <div class="flex flex-col w-1/2 space-y-4">
              <div class="flex justify-between items-start">
                <h2 class="text-3xl font-bold">${risposta.results[b].original_title}</h2>
                <div class="bg-yellow-400 font-bold rounded-xl p-2">${risposta.results[b].vote_average}</div>
              </div>
              <div>
                <div class="text-sm text-gray-400">Film</div>
                <div class="text-lg text-gray-800">2019</div>
              </div>
                <p class=" text-gray-400 max-h-40 overflow-y-hidden">${risposta.results[b].overview}</p>
              <a href="./details.html" class="px-4 py-2 bg-slate-400 text-center text-2xl font-bold rounded-lg">Scopri di più</a>
            </div>
      
          </div>
        </div>
        
      </div>`

        b++;
    });
}