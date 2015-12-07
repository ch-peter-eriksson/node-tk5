#node-tk5
Node API wrapping tk5

###Install
To build this library, following components are needed
* Visual Studio 2015 with c++ installed
* Python 2.7
* Python environment variable PYTHON={python-dir including exe}

Install (npm):
`npm install "git+https://bitbucket.org/chyronhego_se/node-tk5.git" --msvs_version=2015`

###Example code

```
#!javascript

var TitleManager = require('node-tk5').TitleManager;

var tm = new TitleManager();
var client = tm.getClient();

client.setServerAddress('127.0.0.1');
client.connect();
tm.setProject('myProject');

var cl = tm.createCommandList();
cl.loadScene('myScene.gse', 'myScene');
cl.set('node', 'Attribute', 'MyData');
var title = tm.createTitle('')
title.execute(cl);

```


Almost all of the api is the same as TK5, only difference is how events are signaled. The TitleManager object emits all possible events.
tm.on('disconnect', function() {});