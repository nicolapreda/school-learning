var ricerca = "";
var pagina = 1;
var container = document.getElementById('container');


window.onload = function () {

  fetch('https://api.themoviedb.org/3/movie/popular?api_key=7dd3351fd7dcd7de4e6bcdd502b9a4e0&language=en-US&page=' + pagina)
    .then(response => response.json())
    .then(risposta => fai(risposta))
    .catch(err => console.error('Impossibile recuperare i film', err));

}


function search() {

  var input = document.getElementById("input").value;
  ricerca = input;
  container.innerHTML = "";

  fetch('https://api.themoviedb.org/3/search/movie?api_key=7dd3351fd7dcd7de4e6bcdd502b9a4e0&query=' + ricerca + '&page=' + pagina + "&include_adult=false&language=en-it")
    .then(response => response.json())
    .then(risposta => {
      if (risposta.results.length < 30) {
        pagina++;
          fetch('https://api.themoviedb.org/3/search/movie?api_key=7dd3351fd7dcd7de4e6bcdd502b9a4e0&query=' + ricerca + '&page=' + pagina + "&include_adult=false&language=en-it")
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

document.addEventListener('keydown', function (event) {
  if (event.keyCode == 27) {
    modalClose();
  }
});



  function fai(risposta) {
    
    pagina = 1;
  var b = 0;
  risposta.results.sort(function (a, b) {
    return b.vote_average - a.vote_average;
  });

  risposta.results.forEach(a => {
    if (b == 30)
      return;

    var locandina;

    if (a.backdrop_path != null)
      locandina = "https://image.tmdb.org/t/p/original" + risposta.results[b].poster_path;
    else
      locandina = "https://www.edizionicantagalli.com/wp-content/uploads/2020/01/Copertina-non-disponibile.jpg";

    if (risposta.results[b].original_title.length > 30)
      risposta.results[b].original_title = risposta.results[b].original_title.substring(0, 15) + "...";

    if (risposta.results[b].overview.includes("'"))
      risposta.results[b].overview = risposta.results[b].overview.replace(/'/g, " ");

    if (risposta.results[b].overview.includes('"'))
      risposta.results[b].overview = risposta.results[b].overview.replace(/"/g, " ");


    document.getElementById("container").innerHTML += `<div class=" py-6 flex flex-col justify-center sm:py-12">
  
        <div class="py-3 sm:max-w-xl sm:mx-auto">
          <div class="bg-white shadow-lg border-gray-100 max-h-80	 border sm:rounded-3xl p-8 flex space-x-8">
            <div class=" overflow-visible w-1/2">
                <img class="rounded-3xl shadow-lg" src="${locandina}" alt="${risposta.results[b].original_title}">
            </div>
            <div class="flex flex-col w-1/2 space-y-4">
              <div class="flex justify-between items-start">
                <h2 class="text-3xl font-bold">${risposta.results[b].original_title}</h2>
                <div class="bg-yellow-400 font-bold rounded-xl p-2">${risposta.results[b].vote_average}</div>
              </div>
              <div>
                <div class="text-sm text-gray-400">Film</div>
                <div class="text-lg text-gray-800">${risposta.results[b].release_date}</div>
              </div>
                <p class=" text-gray-400 max-h-40 overflow-y-hidden">${risposta.results[b].overview}</p>
              <a onclick="openModal('${risposta.results[b].original_title}', '${risposta.results[b].backdrop_path}','${locandina}', '${risposta.results[b].overview}', '${risposta.results[b].vote_average}', 'Azione, fantasy', '${risposta.results[b].id}');" class="px-4 py-2 bg-blue-200 hover:bg-blue-300 transition text-center cursor-pointer rounded-lg">Scopri di più</a>
            </div>
      
          </div>
        </div>
        
      </div>`

    b++;
  });
}



const modal = document.querySelector('.main-modal');
const closeButton = document.querySelectorAll('.modal-close');

const modalClose = () => {
  modal.classList.remove('fadeIn');
  modal.classList.add('fadeOut');
  setTimeout(() => {
    modal.style.display = 'none';
  }, 500);
}


const openModal = (title, image_path,locandina, overview, average, geners, id) => {
  modal.classList.remove('fadeOut');
  modal.classList.add('fadeIn');
  modal.style.display = 'flex';

  var copertina, extdb;

  if (image_path != "null")
    copertina = "https://image.tmdb.org/t/p/original" + image_path;
  else {
    copertina = "https://www.themoviedb.org/t/p/w1920_and_h800_multi_faces_filter(blur)/sLvS5mxJbjoh6tnzktXCYqZCfLl.jpg";
  }
  extdb = `https://www.themoviedb.org/movie/${id}`

  document.getElementById('modal-content').innerHTML = `
  <img class="shadow-lg" src="${copertina}" alt="${title}">
  <div class="px-6 py-6">
    <div class="flex justify-between items-center pb-3">
            <p class="text-2xl font-bold">${title}</p>
            <a onclick="modalClose();" class="cursor-pointer z-50">
              <svg class="fill-current text-black" xmlns="http://www.w3.org/2000/svg" width="18" height="18"
                viewBox="0 0 18 18">
                <path
                  d="M14.53 4.53l-1.06-1.06L9 7.94 4.53 3.47 3.47 4.53 7.94 9l-4.47 4.47 1.06 1.06L9 10.06l4.47 4.47 1.06-1.06L10.06 9z">
                </path>
              </svg>
            </a>
          </div>
          <div class="flex justify-between items-center pb-3">
            <p class="text-xl font-semibold">Genere: ${geners}</p>
            <div class="bg-yellow-400 font-bold rounded-xl p-2 block">${average}</div>

          </div>
          <div class="my-5">
            <p>${overview}</p>
          </div>

          <a href="${extdb}" target="_blank" class="px-4 py-2 bg-blue-200 hover:bg-blue-300 transition text-center cursor-pointer rounded-lg">Altre Informazioni</a>
          </div>`;
}

for (let i = 0; i < closeButton.length; i++) {

  const elements = closeButton[i];

  elements.onclick = (e) => modalClose();

  modal.style.display = 'none';

  window.onclick = function (event) {
    if (event.target == modal) modalClose();
  }
}

