/*/*********************************************************************
 * NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2015 NAN contributors
 *
 * MIT License <https://github.com/nodejs/nan/blob/master/LICENSE.md>
 ********************************************************************/

var events = require('events');
var TM = require('./build/Release/node-tk5').TitleManager;
inherits(TM, events.EventEmitter);

var tm = new TM();
tm.on('bongo', function(data) {
  console.log('BONGO!');
});
console.log(tm.getClient());

setTimeout(function() {}, 5000);

// extend prototype
function inherits(target, source) {
  for (var k in source.prototype)
    target.prototype[k] = source.prototype[k];
}