const EventEmitter = require('events');

// Create class
class MyEmitter extends EventEmitter { }

// Init object
const myEmitter = new MyEmitter();

// Event Listner
myEmitter.on('event', () => console.log('Event Fired!'));

// Init event
myEmitter.emit('event');