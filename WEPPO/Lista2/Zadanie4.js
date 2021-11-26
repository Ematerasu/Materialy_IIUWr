//instanceof sprawdza czy obiekt powstał przy użyciu danego konstruktora
//typeof zwraca typ obiektu

//instanceof lepiej używać dla stworzonych przez programistę typów albo jakichś skomplikowanych obiektów
//typeof sprawdza się w przypadku prostych typów: int, string, bool

//Przykład przy użyciu

let temp = "example";
console.log(typeof temp); //string, typ primitywny
console.log(temp instanceof String); //false

let temp2 = new String("example");
console.log(typeof temp2); //object, każdy nieprymitywny typ jest typu object
console.log(temp2 instanceof String); //true
