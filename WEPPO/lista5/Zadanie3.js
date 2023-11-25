var http = require('http');

var file = 'temp.txt';

var server = http.createServer((req, res) => {
    res.setHeader('Content-Disposition', 'attachment; filename=' + file);
    res.write('Hello world!');
    res.end();
});

server.listen(3000);

console.log('started!');