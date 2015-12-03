#include <uv.h>
#include "../Toolkit5_h.h"
#include <thread>

struct EventWorkerWork {
  uv_async_t  async;
  bool isActive;
  IGSAsyncProcessor* asyncProc;
  std::thread thd;
};

namespace EventWorker {
  static void Run(IGSAsyncProcessor* asyncProc);

  static void close_cb(uv_handle_t* handle) {
    free(handle);
  };

  //called in main thread
  void WorkAsyncComplete(uv_async_t *handle) {
    std::thread* thd;
    EventWorkerWork *work = static_cast<EventWorkerWork *>(handle->data);
    if (work->isActive) {
      work->asyncProc->process();
    }
    else {
      thd = &work->thd;
      thd->join();
      uv_close((uv_handle_t*)handle, close_cb);
    }
  }

  static void runThread(EventWorkerWork* work) {
    while (work->isActive) {
      VARIANT_BOOL vb;
      work->asyncProc->waitEvent(&vb);
      work->isActive = bool(vb);
      uv_async_send(&work->async);
    }
  }

  static void Run(IGSAsyncProcessor* asyncProc) {
    EventWorkerWork* work = new EventWorkerWork();
    work->isActive = true;
    work->asyncProc = asyncProc;
    work->async.data = work;
    
    uv_async_init(uv_default_loop(), &work->async, WorkAsyncComplete);
    work->thd = std::thread(runThread, work);
  }
};

