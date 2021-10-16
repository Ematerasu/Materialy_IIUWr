function getDigits(num){
    let digits = [];

    while(num){
        digits.push(num % 10);
        num = Math.floor(num / 10);
    }

    return digits;
}

function isGoodNumber(num){
    let digits = getDigits(num);
    let sum = 0;
    for(let i = 0; i < digits.length; i++){
        if(digits[i] == 0 || num % digits[i] != 0){
            return false;
        }
        sum += digits[i];
    }

    return (num % sum == 0);
}

let set = new Set();

for(let i = 1; i <= 100000; i++){
    if(isGoodNumber(i)){
        set.add(i)
    }
}

console.log(set)