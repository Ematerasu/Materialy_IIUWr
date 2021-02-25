<?php
$IsPostFormData = (isset($_POST["sent"]) && ($_POST["sent"]=="y"));
$IsGetFormData = (isset($_GET["sent"]) && ($_GET["sent"]=="y"));
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<title>Dane osobowe</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<style type="text/css">
td,th,body { font-family:Verdana, Arial, Helvetica, sans-serif; font-size:10pt; }

.error {color: black;}

</style>
</head>

<body>
    
    <?php
        $cardNumberError = $dateError = $cvcError = $nameError = $mailError = $phoneNumberError = $valueError = "";
        $cardNumber = $date = $cvc = $name = $mail = $phoneNumber = $value = "";
        
        if($_SERVER["REQUEST_METHOD"]=="POST") {
            
            if(empty($_POST["card-number"])) {
                $cardNumberError = "Nie wprowadzono numeru karty";
            } else {
                $cardNumber = input_data($_POST["card-number"]);
                if(!preg_match("/^[0-9]*$/", $cardNumber)) {
                    $cardNumberError = "W numerze kart dozwolone sa tylko cyfry";
                }
                
                if(strlen($cardNumber) != 16) {
                    $cardNumberError = "Numer karty musi miec 24 cyfry";
                }
            }
            
            if(empty($_POST["date"])) {
                $dateError = "Nie wprowadzono daty waznosci";
            } else {
                $date = input_data($_POST["date"]);
                if(!preg_match("/^(0?[1-9]|[12][0-9]|3[01])[\/\-](0?[1-9]|1[012])[\/\-]\d{4}$/", $date)) {
                    $dateError = "Bledna data";
                }
            }
            
            if(empty($_POST["cvc"])) {
                $cvcError = "Nie wprowadzono numeru cvc";
            } else {
                $cvc = input_data($_POST["cvc"]);
                if(!preg_match("/^[0-9]*$/", $cvc)) {
                    $cvcError = "W numerze cvc dozwolone sa tylko cyfry";
                }
                
                if(strlen($cvc) != 3) {
                    $cvcError = "Numer cvc musi miec 3 cyfry";
                }
            }
            
            if (empty($_POST["name"])) {  
                $nameError = "Nie wprowadzono imienia i nazwiska";  
            } else {  
                $name = input_data($_POST["name"]);  
                if (!preg_match("/^[a-zA-Z ]*$/",$name)) {  
                    $nameError  = "Tylko litery i spacje sa dozwolone";  
                }  
            }
            
            if (empty($_POST["mail"])) {  
                $mailError = "Nie wprowadzono adresu e-mail";  
            } else {  
                $mail = input_data($_POST["mail"]);  
                if (!filter_var($mail, FILTER_VALIDATE_EMAIL)) {  
                    $mailError = "Invalid email format";  
                }  
            }
            
            if(empty($_POST["phone-number"])) {
                $phoneNumberError = "Nie wprowadzono numeru telefonu";
            } else {
                $phoneNumber = input_data($_POST["phone-number"]);
                if(!preg_match("/^[0-9]*$/", $phoneNumber)) {
                    $phoneNumberError = "W numerze telefonu dozwolone sa tylko cyfry";
                }
                if(strlen($phoneNumber) != 9) {
                    $phoneNumberError = "Numer telefonu musi miec 9 cyfr";
                }
            }
            
            if(empty($_POST["kwota"])) {
                $valueError = "Nie wprowadzono kwoty";
            } else {
                $value = input_data($_POST["kwota"]);
                if(!preg_match("/^[0-9]*$/", $value)) {
                    $cardNumberError = "W numerze kwoty dozwolone sa tylko cyfry";
                }
            }
}

function input_data($data) {  
  $data = trim($data);  
  $data = stripslashes($data);  
  $data = htmlspecialchars($data);  
  return $data;  
}  
        
    ?>

<h3 align="center">Dane osobowe</h3>

<form name="dane" action="dane.php" method="post">
<table align="center" cellpadding="4" cellspacing="2" border="0" bgcolor="#FF9900" width="500px">
<tr><th align="left">Nr karty:</th><td><input name="card-number" type="number" size="20" maxlength="24" value="<?php echo isset($_POST['card-number']) ? $_POST['card-number'] : '' ?>"><span class="error">*<?php echo $cardNumberError;?></span></td></tr>
<tr><th align="left">Data waznosci karty:</th><td><input name="date" type="text" size="20" maxlength="40" value="<?php echo isset($_POST['date']) ? $_POST['date'] : '' ?>"><span class="error">*<?php echo $dateError;?></span></td></tr>
<tr><th align="left">CVC:</th><td><input name="cvc" type="number" size="6" maxlength="3" value="<?php echo isset($_POST['cvc']) ? $_POST['cvc'] : '' ?>"><span class="error">*<?php echo $cvcError;?></span></td></tr>
<tr><th align="left">Imie i nazwisko:</th><td><input name="name" type="text" size="11" maxlength="11" value="<?php echo isset($_POST['name']) ? $_POST['name'] : '' ?>"><span class="error">*<?php echo $nameError;?></span></td></tr>
<tr><th align="left">Adres e-mail:</th><td><input name="mail" type="e-mail" value="<?php echo isset($_POST['mail']) ? $_POST['mail'] : '' ?>"><span class="error">*<?php echo $mailError;?></span></td></tr>
<tr><th align="left">Nr telefonu:</th><td><input name="phone-number" type="number" value="<?php echo isset($_POST['phone-number']) ? $_POST['phone-number'] : '' ?>"><span class="error">*<?php echo $phoneNumberError;?></span></td></tr>
<tr><th align="left">Kwota:</th><td><input name="kwota" type="number" value="<?php echo isset($_POST['kwota']) ? $_POST['kwota'] : '' ?>"><span class="error">*<?php echo $valueError;?></span></td></tr>
<tr><td align="center" colspan="2"><input type="submit" value="Wyslij" name="submit"></td></tr>
</table>
<input name="sent" type="hidden" value="y">
</form>
<div style="text-align:center">
<?php  
    if($IsPostFormData) {
    if($cardNumberError == "" && $dateError == "" && $cvcError == "" && $nameError == "" && $mailError == "" && $phoneNumberError == "" && $valueError == "") {  
        echo "<h3 color = black> <b>Dziekuje, transakcja udana</b> </h3>";  
        echo "<h2>Twoje dane</h2>";  
        echo "Numer karty: " .$cardNumber;  
        echo "<br>";  
        echo "Data waznosci karty: " .$date;  
        echo "<br>";  
        echo "Numer cvc: " .$cvc;  
        echo "<br>";  
        echo "Imie i nazwisko: " .$name;  
        echo "<br>";  
        echo "Adres e-mail: " .$mail;  
        echo "<br>";  
        echo "Numer telefonu: " .$phoneNumber;  
        echo "<br>";  
        echo "Kwota: " .$value;  
        echo "<br>";  
    }
}  
?> 
</div>

</body>
</html>