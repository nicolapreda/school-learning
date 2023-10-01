<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <title>Calcolatore Costo Corso di Lingua</title>
</head>
<body>
    <h1>Calcolatore Costo Corso di Lingua</h1>
    
    <?php
    $nome = $cognome = $email = $corso = $livello = $ore = $preferenze_orario = $altre_richieste = $costo_totale = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $nome = test_input($_POST["nome"]);
        $cognome = test_input($_POST["cognome"]);
        $email = test_input($_POST["email"]);
        $corso = test_input($_POST["corso"]);
        $livello = test_input($_POST["livello"]);
        $ore = intval($_POST["ore"]);
        $preferenze_orario = test_input($_POST["preferenze"]);
        $altre_richieste = test_input($_POST["altre_richieste"]);

        $costo_orario = 0;

        switch ($livello) {
            case "base":
                $costo_orario = 15;
                break;
            case "intermedio":
                $costo_orario = 20;
                break;
            case "avanzato":
                $costo_orario = 25;
                break;
            default:
                echo "Livello non valido";
                exit;
        }

        $costo_totale = $costo_orario * $ore;
    }

    function test_input($data) {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }
    ?>

    <form method="POST" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        <label for="nome">Nome:</label>
        <input type="text" name="nome" required><br><br>

        <label for="cognome">Cognome:</label>
        <input type="text" name="cognome" required><br><br>

        <label for="email">Email:</label>
        <input type="email" name="email" required><br><br>

        <label for="corso">Corso di Lingua:</label>
        <select name="corso" required>
            <option value="inglese">Inglese</option>
            <option value="spagnolo">Spagnolo</option>
        </select><br><br>

        <label for="livello">Livello:</label>
        <input type="radio" name="livello" value="base" required> Base
        <input type="radio" name="livello" value="intermedio" required> Intermedio
        <input type="radio" name="livello" value="avanzato" required> Avanzato<br><br>

        <label for="ore">Numero di Ore:</label>
        <select name="ore" required>
            <option value="20">20 ore</option>
            <option value="30">30 ore</option>
            <option value="40">40 ore</option>
        </select><br><br>

        <label for="preferenze">Preferenze Orario:</label>
        <input type="radio" name="preferenze" value="mattina" required> Mattina
        <input type="radio" name="preferenze" value="pomeriggio" required> Pomeriggio
        <input type="radio" name="preferenze" value="sera" required> Sera<br><br>

        <label for="altre_richieste">Altre Richieste:</label>
        <textarea name="altre_richieste" rows="4" cols="50"></textarea><br><br>

        <input type="submit" value="Calcola Costo">
    </form>

    <?php
    if ($costo_totale !== "") {
        echo "<h2>Risultato Calcolo Costo Corso</h2>";
        echo "<p>Nome: $nome</p>";
        echo "<p>Cognome: $cognome</p>";
        echo "<p>Email: $email</p>";
        echo "<p>Corso di Lingua: $corso</p>";
        echo "<p>Livello: $livello</p>";
        echo "<p>Numero di Ore: $ore</p>";
        echo "<p>Preferenze Orario: $preferenze_orario</p>";
        echo "<p>Altre Richieste: $altre_richieste</p>";
        echo "<p>Costo del Corso: $costo_totale euro</p>";
    }
    ?>
</body>
</html>
