const express = require('express');
const fs = require('fs');
const path = require('path');
const { exec } = require('child_process');
const { stdout } = require('process');

const app = express();

app.use(express.static(path.join(__dirname, '/../public')));
app.use(express.json());
app.use(express.urlencoded({ extended : true }));

app.get('/', (req, res) => {
	res.sendFile(path.join(__dirname, '/../public/index.html'));
});

app.get('/index', (req, res) => {
	res.sendFile(path.join(__dirname, '/../public/index.html'));
});

app.get('/about', (req, res) => {
	res.sendFile(path.join(__dirname, '/../public/about.html'));
});

app.get('/ds', (req, res) => {
  let fileName = req.query.name + '.html';
	res.sendFile(path.join(__dirname, '/../public/' + fileName));
});

app.get('/form', (req, res) => {
  let dir = 'forms/' + req.query.ds + '/' + req.query.id + '.html';
	res.sendFile(path.join(__dirname, '/../public/' + dir));
});

app.get("/send-file", (req, res) => {
  res.download(path.join(__dirname, '/output.txt'), "output.txt" ,(err) => {
    if (err) {
      console.log('error:', err.message);
      res.send(err);
    } else {
      console.log("file sent");
    }
  });
	// res.sendFile(path.join(__dirname, '/output.txt'));
});

app.post("/submit-form", (req, res) => {
  let data = req.body.ds + '\n' + req.body.dimensions + '\n' + req.body.size + '\n' + req.body.lBound + '\n' + req.body.rBound;
  let pathToCpp = path.join(__dirname, '/../CPP_Reference/Main.cpp');
  fs.writeFile(path.join(__dirname, '/input.txt'), data, () => {
    console.log('done');
  });
  
  exec(`g++ ${pathToCpp} -o Main`, (err, stdout, stdin) => {
    console.log('run')
    exec('./Main < input.txt', (err, stdout, stdin) => {
      if (err) {
        console.log(err.message);
      }
      console.log('Done');
    });
  });
  res.end();
  
});

const PORT = process.env.PORT || 5000;

app.listen(PORT, () => {
	console.log(`Server started at ${PORT}`);
});