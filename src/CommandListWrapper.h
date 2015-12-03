#pragma once
#include <nan.h>
#include <v8.h>
#include <iostream>
#include "../Toolkit5_h.h"
#include "Tk5Utils.h"
#include "AnimationWrapper.h"
#include "AnimationOptionsWrapper.h"
#include "DispArray.h"

using namespace v8;
using namespace std;

class CommandListWrapper : public Nan::ObjectWrap
{
public:
  IGSCommandList* cl = NULL;
  CommandListWrapper() {}
  ~CommandListWrapper() {
    if (cl) {
      cl = NULL;
    }
  }

  static NAN_MODULE_INIT(Init) {
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // node methods
    Nan::SetPrototypeMethod(tpl, "animate", Animate);
    Nan::SetPrototypeMethod(tpl, "set", Set);
    Nan::SetPrototypeMethod(tpl, "loadScene", LoadScene);

    constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
  }

  
  static inline CommandListWrapper* Unwrap(Nan::NAN_METHOD_ARGS_TYPE info) {
    return Nan::ObjectWrap::Unwrap<CommandListWrapper>(info.This());
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


  static Nan::NAN_METHOD_RETURN_TYPE NewInstance(Nan::NAN_METHOD_ARGS_TYPE info, IGSCommandList* cl) {
    v8::Local<v8::Function> cons = Nan::New(constructor());
    v8::Local<v8::Object> obj = Nan::NewInstance(cons).ToLocalChecked();
    CommandListWrapper* aw = Nan::ObjectWrap::Unwrap<CommandListWrapper>(obj);

    aw->cl = cl;
    info.GetReturnValue().Set(obj);
  }

  static NAN_METHOD(Set) {
    CommandListWrapper* clw = Unwrap(info);
    DispArray * dispArr = NULL;
    BSTR addr = NULL;
    if (info[0]->IsString()) {
      String::Utf8Value cmd(info[0]);
      addr = Tk5Utils::StrToBSTR(*cmd);
    }
    if (addr == NULL) {
      Nan::ThrowError(Nan::Error(Nan::New("Node address is missing in set cmd").ToLocalChecked()));
      return;
    }

    BSTR attr = NULL;
    if (info[1]->IsString()) {
      String::Utf8Value cmd(info[1]);
      attr = Tk5Utils::StrToBSTR(*cmd);
    }
    if (attr == NULL) {
      Nan::ThrowError(Nan::Error(Nan::New("Attribute is missing in set cmd").ToLocalChecked()));
      return;
    }
    variant_t val;
    if (info[2]->IsString()) {
      String::Utf8Value cmd(info[2]);
      val = variant_t(Tk5Utils::StrToBSTR(*cmd));
    }
    else if (info[2]->IsBoolean()) {
      val = variant_t(info[2]->BooleanValue());
    }
    else if (info[2]->IsArray()) {
      Local<Array> argv_handle = Local<Array>::Cast(info[2]);
      int argc = argv_handle->Length();
      float numbers[10] = {};
      int i;
      for (i = 0; i < argc; i++) {
        numbers[i] = argv_handle->Get(Nan::New(i))->NumberValue();
      }

      dispArr = new DispArray(numbers, argc);
      val = variant_t(dispArr);
    }
    else if (info[2]->IsInt32()) {
      val = variant_t(info[2]->Int32Value());
    }
    else if (info[2]->IsNumber()) {
      val = variant_t(info[2]->NumberValue());
    }
    clw->cl->set(addr, attr, val);
    if (dispArr) {  }
  }

  static NAN_METHOD(Animate) {
    CommandListWrapper* clw = Unwrap(info);
    variant_t opt = NULL;
    if (info.Length() >= 3) {
      if (info[2]->IsObject()) {
        AnimationOptionsWrapper* options = Nan::ObjectWrap::Unwrap<AnimationOptionsWrapper>(info[2]->ToObject());
        if (options) {
          opt = variant_t(options->options);
        }
      }
    }

    // first, get node address
    BSTR addr = NULL;
    if (info[1]->IsString()) {
      String::Utf8Value cmd(info[1]);
      addr = Tk5Utils::StrToBSTR(*cmd);
    }
    if (addr == NULL) {
      Nan::ThrowError(Nan::Error(Nan::New("Node address is missing in animate cmd").ToLocalChecked()));
      return;
    }

    // first argument can be string or AnimationWrapper obj
    if (info[0]->IsString()) {
      variant_t v = "";
      String::Utf8Value cmd(info[0]);
      string animationName = string(*cmd);
      v = animationName.c_str();
      clw->cl->animate(v, addr, opt);
    }
    else if (info[0]->IsObject()) {
      AnimationWrapper* anim = Nan::ObjectWrap::Unwrap<AnimationWrapper>(info[0]->ToObject());
      if (anim) {
        variant_t v = anim->anim;
        clw->cl->animate(v, addr, opt);
      }
    }
  }

  static NAN_METHOD(LoadScene) {
    CommandListWrapper* clw = Unwrap(info);
    BSTR b1 = paramAsBSTR(info, 0);
    BSTR b2 = paramAsBSTR(info, 1);
    if (b1 == NULL) {
      Nan::ThrowError("No scene name passed");
      return;
    }

    if (b2 == NULL) { b2 = BSTR(""); }
    HRESULT hr = clw->cl->loadScene(b1, b2);
    SysFreeString(b1);
    SysFreeString(b2);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(New) {
    if (info.IsConstructCall()) {
      CommandListWrapper* obj = new CommandListWrapper();
      obj->cl = NULL;
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