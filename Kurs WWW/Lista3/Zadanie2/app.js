let markaTab = ["Fiat", "Ford"];
modelTab = {};

modelTab["Fiat"]=[];
modelTab["Fiat"].push("Panda");
modelTab["Fiat"].push("Uno");

modelTab["Ford"]=[];
modelTab["Ford"].push("Ecosport");
modelTab["Ford"].push("Fiesta");

let marka = document.getElementsByName("marka")[0];
let model = document.getElementsByName("model")[0];
let userInput = document.getElementsByName("nowa")[0];
let radioMarka = document.getElementsByName("rodzaj")[0];
let radioModel = document.getElementsByName("rodzaj")[1];
let button = document.getElementsByName("dodaj")[0];

marka.addEventListener('change', updateModelTab);


function updateMarkaTab() {
    let marki = "";
    for(element of markaTab) marki += '<option>'+element+'</option>';

    marka.innerHTML = marki;
}

function updateModelTab() {
    let modele = "";
    for(element of modelTab[marka.value]) modele += '<option>'+element+'</option>';

    model.innerHTML = modele;
}

function addPosition() {
    if(radioMarka.checked) {
        markaTab.push(userInput.value);
        markaTab.sort();
        modelTab[userInput.value] = [];
        updateMarkaTab();
    }
    else if(radioModel.checked) {
        modelTab[marka.value].push(userInput.value);
        modelTab[marka.value].sort();
        updateModelTab();
    }
}

updateMarkaTab();
updateModelTab();


