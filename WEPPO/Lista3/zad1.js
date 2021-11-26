// Obiekt z jednym polem, metodą i po jednym getterze i setterze
var object = {
    x: 1,
    foo(){
        return "foo";
    },
    get getx(){
        return this.x;
    },
    set setx(x){
        this.x = x;
    }
}

console.log(object.x)
console.log(object.getx)
object.setx = 10
console.log(object.getx)
console.log(object.foo())

// Dodawanie nowego pola, nowej metody w sposób "normalny", można też użyc defineProperty
object.y = 2;
object.bar = function(){
    return "bar";
}
console.log(object.y)
console.log(object.bar())

// dodawanie getterow i setterow za pomocą defineProperty, inaczej sie nie da
Object.defineProperty(object, 'gety', {
    get : function() {
    return this.y;
    }
});

Object.defineProperty(object, 'sety', {
    set : function(y) {
    return this.y = y;
    }
});

console.log(object.gety)
object.sety = 20
console.log(object.gety)


