
// Pierwsza korekta -> zamiana 'var i' na 'let i'
// Różnice wynikiją z zasięgu zmiennych, let jest tworzona lokalnie, dana wartość 'i' istnieje tylko lokalnie, w kolejnej iteracji 'i' zmienia swoja wartosc
// var natomiast ma zasięg "globalny"
function createFs(n) { // tworzy tablice n funkcji
    var fs = []; // i-ta funkcja z tablicy ma zwrócic i
    for (let i=0; i<n; i++ ) {
        fs[i] =
        function() {
            return i;
        };
    };
    return fs;
}
var myfs = createFs(10);
console.log( myfs[0]() ); // zerowa funkcja miała zwrócic 0
console.log( myfs[2]() ); // druga miała zwrócic 2
console.log( myfs[7]() ); // 7


// Druga korekta -> zagniedzenie fukncji w funkcji
function createFs2(n) { // tworzy tablice n funkcji
    var fs = []; // i-ta funkcja z tablicy ma zwrócic i
    for (var i=0; i<n; i++ ) {
        fs[i] =
        function() {
            let temp = i;
            return function(){
                return temp;
            }
        }();
    };
    return fs;
}
var myfs = createFs2(10);
console.log( myfs[0]() ); // zerowa funkcja miała zwrócic 0
console.log( myfs[2]() ); // druga miała zwrócic 2
console.log( myfs[7]() ); // 7