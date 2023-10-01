

<!DOCTYPE html>
<html>
<head>
    <title>Tavola Pitagorica</title>
</head>
<body>
    <table border="1">
        <caption>Tavola Pitagorica da 1 a 12</caption>
        <tr>
            <th>&times;</th>
            <?php
            for ($i = 1; $i <= 12; $i++) {
                echo "<th>$i</th>";
            }
            ?>
        </tr>
        <?php
        for ($i = 1; $i <= 12; $i++) {
            echo "<tr>";
            echo "<th>$i</th>";
            for ($j = 1; $j <= 12; $j++) {
                echo "<td>" . ($i * $j) . "</td>";
            }
            echo "</tr>";
        }
        ?>
    </table>
</body>
</html>
