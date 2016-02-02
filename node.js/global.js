// include 'path' module
var path = require("path");

var hello = "Hellow World from Node.js";
global.console.log(hello);
//global.console.log(global.hello); 
//   global.console.log() works fine
//   BUT global.hello doesn't work.  hello is a variable to this module only.
//       so it can't be global.

var justNode = hello.slice(17);
console.log(`Rock on World from ${justNode}`);

console.log(__dirname);
console.log(__filename);

console.log(`Rock on World from ${path.basename(__filename)}`);

