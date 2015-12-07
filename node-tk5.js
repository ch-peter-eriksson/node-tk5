var TM = require('./build/Release/node-tk5').TitleManager;
var events = require('events');
var utils = require('utils');

inherits(TM, events.EventEmitter);
module.exports.TitleManager = TM;