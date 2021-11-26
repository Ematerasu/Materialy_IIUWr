var Foo = (function() {

    function Foo(){
        console.log("Foo function");
    }

    function Bar() {
        Qux();
        console.log("Bar function");
    }

    function Qux() {
        console.log("Qux function");
    }
    
    Foo.prototype.Bar = Bar;

    return Foo;
}());

var test = new Foo();
console.log(Object.getPrototypeOf(test));
test.Bar();
//test.Qux(); // error, test.Qux() is not a function, gdyz jest prywatna i nie mamy do niej dostepu z tego miejsca