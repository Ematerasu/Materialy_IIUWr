function sum(...args) {
    let sum = 0;
    for(let i = 0; i < args.length;i++){
        sum += args[i];
    }
    return sum;
}
console.log(sum(1,2,3))
// 6
console.log(sum(1,2,3,4,5))
// 15