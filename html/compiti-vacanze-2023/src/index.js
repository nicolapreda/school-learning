document
  .getElementById("loginForm")
  .addEventListener("submit", function (event) {
    event.preventDefault();

    const username = document.getElementById("username").value;
    const password = document.getElementById("password").value;

    // Validazione del nome utente (3-10 caratteri)
    if (username.length < 3 || username.length > 10) {
      alert("Il nome utente deve avere tra 3 e 10 caratteri.");
      return;
    }

    // Validazione della password (almeno una minuscola, una maiuscola, una cifra e un carattere speciale)
    const passwordRegex =
      /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@!?\_])[A-Za-z\d@!?\_]{8,}$/;
    if (!password.match(passwordRegex)) {
      alert(
        "La password deve contenere almeno una minuscola, una maiuscola, una cifra e un carattere tra '@', '!', '?', '_' e deve essere lunga almeno 8 caratteri."
      );
      return;
    }

    // Se la validazione ha successo, salva l'utente nel localStorage
    localStorage.setItem("loggedInUser", username);

    // Reindirizza l'utente a home.html
    window.location.href = "home.html";
  });

