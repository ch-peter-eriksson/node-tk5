#pragma once
#include <nan.h>
#include <v8.h>
#include "../Toolkit5_h.h"
#include "Tk5Utils.h"

using namespace v8;

class AnimationChannelWrapper : public Nan::ObjectWrap
{
private:
  IGSAnimationChannel* channel = NULL;
public:
  AnimationChannelWrapper() {}
  ~AnimationChannelWrapper() {
    if (channel) {
      channel = NULL;
    }
  }

  static NAN_MODULE_INIT(Init) {
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // node methods
    SetPrototypeMethod(tpl, "addKeyframe", AddKeyFrame);
    constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
  }

  static inline BSTR paramAsBSTR(Nan::NAN_METHOD_ARGS_TYPE info, int idx) {
    if (info[idx]->IsString()) {
      String::Utf8Value cmd(info[idx]);
      BSTR b = Tk5Utils::StrToBSTR(*cmd);
      return b;
    }
    else {
      return NULL;
    }
  }

  static NAN_METHOD(AddKeyFrame) {
    AnimationChannelWrapper* obj = Unwrap(info);
    BSTR b1 = paramAsBSTR(info, 3);
    BSTR b2 = paramAsBSTR(info, 4);
    if (b1 == NULL) b1 = Tk5Utils::StrToBSTR("");
    if (b2 == NULL) b2 = Tk5Utils::StrToBSTR("");
    if ((b1) && (b2)) {
      HRESULT hr = obj->channel->addKeyframe(info[0]->NumberValue(), info[1]->NumberValue(), b1, b2);
      SysFreeString(b1);
      SysFreeString(b2);
      info.GetReturnValue().Set(Tk5Utils::CheckAndThrowCOMError(hr));
    }
  }

  static inline AnimationChannelWrapper* Unwrap(Nan::NAN_METHOD_ARGS_TYPE info) {
    return Nan::ObjectWrap::Unwrap<AnimationChannelWrapper>(info.This());
  }

  static Nan::NAN_METHOD_RETURN_TYPE NewInstance(Nan::NAN_METHOD_ARGS_TYPE info, IGSAnimationChannel* channel) {
    v8::Local<v8::Function> cons = Nan::New(constructor());
    v8::Local<v8::Object> obj = Nan::NewInstance(cons).ToLocalChecked();
    AnimationChannelWrapper* aw = Nan::ObjectWrap::Unwrap<AnimationChannelWrapper>(obj);

    aw->channel = channel;
    info.GetReturnValue().Set(obj);
  }

  static NAN_METHOD(New) {
    if (info.IsConstructCall()) {
      AnimationChannelWrapper* obj = new AnimationChannelWrapper();
      obj->channel = NULL;
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