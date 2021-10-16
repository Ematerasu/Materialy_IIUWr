function IsPrimeNumber(num){
    for(var i = 2; i < num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

let set = new Set();

for(var i = 2; i < 100; i++){
    if(IsPrimeNumber(i)){
        set.add(i)
    }
}

console.log(set)