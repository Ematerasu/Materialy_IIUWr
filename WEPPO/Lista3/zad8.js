function* take(it, top) {
    for(let i = 0; i < top; i++){
        let temp = it.next();
        if(temp.done){
            return;
        }
        yield temp.value;
    }
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

for (let num of take(fib(), 10)) {
    console.log(num);
}