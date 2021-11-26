module.exports = { foo_a };

var b = require("./zadanie3_2")

function foo_a(n){
    if ( n > 0 ) {
        console.log( `a: ${n}`);
        b.foo_b(n-1);
    }
}