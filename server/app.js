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

app.get('/about', (req, res) => {
	res.sendFile(path.join(__dirname, '/../public/about.html'));
});

app.get('/ds', (req, res) => {
  let fileName = req.query.name + '.html';
	res.sendFile(path.join(__dirname, '/../public/' + fileName));
});

const PORT = process.env.PORT || 5000;

app.listen(PORT, () => {
	console.log(`Server started at ${PORT}`);
});