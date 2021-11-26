
// 1 kropka //
let example = {
    x: '1',
    y: '2',
    Dominik: '3'
}

console.log(example['x']);
console.log(example.y);

//Jak uzywamy '.' powinnismy wczesniej znac dokladny klucz, wyrazenie po kropce nie jest ewaluowane, tak jak w przypadku operatora []
//Przyklad:
console.log(example["Dom"+"inik"]);
//Z kropką nie jesteśmy w stanie takiego wyrażenia skompilować
//console.log(example.("Dom"+"inik"));

///////////////

// 2 kropka //
let example2 = {
    1 : 'x',
    2 : 'y'
}

console.log(example2[1]); // 'x'
console.log(example2['1']); // 'x'
console.log(example2[example]); //undefined
console.log(example2[example.y]); //example.y = 2, example2[2] -> 'y'

//Przy dostepie poprzez inny obiekt niz number i string dostajemy undefined
example2[5] = 10; // element wpisany na index piaty
example2["aaa"] = 15; // element o kluczu nie bedacym liczba zostanie dopisany na koniec w postaci klucz : wartosc
console.log(example2);
example2[4] = "wciskam sie!";
console.log(example2);
//Gdy klucz jest liczba to zostanie wpisany zgodnie z porzadkiem liczbowym, w innym przypadku zostanie wpisany na koniec

/////////////////

// 3 kropka //
let arr = [1,2,3,4];

console.log(arr['2']); //poprawnie
console.log(arr[example2]); //undefined
arr["test"] = 15;
console.log(arr); // zostaje dopisana na koniec w formacie klucz : wartosc
arr.length = 2; //ogranicza liczbe elementow typu number do wartosci podanej
console.log(arr);
arr.length = 10;
console.log(arr); //poszerza tablice do wskazanej wartosci dodajac puste elementy na koniec
