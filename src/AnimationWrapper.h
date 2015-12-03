#pragma once
#include <nan.h>
#include <v8.h>
#include "../Toolkit5_h.h"
#include "Tk5Utils.h"
#include "AnimationChannelWrapper.h"

using namespace v8;

class AnimationWrapper : public Nan::ObjectWrap
{
private:
public:
  IGSAnimation* anim = NULL;
  AnimationWrapper() {}
  ~AnimationWrapper() {
    if (anim) {
      anim = NULL;
    }
  }

  static NAN_MODULE_INIT(Init) {
    AnimationChannelWrapper::Init(target);
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // node methods
    Nan::SetPrototypeMethod(tpl, "createChannel", CreateChannel);

    constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
  }

  static NAN_METHOD(CreateChannel) {
    AnimationWrapper* obj = Unwrap(info);
    IGSAnimationChannel* channel = NULL;
    HRESULT hr = obj->anim->createChannel(&channel);
    if (Tk5Utils::CheckAndThrowCOMError(hr)) {
      AnimationChannelWrapper::NewInstance(info, channel);
    }
  }

  static inline AnimationWrapper* Unwrap(Nan::NAN_METHOD_ARGS_TYPE info) {
    return Nan::ObjectWrap::Unwrap<AnimationWrapper>(info.This());
  }

  static Nan::NAN_METHOD_RETURN_TYPE NewInstance(Nan::NAN_METHOD_ARGS_TYPE info, IGSAnimation* anim) {
    v8::Local<v8::Function> cons = Nan::New(constructor());
    v8::Local<v8::Object> obj = Nan::NewInstance(cons).ToLocalChecked();
    AnimationWrapper* aw = Nan::ObjectWrap::Unwrap<AnimationWrapper>(obj);

    aw->anim = anim;
    info.GetReturnValue().Set(obj);
  }

  static NAN_METHOD(New) {
    if (info.IsConstructCall()) {
      AnimationWrapper* obj = new AnimationWrapper();
      obj->anim = NULL;
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