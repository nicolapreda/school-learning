var ricerca = "";
var pagina = 1;
var container = document.getElementById('container');

var sorting = 0;

window.onload = function () {

  fetch('https://api.themoviedb.org/3/movie/popular?api_key=7dd3351fd7dcd7de4e6bcdd502b9a4e0&language=it-IT&page=' + pagina)
    .then(response => response.json())
    .then(risposta => {
      console.log(risposta);
      fai(risposta);
    })
    .catch(err => console.error('Impossibile recuperare i film', err));

}


function search() {

  var startDate = document.getElementById("startDate").value;
  var endDate = document.getElementById("endDate").value;

  if (startDate == "") {
    startDate = "1900-01-01";
  }
  if (endDate == "") {
    endDate = "2100-12-31";
  }
  if (startDate > endDate) {
    var temp = startDate;
    startDate = endDate;
    endDate = temp;
  }
  if (startDate == endDate) {
    startDate = "1900-01-01";
    endDate = "2100-12-31";
  }


  var input = document.getElementById("input").value;
  if(input == "" || input == " "){
    alert("Prima scrivi il film da cercare!")
    return;
  }
  ricerca = input;
  container.innerHTML = "";


  


  fetch('https://api.themoviedb.org/3/search/movie?api_key=7dd3351fd7dcd7de4e6bcdd502b9a4e0&query=' + ricerca + '&page=' + pagina + "&include_adult=false&language=it-it" + '&primary_release_date.gte=' + startDate + '&primary_release_date.lte=' + endDate)
    .then(response => response.json())
    .then(risposta => {
      if (risposta.results.length < 30) {
        pagina++;
        fetch('https://api.themoviedb.org/3/search/movie?api_key=7dd3351fd7dcd7de4e6bcdd502b9a4e0&query=' + ricerca + '&page=' + pagina + "&include_adult=false&language=it-it" + '&primary_release_date.gte=' + startDate + '&primary_release_date.lte=' + endDate)
          .then(response => response.json())
          .then(risposta2 => {
            risposta.results = risposta.results.concat(risposta2.results);
            console.log(risposta);
            fai(risposta);
          })
      }
      else {
        fai(risposta)
      }
    })

}


document.getElementById("input").addEventListener("keyup", function (event) {
  if (event.keyCode === 13) {
    document.getElementById("search").click();
  }
});



function fai(risposta) {

  pagina = 1;
  var b = 0;

  switch (sorting) {
    case 0:
      break;
    case 1:
      //ordina per popolarità crescente
      risposta.results.sort(function (a, b) {
        return a.popularity - b.popularity;
      });
      break;
    case 2:
      //ordina per popolarità decrescente

      risposta.results.sort(function (a, b) {
        return b.popularity - a.popularity;
      });
      break;
    case 3:
      //ordina per voto crescente


      risposta.results.sort(function (a, b) {
        return a.vote_average - b.vote_average;
      });
      break;
    case 4:
      //ordina per voto decrescente


      risposta.results.sort(function (a, b) {
        return b.vote_average - a.vote_average;
      });

      break;
    case 5:
      //ordina per data di rilascio crescente
      risposta.results.sort(function (a, b) {
        return new Date(a.release_date) - new Date(b.release_date);
      });
      break;
    case 6:
      //ordina per data di rilascio decrescente
      risposta.results.sort(function (a, b) {
        return new Date(b.release_date) - new Date(a.release_date);
      });
      break;
    case 7:
      //ordina per titolo crescente
      risposta.results.sort(function (a, b) {
        var x = a.title.toLowerCase();
        var y = b.title.toLowerCase();
        if (x < y) { return -1; }
        if (x > y) { return 1; }
        return 0;
      }
      );
      break;
    case 8:
      //ordina per titolo decrescente
      risposta.results.sort(function (a, b) {
        var x = a.title.toLowerCase();
        var y = b.title.toLowerCase();
        if (x > y) { return -1; }
        if (x < y) { return 1; }
        return 0;
      }
      );
      break;

  }




  risposta.results.forEach(a => {
    if (b == 30)
      return;

    var locandina;

    if (a.backdrop_path != null)
      locandina = "https://image.tmdb.org/t/p/original" + risposta.results[b].poster_path;
    else
      locandina = "https://www.edizionicantagalli.com/wp-content/uploads/2020/01/Copertina-non-disponibile.jpg";

    if (risposta.results[b].original_title.length > 30)
      risposta.results[b].original_title = risposta.results[b].title.substring(0, 15) + "...";

    if (risposta.results[b].overview.includes("'"))
      risposta.results[b].overview = risposta.results[b].overview.replace(/'/g, " ");

    if (risposta.results[b].overview.includes('"'))
      risposta.results[b].overview = risposta.results[b].overview.replace(/"/g, " ");


    document.getElementById("container").innerHTML += `<div class="mb-12 py-6 flex flex-col justify-center sm:py-12">
  
        <div class="py-3 sm:max-w-xl sm:mx-auto">
          <div class="bg-white shadow-lg border-gray-100 max-h-80	 border sm:rounded-3xl p-8 flex space-x-8">
            <div class=" overflow-visible w-1/2">
                <img class="rounded-3xl shadow-lg" src="${locandina}" alt="${risposta.results[b].title}">
            </div>
            <div class="flex flex-col w-1/2 space-y-4">
              <div class="flex justify-between items-start">
                <h2 class="text-3xl font-bold">${risposta.results[b].title}</h2>
                <div class="bg-yellow-400 font-bold rounded-xl p-2">${risposta.results[b].vote_average}</div>
              </div>
              <div>
                <div class="text-sm text-gray-400">Film</div>
                <div class="text-lg text-gray-800">${risposta.results[b].release_date}</div>
              </div>
              <a onclick='setLocalID(${risposta.results[b].id}, "${risposta.results[b].original_language}", "${risposta.results[b].original_title}", "${risposta.results[b].overview}", "${risposta.results[b].backdrop_path}", "${risposta.results[b].poster_path}", "${risposta.results[b].release_date}", ${risposta.results[b].vote_average}, ${risposta.results[b].vote_count}, ${risposta.results[b].popularity})' class="px-4 py-2 bg-blue-200 hover:bg-blue-300 transition text-center cursor-pointer rounded-lg">Scopri di più</a>
            </div>
      
          </div>
        </div>
        
      </div>`

    b++;
  });
}


function setLocalID(id, original_language, original_title, overview, backdrop_path, poster_path, release_date, vote_average, vote_count, popularity) {
  localStorage.setItem('id', id);
  localStorage.setItem('original_language', original_language);
  localStorage.setItem('original_title', original_title);
  localStorage.setItem('overview', overview);
  localStorage.setItem('backdrop_path', backdrop_path);
  localStorage.setItem('poster_path', poster_path);
  localStorage.setItem('release_date', release_date);
  localStorage.setItem('vote_average', vote_average);
  localStorage.setItem('vote_count', vote_count);
  localStorage.setItem('popularity', popularity);

  window.location.href = "details.html";
}



function setSorting(sortingType) {
  switch (sortingType) {
    case 0:
      //prendi il valore di sorting dal local storage
      document.getElementById(sorting).classList.remove("bg-blue-400");
      sorting = 0;
      document.getElementById(sorting).classList.add("bg-blue-400");


      break;
    case 1:
      document.getElementById(sorting).classList.remove("bg-blue-400");

      sorting = 1;
      document.getElementById(sorting).classList.add("bg-blue-400");

      break;
    case 2:
      document.getElementById(sorting).classList.remove("bg-blue-400");

      sorting = 2;
      document.getElementById(sorting).classList.add("bg-blue-400");

      break;
    case 3:
      document.getElementById(sorting).classList.remove("bg-blue-400");

      sorting = 3;
      document.getElementById(sorting).classList.add("bg-blue-400");

      break;
    case 4:
      document.getElementById(sorting).classList.remove("bg-blue-400");

      sorting = 4;
      document.getElementById(sorting).classList.add("bg-blue-400");

      break;
    case 5:
      document.getElementById(sorting).classList.remove("bg-blue-400");

      sorting = 5;
      document.getElementById(sorting).classList.add("bg-blue-400");

      break;
    case 6:
      document.getElementById(sorting).classList.remove("bg-blue-400");

      sorting = 6;
      document.getElementById(sorting).classList.add("bg-blue-400");

      break;
    case 7:
      document.getElementById(sorting).classList.remove("bg-blue-400");

      sorting = 7;
      document.getElementById(sorting).classList.add("bg-blue-400");

      break;
    case 8:
      document.getElementById(sorting).classList.remove("bg-blue-400");

      sorting = 8;
      document.getElementById(sorting).classList.add("bg-blue-400");

      break;

  }

  var dropdown = document.getElementById("dropdown1");
  dropdown.className = "z-10 hidden bg-white divide-y divide-gray-100 rounded-lg shadow w-44 dark:bg-gray-700";
}