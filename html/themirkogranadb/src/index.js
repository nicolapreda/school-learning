var ricerca = "";
var page = 1;
var container = document.getElementById('container');

var sorting = 0;

window.onload = function () {

  fetch('https://api.themoviedb.org/3/movie/popular?api_key=7dd3351fd7dcd7de4e6bcdd502b9a4e0&language=it-IT&page=' + page)
    .then(response => response.json())
    .then(result => {
      console.log(result);
      insert(result);
    })
    .catch(err => console.error('Impossibile recuperare i film', err));

}


function search() {

  var input = document.getElementById("input").value;
  if (input == "" || input == " ") {
    alert("Prima scrivi il film da cercare!")
    return;
  }
  ricerca = input;
  container.innerHTML = "";


  fetch('https://api.themoviedb.org/3/search/movie?api_key=7dd3351fd7dcd7de4e6bcdd502b9a4e0&query=' + ricerca + '&page=' + page + "&include_adult=false&language=it-IT")
    .then(response => response.json())
    .then(result => {
      if (result.results.length < 30) {
        page++;
        fetch('https://api.themoviedb.org/3/search/movie?api_key=7dd3351fd7dcd7de4e6bcdd502b9a4e0&query=' + ricerca + '&page=' + page + "&include_adult=false&language=it-IT")
          .then(response => response.json())
          .then(result2 => {
            result.results = result.results.concat(result2.results);
            console.log(result);
            insert(result);
          })
      }
      else {
        insert(result)
      }
    })
}


document.getElementById("input").addEventListener("keyup", function (event) {
  if (event.keyCode === 13) {
    document.getElementById("search").click();
  }
});



function insert(result) {

  page = 1;
  var b = 0;

  switch (sorting) {
    case 0:
      break;
    case 1:
      //ordina per popolarità crescente
      result.results.sort(function (a, b) {
        return a.popularity - b.popularity;
      });
      break;
    case 2:
      //ordina per popolarità decrescente

      result.results.sort(function (a, b) {
        return b.popularity - a.popularity;
      });
      break;
    case 3:
      //ordina per voto crescente


      result.results.sort(function (a, b) {
        return a.vote_average - b.vote_average;
      });
      break;
    case 4:
      //ordina per voto decrescente
      result.results.sort(function (a, b) {
        return b.vote_average - a.vote_average;
      });

      break;
    case 5:
      //ordina per data di rilascio crescente
      result.results.sort(function (a, b) {
        return new Date(a.release_date) - new Date(b.release_date);
      });
      break;
    case 6:
      //ordina per data di rilascio decrescente
      result.results.sort(function (a, b) {
        return new Date(b.release_date) - new Date(a.release_date);
      });
      break;
    case 7:
      //ordina per titolo crescente
      result.results.sort(function (a, b) {
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
      result.results.sort(function (a, b) {
        var x = a.title.toLowerCase();
        var y = b.title.toLowerCase();
        if (x > y) { return -1; }
        if (x < y) { return 1; }
        return 0;
      }
      );
      break;

  }




  result.results.forEach(a => {
    if (b == 30)
      return;

    var locandina;

    if (a.backdrop_path != null)
      locandina = "https://image.tmdb.org/t/p/original" + result.results[b].poster_path;
    else
      locandina = "https://www.edizionicantagalli.com/wp-content/uploads/2020/01/Copertina-non-disponibile.jpg";

    if (result.results[b].title.length > 30)
      result.results[b].title = result.results[b].title.substring(0, 30) + "...";

    if (result.results[b].overview.includes("'"))
      result.results[b].overview = result.results[b].overview.replace(/'/g, " ");

    if (result.results[b].overview.includes('"'))
      result.results[b].overview = result.results[b].overview.replace(/"/g, " ");

    var date = new Date(result.results[b].release_date);
    var options = { year: 'numeric', month: 'long', day: 'numeric' };
    release_date = date.toLocaleDateString('it-IT', options);

    var vote = Math.round(result.results[b].vote_average * 10) / 10;


    document.getElementById("container").innerHTML += `<div class="mb-12 py-6 flex flex-col justify-center sm:py-12">
  
        <div class="py-3 sm:max-w-xl sm:mx-auto">
          <div class="bg-white shadow-lg border-gray-100 max-h-80	 border sm:rounded-3xl p-8 flex space-x-8">
            <div class=" overflow-visible w-1/2">
                <img class="rounded-3xl shadow-lg" src="${locandina}" alt="${result.results[b].title}">
            </div>
            <div class="flex flex-col w-1/2 space-y-4">
              <div class="flex justify-between items-start">
                <h2 class="text-3xl font-bold">${result.results[b].title}</h2>
                <div class="bg-yellow-400 font-bold rounded-xl p-2">${vote}</div>
              </div>
              <div>
                <div class="text-sm text-gray-400">Film</div>
                <div class="text-lg text-gray-800">${release_date}</div>
              </div>
              <a onclick='getDetails(${result.results[b].id})' class="px-4 py-2 bg-blue-200 hover:bg-blue-300 transition text-center cursor-pointer rounded-lg">Scopri di più</a>
            </div>
      
          </div>
        </div>
        
      </div>`

    b++;
  });
}


function getDetails(id) {
  localStorage.setItem('id', id);
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