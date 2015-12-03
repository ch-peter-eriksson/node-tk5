#include "TitleManagerWrapper.h"

using namespace v8;
using namespace std;

// GS2 callbacks

static void GS2Command(void* owner, int cmd) {
  TitleManagerWrapper *sender = (TitleManagerWrapper*)owner;
  Nan::HandleScope scope;
  v8::Local<v8::Value> argv[2] = {
    Nan::New("command").ToLocalChecked(),
    Nan::New<Number>(cmd)
  };
  Nan::MakeCallback(sender->handle(), "emit", 2, argv);
}

static void GS2Disconnect(void* owner) {
  TitleManagerWrapper *sender = (TitleManagerWrapper*)owner;
  Nan::HandleScope scope;
  v8::Local<v8::Value> argv[1] = {
    Nan::New("disconnect").ToLocalChecked()
  };
  Nan::MakeCallback(sender->handle(), "emit", 1, argv);
}

static void GS2PickResult(void* owner, BSTR xmlResult) {
  TitleManagerWrapper *sender = (TitleManagerWrapper*)owner;
  Nan::HandleScope scope;
  v8::Local<v8::Value> argv[2] = {
    Nan::New("pickResult").ToLocalChecked(),
    Nan::New((uint16_t*)xmlResult).ToLocalChecked()
  };
  Nan::MakeCallback(sender->handle(), "emit", 2, argv);
}

static void GS2ZoneStateChange(void* owner, BSTR zoneName, bool zoneState) {
  TitleManagerWrapper *sender = (TitleManagerWrapper*)owner;
  Nan::HandleScope scope;
  v8::Local<v8::Value> argv[3] = {
    Nan::New("zoneStateChanged").ToLocalChecked(),
    Nan::New((uint16_t*)zoneName).ToLocalChecked(),
    Nan::New(zoneState)
  };
  Nan::MakeCallback(sender->handle(), "emit", 3, argv);
}

static void GS2Message(void* owner, BSTR msg) {
  TitleManagerWrapper *sender = (TitleManagerWrapper*)owner;
  Nan::HandleScope scope;
  v8::Local<v8::Value> argv[2] = {
    Nan::New("message").ToLocalChecked(),
    Nan::New((uint16_t*)msg).ToLocalChecked()
  };
  Nan::MakeCallback(sender->handle(), "emit", 2, argv);
}


TitleManagerWrapper::TitleManagerWrapper()
{
  CoInitialize(NULL);
  HRESULT hr = CoCreateInstance(CLSID_TitleManager, NULL, CLSCTX_ALL, IID_IGSTitleManager, (void **)&ptm);
  IGSClient* client;
  hr = ptm->getClient(&client);
  client->createAsyncProcessor(&asyncProc);

  EventWorker::Run(asyncProc);

  eventSink = new CmdEventSink((IDispatch*)client, (void*)this);
  eventSink->onCommandEvent = &GS2Command;
  eventSink->onDisconnectEvent = &GS2Disconnect;
  eventSink->onPickResultEvent = &GS2PickResult;
  eventSink->onZoneChangeEvent = &GS2ZoneStateChange;
  eventSink->onMessageEvent = &GS2Message;

  hr = ptm->QueryInterface(IID_ISupportErrorInfo, (void **)&supportErrorInfo);
  if SUCCEEDED(hr) {
    hr = supportErrorInfo->InterfaceSupportsErrorInfo(IID_IGSTitleManager);
  }
}

TitleManagerWrapper::~TitleManagerWrapper()
{
  if (ptm) { 
    asyncProc->close();
    
    if (eventSink) {
      eventSink->DisconnectSink();
      eventSink = NULL;
    }

    ptm->Release();
    CoUninitialize();
  }
}
