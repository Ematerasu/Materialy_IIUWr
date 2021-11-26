function fibRec(n){
    if(n == 0){
        return 0;
    }
    
    if(n == 1){
        return 1;
    }

    return fibRec(n-1) + fibRec(n-2);
}

function memoize(fn){
    var cache = {};

    return function(n){
        var result;
        if(n in cache){
            result =  cache[n];
        }
        else{
            result = fn(n);
        }
        cache[n] = result;
        return result
    }
}

var memoFib = memoize(fibRec)

console.time("memFib")
console.log(memoFib(40))
console.timeEnd("memFib")

console.time("memFib (with cache)")
console.log(memoFib(40))
console.timeEnd("memFib (with cache)")

console.time("normalFib")
console.log(fibRec(40))
console.timeEnd("normalFib")

