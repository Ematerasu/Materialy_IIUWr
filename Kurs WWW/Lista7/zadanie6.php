<?php
    setcookie( "sernik" , "z czekoladą", time() + 3600, "/" );
    session_start();
    $_SESSION["sesja"]=rand(0 ,1000);
	//ciastka w operze zbadaj element -> application -> cookies
	//path ustawia sciezke gdzie ciastko bedzie sie znajdowac, ustawienie na "/" jak wyzej oznacza ze ciastko bedzie dostepne w calej domenie
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Zadanie6</title>
    </head>
    <body>
        Ciastko: <?php echo $_COOKIE["sernik"]; ?>    <br>
        Ciastko sesyjne: <?php echo $_SESSION["sesja"]; ?>

    </body>
</html>