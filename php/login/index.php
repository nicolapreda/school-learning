<?php

// Funzione per controllare se l'utente è già registrato
function isUserRegistered($email, $filePath) {
    $utenti = file($filePath, FILE_IGNORE_NEW_LINES);
    foreach ($utenti as $utente) {
        list(, , $emailSalvata) = explode(',', $utente);
        if ($emailSalvata === $email) {
            return true;
        }
    }
    return false;
}

// Verifica se il modulo è stato inviato
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $nome = trim($_POST['nome']);
    $cognome = trim($_POST['cognome']);
    $email = trim($_POST['email']);
    $file_path = "utenti.txt";

    // Verifica se l'utente è già registrato
    if (isUserRegistered($email, $file_path)) {
        echo "Utente già registrato!";
    } else {
        // Registra l'utente
        $file = fopen($file_path, "a");
        fputcsv($file, [$nome, $cognome, $email]);
        fclose($file);
        echo "Utente registrato con successo!";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Registrazione Utente</title>
</head>
<body>
    <h1>Registrazione Utente</h1>
    <form action="" method="POST">
        Nome: <input type="text" name="nome" required><br>
        Cognome: <input type="text" name="cognome" required><br>
        Email: <input type="email" name="email" required><br>
        <input type="submit" value="Registra">
    </form>
</body>
</html>
