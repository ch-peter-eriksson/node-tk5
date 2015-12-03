#pragma once
#include <nan.h>
#include <v8.h>
#include "../Toolkit5_h.h"
#include "Tk5Utils.h"

using namespace v8;

class AnimationOptionsWrapper : public Nan::ObjectWrap
{
private:
public:
  IGSAnimationOptions* options = NULL;
  AnimationOptionsWrapper() {}
  ~AnimationOptionsWrapper() {
    if (options) {
      options = NULL;
    }
  }

  static NAN_MODULE_INIT(Init) {
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    v8::Local<ObjectTemplate> proto = tpl->PrototypeTemplate();

    Nan::SetAccessor(proto, Nan::New("offset").ToLocalChecked(), GetOffset, SetOffset);
    Nan::SetAccessor(proto, Nan::New("skip").ToLocalChecked(), GetSkip, SetSkip);
    Nan::SetAccessor(proto, Nan::New("end").ToLocalChecked(), GetEnd, SetEnd);
    Nan::SetAccessor(proto, Nan::New("playMode").ToLocalChecked(), GetPlayMode, SetPlayMode);
    Nan::SetAccessor(proto, Nan::New("enableFinish").ToLocalChecked(), GetEnableFinish, SetEnableFinish);
    Nan::SetAccessor(proto, Nan::New("name").ToLocalChecked(), GetName, SetName);
    Nan::SetAccessor(proto, Nan::New("watchID").ToLocalChecked(), GetWatchID, SetWatchID);

    // node methods
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

  static inline AnimationOptionsWrapper* Unwrap(Nan::NAN_METHOD_ARGS_TYPE info) {
    return Nan::ObjectWrap::Unwrap<AnimationOptionsWrapper>(info.This());
  }
  static inline AnimationOptionsWrapper* Unwrap(Nan::NAN_GETTER_ARGS_TYPE info) {
    return Nan::ObjectWrap::Unwrap<AnimationOptionsWrapper>(info.This());
  }
  static inline AnimationOptionsWrapper* Unwrap(Nan::NAN_SETTER_ARGS_TYPE info) {
    return Nan::ObjectWrap::Unwrap<AnimationOptionsWrapper>(info.This());
  }

  static Nan::NAN_METHOD_RETURN_TYPE NewInstance(Nan::NAN_METHOD_ARGS_TYPE info, IGSAnimationOptions* options) {
    v8::Local<v8::Function> cons = Nan::New(constructor());
    v8::Local<v8::Object> obj = Nan::NewInstance(cons).ToLocalChecked();
    AnimationOptionsWrapper* aw = Nan::ObjectWrap::Unwrap<AnimationOptionsWrapper>(obj);

    aw->options = options;
    info.GetReturnValue().Set(obj);
  }

  static NAN_METHOD(New) {
    if (info.IsConstructCall()) {
      AnimationOptionsWrapper* obj = new AnimationOptionsWrapper();
      obj->options = NULL;
      obj->Wrap(info.This());
      info.GetReturnValue().Set(info.This());
    }
    else {
      v8::Local<v8::Function> cons = Nan::New(constructor());
      info.GetReturnValue().Set(Nan::NewInstance(cons).ToLocalChecked());
    }
  }

  static NAN_GETTER(GetOffset) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    float val;
    obj->options->get_offset(&val);
    info.GetReturnValue().Set(val);
  }

  static NAN_SETTER(SetOffset) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    float val = value->NumberValue();
    obj->options->put_offset(val);
  }

  static NAN_GETTER(GetSkip) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    float val;
    obj->options->get_skip(&val);
    info.GetReturnValue().Set(val);
  }

  static NAN_SETTER(SetSkip) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    float val = value->NumberValue();
    obj->options->put_skip(val);
  }

  static NAN_GETTER(GetEnd) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    float val;
    obj->options->get_end(&val);
    info.GetReturnValue().Set(val);
  }

  static NAN_SETTER(SetEnd) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    float val = value->NumberValue();
    obj->options->put_end(val);
  }

  static NAN_GETTER(GetPlayMode) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    BSTR b;
    obj->options->get_playMode(&b);
    info.GetReturnValue().Set(Nan::New((uint16_t*)b).ToLocalChecked());
  }

  static NAN_SETTER(SetPlayMode) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    String::Utf8Value cmd(value);
    BSTR b = Tk5Utils::StrToBSTR(*cmd);
    obj->options->put_playMode(b);
  }

  static NAN_GETTER(GetEnableFinish) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    BOOL val;
    obj->options->get_enableFinish(&val);
    info.GetReturnValue().Set(val);
  }

  static NAN_SETTER(SetEnableFinish) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    bool val = value->BooleanValue();
    obj->options->put_enableFinish(val);
  }

  static NAN_GETTER(GetName) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    BSTR b;
    obj->options->get_name(&b);
    info.GetReturnValue().Set(Nan::New((uint16_t*)b).ToLocalChecked());
  }

  static NAN_SETTER(SetName) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    String::Utf8Value cmd(value);
    BSTR b = Tk5Utils::StrToBSTR(*cmd);
    obj->options->put_name(b);
  }

  static NAN_GETTER(GetWatchID) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    int val;
    obj->options->get_watchID(&val);
    info.GetReturnValue().Set(val);
  }

  static NAN_SETTER(SetWatchID) {
    AnimationOptionsWrapper* obj = Unwrap(info);
    int val = value->IntegerValue();
    obj->options->put_watchID(val);
  }

  static inline Nan::Persistent<v8::Function> & constructor() {
    static Nan::Persistent<v8::Function> my_constructor;
    return my_constructor;
  }
};