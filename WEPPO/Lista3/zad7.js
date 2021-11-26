function fibIter() {
    let a = 1;
    let b = 1;
    return {
        next : function() {
            let c = a
            a = b
            b = c + b
            return {
                value : c,
                done : false
            }
        }
    }
}

var fibIterator = {
    [Symbol.iterator]: fibIter
}

function *fib() {
    let a = 1;
    let b = 1;
    while(true){
        yield a;
        let temp = a;
        a = b;
        b = b + temp;
    }
}

// Działa
/*
for (let f of fibIterator) {
    console.log(f)
}
*/

// Działa
/*
var _it = fib();
for ( var _result; _result = _it.next(), !_result.done; ) {
    console.log( _result.value );
}
*/


// nie dziala dla iteratora
/*
for (let f of fibIter()) {
    console.log(f)
}
*/

// dziala dla generatora
/*
for (let f of fib()) {
     console.log(f)
}
*/
