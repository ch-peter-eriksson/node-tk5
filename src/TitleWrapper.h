#pragma once
#include <nan.h>
#include "CommandListWrapper.h"
#include "../Toolkit5_h.h"

using namespace std;

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
    Nan::SetPrototypeMethod(tpl, "destroy", Destroy);
    Nan::SetPrototypeMethod(tpl, "setProject", SetProject);
    Nan::SetPrototypeMethod(tpl, "setTitleName", SetTitleName);
    Nan::SetPrototypeMethod(tpl, "getZone", GetZone);

    Nan::SetPrototypeMethod(tpl, "destroyInTransaction", DestroyInTransaction);
    Nan::SetPrototypeMethod(tpl, "setDestroyTransactionName", SetDestroyTransactionName);

    constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
  }

  static NAN_METHOD(Execute) {
    TitleWrapper* obj = Nan::ObjectWrap::Unwrap<TitleWrapper>(info.This());
    CommandListWrapper* clw = Nan::ObjectWrap::Unwrap<CommandListWrapper>(info[0]->ToObject());
    variant_t v = NULL;
    if ((info.Length() > 1) && (info[1]->IsString())) {
      String::Utf8Value cmd(info[1]);
      string nodePrefix = string(*cmd);
      v = nodePrefix.c_str();
    }
    obj->title->execute(clw->cl, v);
  }

  static NAN_METHOD(Destroy) {
    TitleWrapper* obj = Nan::ObjectWrap::Unwrap<TitleWrapper>(info.This());
    obj->title->destroy();
    obj->title = NULL;
  }

  static NAN_METHOD(SetProject) {
    TitleWrapper* obj = Nan::ObjectWrap::Unwrap<TitleWrapper>(info.This());
    BSTR b1 = Tk5Utils::paramAsBSTR(info, 0);
    obj->title->setProject(b1);
    SysFreeString(b1);
    obj->title = NULL;
  }

  static NAN_METHOD(SetTitleName) {
    TitleWrapper* obj = Nan::ObjectWrap::Unwrap<TitleWrapper>(info.This());
    BSTR b1 = Tk5Utils::paramAsBSTR(info, 0);
    obj->title->setTitleName(b1);
    SysFreeString(b1);
    obj->title = NULL;
  }

  static NAN_METHOD(GetZone) {
    TitleWrapper* obj = Nan::ObjectWrap::Unwrap<TitleWrapper>(info.This());
    BSTR b1;
    obj->title->getZone(&b1);
    info.GetReturnValue().Set(Nan::New((uint16_t*)b1).ToLocalChecked());
    SysFreeString(b1);
    obj->title = NULL;
  }

  static NAN_METHOD(DestroyInTransaction) {
    TitleWrapper* obj = Nan::ObjectWrap::Unwrap<TitleWrapper>(info.This());
    variant_t v = Tk5Utils::argToVariant(info[0]);
    obj->title->destroyInTransaction(v);
    obj->title = NULL;
  }

  static NAN_METHOD(SetDestroyTransactionName) {
    TitleWrapper* obj = Nan::ObjectWrap::Unwrap<TitleWrapper>(info.This());
    BSTR b = Tk5Utils::paramAsBSTR(info, 0);
    obj->title->setDestroyTransactionName(b);
    SysFreeString(b);
  }

  static Nan::NAN_METHOD_RETURN_TYPE NewInstance(Nan::NAN_METHOD_ARGS_TYPE info, IGSTitle* title) {
    v8::Local<v8::Function> cons = Nan::New(constructor());
    v8::Local<v8::Object> obj = Nan::NewInstance(cons).ToLocalChecked();
    TitleWrapper* tw = Nan::ObjectWrap::Unwrap<TitleWrapper>(obj);

    tw->title = title;
    info.GetReturnValue().Set(obj);
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