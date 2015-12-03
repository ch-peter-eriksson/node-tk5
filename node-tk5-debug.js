/*/*********************************************************************
 * NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2015 NAN contributors
 *
 * MIT License <https://github.com/nodejs/nan/blob/master/LICENSE.md>
 ********************************************************************/
try {
var events = require('events');
console.log('wait...');
setTimeout(function() {
  console.log('go');
  var TM = require('./build/Debug/node-tk5').TitleManager;
  inherits(TM, events.EventEmitter);

  var tm = new TM();
  console.log('Tk5 ver', tm.getToolkitVersion());
  tm.setProject('repro');
  tm.on('message', function(msg) {
    console.log('MESSAGE!', msg);
  });
  tm.on('disconnect', function() {
    console.log('DISCONNECT!');
  });
  tm.on('pickResult', function(xml) {
    console.log('Pick result', xml);
  });
  tm.on('command', function(cmd){
    console.log('Command callback', cmd);
  });
  tm.on('zoneStateChanged', function(zoneName, zoneState) {  
    console.log('onZoneStateChanged', zoneName, zoneState);
  })

  var options = tm.createAnimationOptions();
  options.offset = 123;
  console.log(options.offset);

  var c = tm.getClient();
  c.setServerAddress('sarv-pe');
  c.connect();
  console.log('addr', c.getServerAddress());

var t;

  t = tm.createTitle('');
  var cl = tm.createCommandList();
  cl.loadScene('peter.gse', 'peter');
  var opt = tm.createAnimationOptions();
  opt.playMode = 'BACKWARD';
  var anim = tm.createAnimation();
  var ch = anim.createChannel();
  ch.destination = 'Rotation.Z';
  ch.after = 'CYCLE';
  ch.before = 'CYCLE';
  ch.addKeyframe(0, 0, "LINEAR", "LINEAR"); 
  ch.addKeyframe(50, 500, "LINEAR", "LINEAR");
  cl.animate(anim, 'a', opt);

  cl.set('text', 'BaseColor', [1,1,0,0.5]); 

  t.execute(cl);
console.log('waiting again');
}, 1000);


setTimeout(function() {
  console.log('delete');
  delete tm;
  global.gc();
}, 20000);

// extend prototype
function inherits(target, source) {
  for (var k in source.prototype)
    target.prototype[k] = source.prototype[k];
}

} catch(e) {
  console.log(e);
  setTimeout(function() {}, 5000);
}