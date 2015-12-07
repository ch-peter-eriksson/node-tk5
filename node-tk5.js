var TM = require('./build/Release/node-tk5').TitleManager;
var events = require('events');

inherits(TM, events.EventEmitter);

// extend prototype
function inherits(target, source) {
  for (var k in source.prototype)
    target.prototype[k] = source.prototype[k];
}

module.exports.TitleManager = TM;