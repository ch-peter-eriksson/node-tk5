#pragma once
#include <nan.h>
#include <v8.h>
#include "../Toolkit5_h.h"
#include "ClientWrapper.h"
#include "CmdEventSink.h"
#include "TitleWrapper.h"
#include "comutil.h"
#include <iostream>
#include "Tk5Utils.h"


using namespace v8;
using namespace std;

class ClientWrapper;

class TitleManagerWrapper : public Nan::ObjectWrap
{
private:
  CmdEventSink * eventSink = NULL;
  ISupportErrorInfo * supportErrorInfo = NULL;

  int value = 123;

  static NAN_METHOD(New) {
    if (info.IsConstructCall()) {
      TitleManagerWrapper *obj = new TitleManagerWrapper();
      obj->Wrap(info.This());
      info.GetReturnValue().Set(info.This());
    }
    else {
      const int argc = 1;
      v8::Local<v8::Value> argv[argc] = { info[0] };
      v8::Local<v8::Function> cons = Nan::New(constructor());
      info.GetReturnValue().Set(cons->NewInstance(argc, argv));
    }
  }

  static NAN_METHOD(getClient) {
    TitleManagerWrapper *obj = Nan::ObjectWrap::Unwrap<TitleManagerWrapper>(info.This());
    IGSClient* client = NULL;
    HRESULT hr = obj->ptm->getClient(&client);
    if (Tk5Utils::CheckAndThrowCOMError(hr)) {
      ClientWrapper::NewInstance(info, client);
    }
    /*
    info.GetReturnValue().Set(obj->value);
    
    v8::Local<v8::Value> argv[1] = {
      Nan::New("bongo").ToLocalChecked(),  // event name
    };
    Nan::MakeCallback(info.This(), "emit", 1, argv);
    */
  }

  static NAN_METHOD(createTitle) {
    TitleManagerWrapper* obj = Nan::ObjectWrap::Unwrap<TitleManagerWrapper>(info.This());
    IGSTitle* title = NULL;

    String::Utf8Value cmd(info[0]);
    string zoneName = string(*cmd);
    variant_t zone = zoneName.c_str();

    HRESULT hr = obj->ptm->createTitle(zone, &title);
    if (Tk5Utils::CheckAndThrowCOMError(hr)) {
      TitleWrapper::NewInstance(info);
    }
  }

  static inline Nan::Persistent<v8::Function> & constructor() {
    static Nan::Persistent<v8::Function> my_constructor;
    return my_constructor;
  }

public:
  IGSTitleManager * ptm;
  TitleManagerWrapper();
  ~TitleManagerWrapper();

  static NAN_MODULE_INIT(Init) {
    TitleWrapper::Init(target);
    ClientWrapper::Init(target);

    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("TitleManager").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    SetPrototypeMethod(tpl, "getClient", getClient);
    SetPrototypeMethod(tpl, "createTitle", createTitle);

    constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
    Nan::Set(target, Nan::New("TitleManager").ToLocalChecked(),
      Nan::GetFunction(tpl).ToLocalChecked());
  }
};  

NODE_MODULE(GSTK5, TitleManagerWrapper::Init);
