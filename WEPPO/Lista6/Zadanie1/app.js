var http = require('http');
var express = require('express');
var multer = require('multer');

var app = express()
var upload = multer({ dest: 'uploads/' })

app.set('view engine', 'ejs')
app.set('views', './views')

app.get('/', (req, res) => {
    res.render('index')
})

app.post('/upload', upload.single('File'), (req, res) => {
    console.log(req.file)
})

http.createServer(app).listen(3000)