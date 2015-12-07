var TM = require('./build/Release/node-tk5').TitleManager;
var events = require('events');
var util = require('util');

util.inherits(events.EventEmitter, TM);

module.exports.TitleManager = TM;