module.exports = { foo_b };

var a = require("./zadanie3_1")

function foo_b(n){
    if ( n > 0 ) {
        console.log( `b: ${n}`);
        a.foo_a(n-1);
    }
}