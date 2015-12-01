#pragma once
#include <nan.h>
#include <iostream>
#include <v8.h>
#include "Tk5Utils.h"
#include "../Toolkit5_h.h"

using namespace v8;

class ClientWrapper : public Nan::ObjectWrap
{
private:
  IGSClient* client = NULL;
public:
  ClientWrapper() {}
  ~ClientWrapper() {
    if (client) {
      client = NULL;
    }
  }

  static NAN_MODULE_INIT(Init) {
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // node methods
    Nan::SetPrototypeMethod(tpl, "connect", Connect);
    Nan::SetPrototypeMethod(tpl, "disconnect", Disconnect);
    Nan::SetPrototypeMethod(tpl, "setPassword", SetPassword);
    Nan::SetPrototypeMethod(tpl, "setServerAddress", SetServerAddress);
    Nan::SetPrototypeMethod(tpl, "getServerAddress", GetServerAddress);
    Nan::SetPrototypeMethod(tpl, "getZoneState", GetZoneState);
    Nan::SetPrototypeMethod(tpl, "setZoneState", SetZoneState);
    Nan::SetPrototypeMethod(tpl, "switchCamera", SwitchCamera);
    Nan::SetPrototypeMethod(tpl, "previewGenerateID", PreviewGenerateID);
    Nan::SetPrototypeMethod(tpl, "previewSchedule", PreviewSchedule);
    Nan::SetPrototypeMethod(tpl, "previewGetStillImageFile", PreviewGetStillImageFile);
    Nan::SetPrototypeMethod(tpl, "previewGetSequenceImageFiles", PreviewGetSequenceImageFiles);
    Nan::SetPrototypeMethod(tpl, "writeRenderPicture", WriteRenderPicture);
    Nan::SetPrototypeMethod(tpl, "writeScene", WriteScene);

    constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
  }

  static NAN_METHOD(Connect) {
    ClientWrapper* obj = Unwrap(info);
    HRESULT hr = obj->client->connect();
    info.GetReturnValue().Set(Tk5Utils::CheckAndThrowCOMError(hr));
  }

  static NAN_METHOD(Disconnect) {
    ClientWrapper* obj = Unwrap(info);
    HRESULT hr = obj->client->disconnect();
    info.GetReturnValue().Set(Tk5Utils::CheckAndThrowCOMError(hr));
  }

  static inline ClientWrapper* Unwrap(Nan::NAN_METHOD_ARGS_TYPE info) {
    return Nan::ObjectWrap::Unwrap<ClientWrapper>(info.This());
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

  static NAN_METHOD(SetPassword) {
    ClientWrapper* obj = Unwrap(info);
    BSTR b = firstParamAsBSTR(info);
    if (b) {
      HRESULT hr = obj->client->setPassword(b);
      SysFreeString(b);
      Tk5Utils::CheckAndThrowCOMError(hr);
    }
  }

  static NAN_METHOD(SetServerAddress) {
    ClientWrapper* obj = Unwrap(info);
    BSTR b = firstParamAsBSTR(info);
    if (b) {
      HRESULT hr = obj->client->setServerAddress(b);
      SysFreeString(b);
      Tk5Utils::CheckAndThrowCOMError(hr);
    }
  }

  static NAN_METHOD(GetServerAddress) {
    ClientWrapper* obj = Unwrap(info);
    BSTR addr;
    HRESULT hr = obj->client->getServerAddress(&addr);
    Tk5Utils::CheckAndThrowCOMError(hr);
    info.GetReturnValue().Set(Nan::New((uint16_t*)addr).ToLocalChecked());
  }

  static NAN_METHOD(GetZoneState) {
    ClientWrapper* obj = Unwrap(info);
    BSTR b = firstParamAsBSTR(info);
    if (b) {
      BOOL state;
      HRESULT hr = obj->client->getZoneState(b, &state);
      info.GetReturnValue().Set(Nan::New<v8::Boolean>(state));
      SysFreeString(b);
      Tk5Utils::CheckAndThrowCOMError(hr);
    }
  }

  static NAN_METHOD(SetZoneState) {
    ClientWrapper* obj = Unwrap(info);
    BSTR b = firstParamAsBSTR(info);
    if (b) {
      if (info[1]->IsBoolean()) {
        HRESULT hr = obj->client->setZoneState(b, info[1]->BooleanValue());
        Tk5Utils::CheckAndThrowCOMError(hr);
      }
    }
  }

  static NAN_METHOD(SwitchCamera) {
    ClientWrapper* obj = Unwrap(info);
    BSTR b = firstParamAsBSTR(info);
    obj->client->switchCamera(b);
  }

  static NAN_METHOD(PreviewGenerateID) {
    ClientWrapper* obj = Unwrap(info);
    int id;
    HRESULT hr = obj->client->previewGenerateID(&id);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(PreviewSchedule) {
    ClientWrapper* obj = Unwrap(info);
    HRESULT hr = obj->client->previewSchedule(info[0]->Uint32Value());
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(PreviewGetStillImageFile) {
    ClientWrapper* obj = Unwrap(info);
    String::Utf8Value cmd(info[1]);
    BSTR b = Tk5Utils::StrToBSTR(*cmd);
    HRESULT hr = obj->client->previewGetStillImageFile(info[0]->Uint32Value(), b);
    SysFreeString(b);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(PreviewGetSequenceImageFiles) {
    ClientWrapper* obj = Unwrap(info);
    String::Utf8Value cmd(info[1]);
    BSTR b = Tk5Utils::StrToBSTR(*cmd);
    int numImages = 0;
    unsigned int id = info[0]->Uint32Value();
    HRESULT hr = obj->client->previewGetSequenceImageFiles(id, b, &numImages);
    SysFreeString(b);
    Tk5Utils::CheckAndThrowCOMError(hr);
    info.GetReturnValue().Set(Nan::New<v8::Integer>(numImages));
  }

  static NAN_METHOD(WriteRenderPicture) {
    ClientWrapper* obj = Unwrap(info);
    HRESULT hr = obj->client->writeRenderPicture();
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(WriteScene) {
    ClientWrapper* obj = Unwrap(info);
    HRESULT hr = obj->client->writeScene();
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static Nan::NAN_METHOD_RETURN_TYPE NewInstance(Nan::NAN_METHOD_ARGS_TYPE info, IGSClient* client) {
    v8::Local<v8::Function> cons = Nan::New(constructor());
    v8::Local<v8::Object> obj = Nan::NewInstance(cons).ToLocalChecked();
    ClientWrapper* cw = Nan::ObjectWrap::Unwrap<ClientWrapper>(obj);
    
    cw->client = client;
    info.GetReturnValue().Set(obj);
  }

  static NAN_METHOD(New){
    if (info.IsConstructCall()) {
      ClientWrapper* obj = new ClientWrapper();
      obj->client = NULL;
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