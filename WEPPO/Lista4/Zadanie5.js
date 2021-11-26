var fs = require("fs");

fs.readFile("zad5.txt", "utf-8", function(err, data) {
    if (err) {
        throw err;
    }
    console.log(data);
});
