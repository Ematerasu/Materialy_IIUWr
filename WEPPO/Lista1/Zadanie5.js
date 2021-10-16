function fibRec(n){
    if(n == 0){
        return 0;
    }
    
    if(n == 1){
        return 1;
    }

    return fibRec(n-1) + fibRec(n-2);
}

function fibIter(n){
    if(n == 0){
        return 0;
    }
    
    if(n == 1){
        return 1;
    }

    var a,b,c;
    a = 1;
    b = 0;
    c = 0;

    for(var i = 1; i < n; i++){
        c = a + b;
        b = a;
        a = c;
    }
    return c;
}

console.time("40th Fibonacci number iter")
console.log(fibIter(40))
console.timeEnd("40th Fibonacci number iter")

console.time("40th Fibonacci number Rec")
console.log(fibRec(40))
console.timeEnd("40th Fibonacci number Rec")

//Dla 40 rekurencyjna wersja wykonuje sie na tyle dluzej od iteracyjnej ze tutaj mozemy stwierdzi iz 40 to max

/*
node.js:
    40th Fibonacci number iter: 23.116ms
    40th Fibonacci number Rec: 1.403s

Chrome:
    40th Fibonacci number iter: 0.19091796875 ms
    40th Fibonacci number Rec: 1804.027099609375 ms

Opera:
    40th Fibonacci number iter: 0.2177734375 ms
    40th Fibonacci number Rec: 2387.390869140625 ms
*/