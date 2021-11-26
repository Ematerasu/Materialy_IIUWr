var readline = require('readline');
var fs = require('fs');

var reader = readline.createInterface({
  input: fs.createReadStream('zad6.txt')
});

var ip_dict = {

}

reader.on('line', function (line) {
    var ip = line.split(" ")[1];
    if (ip in ip_dict)
        ip_dict[ip] += 1;
    else
        ip_dict[ip] = 1;
});

reader.on('close', function() {
    var items = Object.keys(ip_dict).map(function(key) {
        return [key, ip_dict[key]];
    });

    items.sort(function(first, second) {
        return second[1] - first[1];
    });

    console.log(items.slice(0,3));
});