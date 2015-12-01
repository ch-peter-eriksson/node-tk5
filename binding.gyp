{
"targets": [
{
"target_name": "node-tk5",
"sources": [
"Toolkit5_i.c",
"src/TitleWrapper.h",
"src/TitleWrapper.cc",
"src/ClientWrapper.h",
"src/ClientWrapper.cc",
"src/TitleManagerWrapper.h",
"src/TitleManagerWrapper.cc",
"src/CmdEventSink.cc",
  "src/CmdEventSink.h",
  "src/tk5utils.cc",
  "src/tk5utils.h",
"src/tk5utils.h",
"src/tk5utils.cc",
"src/tk5utils.h"

],
"libraries": [
"-lcomsuppw.lib"
],
"include_dirs": ["<!(node -e \"require('nan')\")"]
}
]}                     