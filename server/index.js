const express = require('express');
const fs = require('fs');
const path = require('path');
const { exec } = require('child_process');
const { stdout } = require('process');

const app = express();

app.use(express.static(path.join(__dirname, '/../public')));
app.use(express.json());
app.use(express.urlencoded({ extended : true }));

app.get("/", (req, res) => {
	res.sendFile(path.join(__dirname, '/../public/index.html'));
});

const PORT = process.env.PORT || 5000;

app.listen(PORT, () => {
	console.log(`Server started at ${PORT}`);
	// let pathToCpp = path.join(__dirname, '/../CPP_Reference');
	// exec(`g++ ${pathToCpp}/Main.cpp -o Main`, (err, stdout, stdin) => {
	// 	exec(`./Main < input.txt > output.txt`, (err, stdout, stdin) => {
	// 		if (err) {
	// 			console.log(err.message);
	// 			return;
	// 		}
	// 		console.log('Done');
	// 	});
	// });
});