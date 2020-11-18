var accountNum = document.getElementById('accountNumber');
var pesel = document.getElementById('pesel');
var birthDate = document.getElementById('birthDate');
var email = document.getElementById('email');

accountNum.addEventListener("blur", function() {
    var re = /[0-9]{26}/;
    if(re.test(accountNum.value)) accountNum.style.borderColor = "green";
    else accountNum.style.borderColor = "red";
});

pesel.addEventListener("blur", function() {
    var re = /[0-9]{11}/;
    if(re.test(pesel.value)) pesel.style.borderColor = "green";
    else pesel.style.borderColor = "red";
});

birthDate.addEventListener("blur", function() {
    var re = /^(0?[1-9]|[12][0-9]|3[01])[\/\-](0?[1-9]|1[012])[\/\-]\d{4}$/;

    if(re.test(birthDate.value)) birthDate.style.borderColor = "green";
    else birthDate.style.borderColor = "red";
});

email.addEventListener("blur", function() {
    var re = /\S+@\S+\.\S+/;
    if(re.test(email.value)) email.style.borderColor = "green";
    else email.style.borderColor = "red";
});
