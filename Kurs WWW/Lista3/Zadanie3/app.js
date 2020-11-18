function move(i, block, up) {
    var pos;
    var id;

    if(up) {
        pos = 0;
        id = setInterval(go_up, 1);
    }
    else {
        pos = 50;
        id = setInterval(go_down, 1);
    }

    function go_down() {
        if(pos == 0) {
            clearInterval(id);
        }
        else {
            pos-=1;
            block.style.top = pos + "px";
        }
    }

    function go_up() {
        if(pos == 50) {
            clearInterval(id);
        }
        else {
            pos+=1;
            block.style.top = pos + "px";
        }
    }
}

function takeElem() {
    var block = document.getElementById("block");
    var next = block;
    
    var x = 0;
    var up = true;

    for(let i = 1; i <= 5; i++) { 
        setTimeout(move, x, i, next, up);
        next = next.nextElementSibling;
        x += 200;
    }

    up = false;
    next = block;

    for(let i = 1; i <= 5; i++) {
        setTimeout(move, x, i, next, up);
        next = next.nextElementSibling;
        x += 200;
    }

}

setInterval(takeElem, 3000);
