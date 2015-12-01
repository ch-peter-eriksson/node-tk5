/*/*********************************************************************
 * NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2015 NAN contributors
 *
 * MIT License <https://github.com/nodejs/nan/blob/master/LICENSE.md>
 ********************************************************************/
try {
var events = require('events');
var TM = require('./build/Debug/node-tk5').TitleManager;
inherits(TM, events.EventEmitter);

var tm = new TM();
tm.on('bongo', function(data) {
  console.log('BONGO!');
});
for (var i = 0; i < 10; i++) {
  var c = tm.getClient();
  c.setServerAddress('192.168.5.123');
}
console.log('addr', c.getServerAddress());

function ostkaka() {
  var cl = tm.getClient();
  delete cl;
}

tm.getClient().setPassword('peter');
console.log('preview id', tm.getClient().previewGenerateID());

ostkaka();

//var t = tm.createTitle('peter');
//console.log(t.execute());
console.log('hoho');
delete tm;
tm = null;
global.gc();
setTimeout(function() {}, 5000);

// extend prototype
function inherits(target, source) {
  for (var k in source.prototype)
    target.prototype[k] = source.prototype[k];
}

} catch(e) {
  console.log(e);
  setTimeout(function() {}, 5000);
}