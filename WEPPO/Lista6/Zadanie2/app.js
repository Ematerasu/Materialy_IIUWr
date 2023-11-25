var http = require('http');
var express = require('express');

var app = express()

app.set('view engine', 'ejs')
app.set('views', './views')

app.use( (req, res) => {
    let radios = {
        name: 'radios',
        options: [
            { id: "first",  text: "First option" },
            { id: "second", text: "Second option" },
            { id: "third", text: "Third option" },
        ]
    }

    res.render('index', {radios})
})

http.createServer(app).listen(3000)