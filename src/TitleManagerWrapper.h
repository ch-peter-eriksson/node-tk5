#pragma once
#include <nan.h>
#include <v8.h>
#include "../Toolkit5_h.h"
#include "ClientWrapper.h"
#include "CmdEventSink.h"
#include "EventWorker.h"
#include "TitleWrapper.h"
#include "AnimationWrapper.h"
#include "AnimationOptionsWrapper.h"
#include "CommandListWrapper.h"
#include "comutil.h"
#include <iostream>
#include "Tk5Utils.h"

using namespace v8;
using namespace std;

class TitleManagerWrapper : public Nan::ObjectWrap
{
private:
  CmdEventSink * eventSink = NULL;
  IGSAsyncProcessor* asyncProc = NULL;
  ISupportErrorInfo * supportErrorInfo = NULL;
public:
    static NAN_MODULE_INIT(Init) {
    TitleWrapper::Init(target);
    ClientWrapper::Init(target);
    AnimationWrapper::Init(target);
    AnimationOptionsWrapper::Init(target);
    CommandListWrapper::Init(target);

    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("TitleManager").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    SetPrototypeMethod(tpl, "getClient", GetClient);
    SetPrototypeMethod(tpl, "createTitle", CreateTitle);
    SetPrototypeMethod(tpl, "createTitleInChannel", CreateTitleInChannel);
    SetPrototypeMethod(tpl, "createAnimation", CreateAnimation);
    SetPrototypeMethod(tpl, "createAnimationOptions", CreateAnimationOptions);
    SetPrototypeMethod(tpl, "createCommandList", CreateCommandList);
    SetPrototypeMethod(tpl, "setProject", SetProject);
    SetPrototypeMethod(tpl, "getToolkitVersion", GetToolkitVersion);


    constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
    Nan::Set(target, Nan::New("TitleManager").ToLocalChecked(),
      Nan::GetFunction(tpl).ToLocalChecked());
  }

  static inline TitleManagerWrapper* Unwrap(Nan::NAN_METHOD_ARGS_TYPE info) {
    return Nan::ObjectWrap::Unwrap<TitleManagerWrapper>(info.This());
  }

  static inline BSTR firstParamAsBSTR(Nan::NAN_METHOD_ARGS_TYPE info) {
    if (info[0]->IsString()) {
      String::Utf8Value cmd(info[0]);
      BSTR b = Tk5Utils::StrToBSTR(*cmd);
      return b;
    }
    else {
      Nan::ThrowError(Nan::Error(Nan::New("Expected first argument to be a string").ToLocalChecked()));
      return NULL;
    }
  }

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

  static NAN_METHOD(SetProject) {
    TitleManagerWrapper* tm = Unwrap(info);
    BSTR b = firstParamAsBSTR(info);
    HRESULT hr = tm->ptm->setProject(b);
    SysFreeString(b);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(CreateTitle) {
    TitleManagerWrapper* tmw = Unwrap(info);
    IGSTitle* title = NULL;
    variant_t zone = ""; 
    if (info[0]->IsString()) {
      String::Utf8Value cmd(info[0]);
      string zoneName = string(*cmd);
      zone = zoneName.c_str();
    }

    HRESULT hr = tmw->ptm->createTitle(zone, &title);
    if (Tk5Utils::CheckAndThrowCOMError(hr)) {
      TitleWrapper::NewInstance(info, title);
    }
  }

  static NAN_METHOD(CreateCommandList) {
    TitleManagerWrapper* tmw = Unwrap(info);
    IGSCommandList* cl = NULL;
    HRESULT hr = tmw->ptm->createCommandList(&cl);
    if (Tk5Utils::CheckAndThrowCOMError(hr)) {
      CommandListWrapper::NewInstance(info, cl);
    }
  }

  static NAN_METHOD(CreateTitleInChannel) {
    TitleManagerWrapper* tmw = Unwrap(info);
    IGSTitle* title = NULL;
    BSTR b = firstParamAsBSTR(info);

    HRESULT hr = tmw->ptm->createTitleInChannel(b, info[1]->Uint32Value(), &title);
    SysFreeString(b);
    if (Tk5Utils::CheckAndThrowCOMError(hr)) {
      TitleWrapper::NewInstance(info, title);
    }
  }

  static NAN_METHOD(FindTitleByName) {
    TitleManagerWrapper* tmw = Unwrap(info);
    IGSTitle* title = NULL;
    BSTR b = firstParamAsBSTR(info);

    HRESULT hr = tmw->ptm->findTitleByName(b, &title);
    SysFreeString(b);
    if (Tk5Utils::CheckAndThrowCOMError(hr)) {
      TitleWrapper::NewInstance(info, title);
    }
  }

  static NAN_METHOD(FindTitleByZone) {
    TitleManagerWrapper* tmw = Unwrap(info);
    IGSTitle* title = NULL;
    BSTR b = firstParamAsBSTR(info);

    HRESULT hr = tmw->ptm->findTitleByZone(b, &title);
    SysFreeString(b);
    if (Tk5Utils::CheckAndThrowCOMError(hr)) {
      TitleWrapper::NewInstance(info, title);
    }
  }

  static NAN_METHOD(GetClient) {
    TitleManagerWrapper *obj = Nan::ObjectWrap::Unwrap<TitleManagerWrapper>(info.This());
    IGSClient* client = NULL;
    HRESULT hr = obj->ptm->getClient(&client);
    if (Tk5Utils::CheckAndThrowCOMError(hr)) {
      ClientWrapper::NewInstance(info, client);
    }
  }


  static NAN_METHOD(GetToolkitVersion) {
    TitleManagerWrapper *obj = Nan::ObjectWrap::Unwrap<TitleManagerWrapper>(info.This());
    BSTR b;
    HRESULT hr = obj->ptm->getToolkitVersion(&b);
    Tk5Utils::CheckAndThrowCOMError(hr);
    info.GetReturnValue().Set(Nan::New((uint16_t*)b).ToLocalChecked());
  }

  static NAN_METHOD(CreateAnimation) {
    TitleManagerWrapper *obj = Nan::ObjectWrap::Unwrap<TitleManagerWrapper>(info.This());
    IGSAnimation* anim = NULL;
    HRESULT hr = obj->ptm->createAnimation(&anim);
    if (Tk5Utils::CheckAndThrowCOMError(hr)) {
      AnimationWrapper::NewInstance(info, anim);
    }
  }

  static NAN_METHOD(CreateAnimationOptions) {
    TitleManagerWrapper *obj = Nan::ObjectWrap::Unwrap<TitleManagerWrapper>(info.This());
    IGSAnimationOptions* options = NULL;
    HRESULT hr = obj->ptm->createAnimationOptions(&options);
    if (Tk5Utils::CheckAndThrowCOMError(hr)) {
      AnimationOptionsWrapper::NewInstance(info, options);
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
};  

NODE_MODULE(GSTK5, TitleManagerWrapper::Init);
