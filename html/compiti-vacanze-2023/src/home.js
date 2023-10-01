// Verifica se l'utente è loggato
const loggedInUser = localStorage.getItem("loggedInUser");
if (!loggedInUser) {
  // Se l'utente non è loggato, reindirizza alla pagina di login
  window.location.href = "index.html";
}

// Aggiungi l'evento click per il pulsante di logout
document.getElementById("logoutButton").addEventListener("click", function () {
  // Rimuovi l'utente dal localStorage e reindirizza alla pagina di login
  localStorage.removeItem("loggedInUser");
  window.location.href = "index.html";
});


  
  
function loadFamilyData() {
  fetch("famiglie.json")
    .then((response) => response.json())
    .then((data) => {
        window.familyData = data;
      const families = {};

      // Raggruppa le persone per famiglia
      data.forEach((person) => {
        if (!families[person.id_famiglia]) {
          families[person.id_famiglia] = [];
        }
        families[person.id_famiglia].push(person);
      });

      // Creazione delle Cards e del Carousel
      const carouselInner = document.querySelector(".carousel-inner");
      let isFirstFamily = true;

      for (const familyId in families) {
        const family = families[familyId];
        const familyCard = createFamilyCard(family);

        if (isFirstFamily) {
          familyCard.classList.add("active");
          isFirstFamily = false;
        }

        carouselInner.appendChild(familyCard);
      }
    })
    .catch((error) => {
      console.error("Errore nel caricamento dei dati delle famiglie:", error);
    });
}

// Funzione per creare una Card di famiglia con le persone
function createFamilyCard(family) {
  const familyCard = document.createElement("div");
  familyCard.classList.add("carousel-item");

  const cardBody = document.createElement("div");
  cardBody.classList.add("card-body");

  family.forEach((person) => {
    const personInfo = document.createElement("p");
    personInfo.textContent = `${person.nome} ${person.cognome}, ${person.res_luogo}`;

    cardBody.appendChild(personInfo);
  });

  familyCard.appendChild(cardBody);
  return familyCard;
}

// Aggiungi l'evento click per il pulsante di ricerca
document.getElementById("searchButton").addEventListener("click", function() {
    const searchInput = document.getElementById("searchInput").value.toLowerCase();
  
    // Filtra le persone in base al luogo di residenza
    const filteredPeople = window.familyData.filter(person =>
      person.res_luogo.toLowerCase().includes(searchInput)
    );
  
    // Ricostruisci il Carousel con le persone filtrate
    rebuildCarousel(filteredPeople);
  });

  

// Funzione per ricostruire il Carousel con le persone filtrate
function rebuildCarousel(people) {
  const carouselInner = document.querySelector(".carousel-inner");
  carouselInner.innerHTML = ""; // Rimuovi il contenuto attuale del Carousel

  const families = {};
  people.forEach((person) => {
    if (!families[person.id_famiglia]) {
      families[person.id_famiglia] = [];
    }
    families[person.id_famiglia].push(person);
  });

  let isFirstFamily = true;
  for (const familyId in families) {
    const family = families[familyId];
    const familyCard = createFamilyCard(family);

    if (isFirstFamily) {
      familyCard.classList.add("active");
      isFirstFamily = false;
    }

    carouselInner.appendChild(familyCard);
  }
}

// Carica i dati delle famiglie e delle persone al caricamento della pagina
document.addEventListener("DOMContentLoaded", function() {
  loadFamilyData(); // Carica i dati delle famiglie e delle persone
  const searchInput = document.getElementById("searchInput");
  const searchButton = document.getElementById("searchButton");

  // Aggiungi l'evento keyup per il campo di ricerca
  searchInput.addEventListener("keyup", function(event) {
    if (event.key === "Enter") {
      searchButton.click(); // Esegui la ricerca quando viene premuto "Invio"
    }
  });
});

