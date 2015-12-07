{
  "targets": [
    {
      "target_name": "node-tk5",
      "sources": [
        "Toolkit5_i.c",
        "src/TitleWrapper.h",
        "src/TitleWrapper.cc",
        "src/AnimationWrapper.h",
        "src/AnimationChannelWrapper.h",
        "src/AnimationOptionsWrapper.h",
        "src/ClientWrapper.h",
        "src/ClientWrapper.cc",
        "src/TitleManagerWrapper.h",
        "src/TitleManagerWrapper.cc",
        "src/CmdEventSink.cc",
        "src/CmdEventSink.h",
        "src/CommandListWrapper.h",
        "src/DispArray.h",
        "src/DispArray.cc",
        "src/EventWorker.h",
        "src/tk5utils.cc",
        "src/tk5utils.h"

      ],
      "libraries": [
        "-lcomsuppw.lib"
      ],
      "include_dirs": [ "<!(node -e \"require('nan')\")" ]
    }
  ]
}
