function createIteratorLimited(limit) {
    return function createIterator(){ //iterator ma być bezargumentowy więc zwracamy iterator bezargumentowy, który jednak ma ustawiony limit z parametru limit
        var _state = 0;
        return {
            next : function() {
                return {
                    value: _state,
                    done: _state++ >= limit
                }
            }
        }
    }
}

var foo1 = {
    [Symbol.iterator]: createIteratorLimited(5)
}
var foo2 = {
    [Symbol.iterator]: createIteratorLimited(13)
}

for ( var f of foo1 ) {
    console.log(f);
}

console.log("\n")

for ( var f of foo2 ) {
    console.log(f);
}
   
   