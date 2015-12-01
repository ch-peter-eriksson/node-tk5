#pragma once
#include <nan.h>
#include "../Toolkit5_h.h"

class TitleWrapper : public Nan::ObjectWrap
{
private:
  IGSTitle* title;
public:
  TitleWrapper()
  {
  }
  static NAN_MODULE_INIT(Init) {
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "execute", Execute);

    constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
  }

  static NAN_METHOD(Execute) {
    TitleWrapper* obj = Nan::ObjectWrap::Unwrap<TitleWrapper>(info.This());
    info.GetReturnValue().Set(321);
  }

  static NAN_METHOD(NewInstance) {
    v8::Local<v8::Function> cons = Nan::New(constructor());
    info.GetReturnValue().Set(Nan::NewInstance(cons).ToLocalChecked());
  }

  static NAN_METHOD(New) {
    if (info.IsConstructCall()) {
      TitleWrapper* obj = new TitleWrapper();
      obj->Wrap(info.This());
      info.GetReturnValue().Set(info.This());
    }
    else {
      v8::Local<v8::Function> cons = Nan::New(constructor());
      info.GetReturnValue().Set(Nan::NewInstance(cons).ToLocalChecked());
    }
  }

  static inline Nan::Persistent<v8::Function> & constructor() {
    static Nan::Persistent<v8::Function> my_constructor;
    return my_constructor;
  }


};