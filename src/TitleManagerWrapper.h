#pragma once
#include <nan.h>
#include <v8.h>
#include "../Toolkit5_h.h"
#include "Tk5Utils.h"
#include "ClientWrapper.h"
#include "CmdEventSink.h"
#include "EventWorker.h"
#include "TitleWrapper.h"
#include "AnimationWrapper.h"
#include "AnimationOptionsWrapper.h"
#include "CommandListWrapper.h"
#include "comutil.h"
#include <iostream>

#define _WIN32_FUSION 0x0100

using namespace v8;
using namespace std;

static string *moduleDir;

class TitleManagerWrapper : public Nan::ObjectWrap
{
private:
  CmdEventSink * eventSink = NULL;
  IGSAsyncProcessor* asyncProc = NULL;
  ISupportErrorInfo * supportErrorInfo = NULL;
public:
  static std::string toStdString(Local<String> s) {
    char *buf = new char[s->Length() + 1];
    s->WriteUtf8(buf);
    std::string result(buf);
    delete[] buf;
    return result;
  }
  static std::string portDirname(const std::string& filename) {
    if (filename.length() == 0) return std::string(".");

    // Check for and ignore trailing slashes
    size_t lastpos = filename.length() - 1;
    while (lastpos > 0 && (filename[lastpos] == '/' || filename[lastpos] == '\\')) {
      lastpos--;
    }

    std::size_t slashpos = filename.rfind("/", lastpos);
    std::size_t bslashpos = filename.rfind("\\", lastpos);
    if (slashpos == std::string::npos && bslashpos == std::string::npos) {
      // No slashes
      return std::string(".");
    }
    else {
      std::size_t pos;
      if (slashpos != std::string::npos) pos = slashpos;
      else if (bslashpos != std::string::npos) pos = bslashpos;
      else pos = (slashpos > bslashpos) ? slashpos : bslashpos;
      if (pos == 0) {
        return filename.substr(0, 1);
      }
      else {
        // Remove trailing slashes
        size_t endpos = pos;
        while (endpos > 0 && (filename[endpos] == '/' || filename[endpos] == '\\')) {
          endpos--;
        }
        return filename.substr(0, endpos + 1);
      }
    }
  }

  static std::string* getModuleDir(Handle<Object> module) {
    std::string moduleFilename(toStdString(module->Get(Nan::New<String>("filename").ToLocalChecked())->ToString()));
    return new std::string(portDirname(moduleFilename));
  }
  static Local<Object> getProcessObject() {
    return Nan::GetCurrentContext()->Global()->Get(Nan::New<String>("process").ToLocalChecked())->ToObject();
  }

  static std::string* findApplicationDir() {
    Handle<Value> mainModule = getProcessObject()->Get(Nan::New<String>("mainModule").ToLocalChecked());
    if (!mainModule->IsUndefined()) {
      return getModuleDir(mainModule->ToObject());
    }
    return NULL;
  }
  static void Init(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target, Handle<Object> module){
    moduleDir = getModuleDir(module);
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
    BSTR b = Tk5Utils::paramAsBSTR(info, 0);
    if (b == NULL) {
      Nan::ThrowError(Nan::Error(Nan::New("Expected first argument to be a string").ToLocalChecked()));
    }
    return b;
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
