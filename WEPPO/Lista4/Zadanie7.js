const fs   = require('fs');
const util = require('util');

// fs:readFile ale zwracamy Promise
function fspromise( path, enc ) {
    return new Promise( (res, rej) => {
        fs.readFile( path, enc, (err, data) => {
        if ( err )
            rej(err);
        res(data);
        })
    })
};
   

//util.promisify
util.promisify(fs.readFile)('zad5.txt', 'utf-8').then(data => {
    console.log("util.promisify:\n" + data + "\n\n");
});

// fs.promises
fs.promises.readFile('zad5.txt', 'utf-8').then(data => {
    console.log("fs.promises:\n" + data + "\n\n");
});


// Promise::then
fspromise('zad5.txt', 'utf-8').then(data => {
    console.log("promise::then:\n" + data + "\n\n");
});

// asyns/await
(async function readAsync() {
    var data = await fspromise('zad5.txt', 'utf-8');
    console.log("async/await:\n" + data + "\n\n");
})();