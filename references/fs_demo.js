const fs = require('fs');
const path = require('path');

// Create Folder
// fs.mkdir(path.join(__dirname, '/test'), {}, (err) => {
//     if (err) throw err;
//     console.log('Folder Created');
// })

// Create and write file
// fs.writeFile(path.join(__dirname, '/test', 'hello.txt'), 'Hello Boi', err => {
//     if (err) throw err;
//     console.log('Write Done');

//     // Append text
//     fs.appendFile(path.join(__dirname, '/test', 'hello.txt'), ' Whassup', err => {
//         if (err) throw err;
//         console.log('Write Done');
//     });
// });


// Read File
// fs.readFile(path.join(__dirname, '/test', 'hello.txt'), 'utf8', (err, data) => {
//     if (err) throw err;
//     console.log(data);
// });

// Rename File
// fs.rename(path.join(__dirname, '/test', 'hello.txt'), path.join(__dirname, '/test', 'greetings.txt'), (err) => {
//     if (err) throw err;
//     console.log('Renamed');
// });