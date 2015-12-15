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
    Nan::SetPrototypeMethod(tpl, "stopAnimation", StopAnimation);
    Nan::SetPrototypeMethod(tpl, "set", Set);
    Nan::SetPrototypeMethod(tpl, "createNode", CreateNode);
    Nan::SetPrototypeMethod(tpl, "createEffect", CreateEffect);
    Nan::SetPrototypeMethod(tpl, "copyNode", CopyNode);
    Nan::SetPrototypeMethod(tpl, "renameNode", RenameNode);
    Nan::SetPrototypeMethod(tpl, "deleteNode", DeleteNode);
    Nan::SetPrototypeMethod(tpl, "deleteEffect", DeleteEffect);
    Nan::SetPrototypeMethod(tpl, "loadScene", LoadScene);
    Nan::SetPrototypeMethod(tpl, "doAction", DoAction);
    Nan::SetPrototypeMethod(tpl, "beginTransaction", BeginTransaction);
    Nan::SetPrototypeMethod(tpl, "endTransaction", EndTransaction);
    Nan::SetPrototypeMethod(tpl, "rollTransaction", RollTransaction);
    Nan::SetPrototypeMethod(tpl, "callback", Callback);
    Nan::SetPrototypeMethod(tpl, "preload", Preload);
    Nan::SetPrototypeMethod(tpl, "beginSequencePreview", BeginSequencePreview);
    Nan::SetPrototypeMethod(tpl, "endSequencePreview", EndSequencePreview);
    Nan::SetPrototypeMethod(tpl, "captureStillPreview", CaptureStillPreview);
    Nan::SetPrototypeMethod(tpl, "setZoneState", SetZoneState);

    constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
  }

  
  static inline CommandListWrapper* Unwrap(Nan::NAN_METHOD_ARGS_TYPE info) {
    return Nan::ObjectWrap::Unwrap<CommandListWrapper>(info.This());
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
    BSTR addr = Tk5Utils::paramAsBSTR(info, 0);
    if (addr == NULL) {
      Nan::ThrowError(Nan::Error(Nan::New("Node address is missing in set cmd").ToLocalChecked()));
      return;
    }

    BSTR attr = Tk5Utils::paramAsBSTR(info, 1);
    if (attr == NULL) {
      SysFreeString(addr);
      Nan::ThrowError(Nan::Error(Nan::New("Attribute is missing in set cmd").ToLocalChecked()));
      return;
    }
    variant_t val = Tk5Utils::argToVariant(info[2]);
    clw->cl->set(addr, attr, val);
    SysFreeString(addr);
    SysFreeString(attr);
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

    // get node address
    BSTR addr = Tk5Utils::paramAsBSTR(info, 1);
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
    SysFreeString(addr);
  }

  static NAN_METHOD(StopAnimation) {
    CommandListWrapper* clw = Unwrap(info);
    BSTR b1 = Tk5Utils::paramAsBSTR(info, 0);
    BSTR b2 = Tk5Utils::paramAsBSTR(info, 1);
    if (b1 == NULL) {
      Nan::ThrowError("No scene name passed");
      return;
    }

    if (b2 == NULL) { 
      SysFreeString(b1);
      Nan::ThrowError("No address argument passed to stopAnimation");
      return;
    }

    HRESULT hr = clw->cl->stopAnimation(b1, b2);
    SysFreeString(b1);
    SysFreeString(b2);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(CreateNode) {
    CommandListWrapper* clw = Unwrap(info);
    BSTR b1 = Tk5Utils::paramAsBSTR(info, 0);
    BSTR b2 = Tk5Utils::paramAsBSTR(info, 1);
    if (b1 == NULL) {
      Nan::ThrowError("No node type passed to createNode");
      return;
    }

    if (b2 == NULL) {
      SysFreeString(b1);
      Nan::ThrowError("No address argument passed to createNode");
      return;
    }

    HRESULT hr = clw->cl->createNode(b1, b2);
    SysFreeString(b1);
    SysFreeString(b2);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(CreateEffect) {
    CommandListWrapper* clw = Unwrap(info);
    BSTR b1 = Tk5Utils::paramAsBSTR(info, 0);
    BSTR b2 = Tk5Utils::paramAsBSTR(info, 1);
    if (b1 == NULL) {
      Nan::ThrowError("No effect type passed to createEffect");
      return;
    }

    if (b2 == NULL) {
      SysFreeString(b1);
      Nan::ThrowError("No address argument passed to createEffect");
      return;
    }

    HRESULT hr = clw->cl->createEffect(b1, b2);
    SysFreeString(b1);
    SysFreeString(b2);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(CopyNode) {
    CommandListWrapper* clw = Unwrap(info);
    BSTR b1 = Tk5Utils::paramAsBSTR(info, 0);
    BSTR b2 = Tk5Utils::paramAsBSTR(info, 1);
    if (b1 == NULL) {
      Nan::ThrowError("No src address passed to copyNode");
      return;
    }

    if (b2 == NULL) {
      SysFreeString(b1);
      Nan::ThrowError("No dest address passed to copyNode");
      return;
    }

    HRESULT hr = clw->cl->copyNode(b1, b2);
    SysFreeString(b1);
    SysFreeString(b2);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(RenameNode) {
    CommandListWrapper* clw = Unwrap(info);
    BSTR b1 = Tk5Utils::paramAsBSTR(info, 0);
    BSTR b2 = Tk5Utils::paramAsBSTR(info, 1);
    if (b1 == NULL) {
      Nan::ThrowError("No src address passed to renameNode");
      return;
    }

    if (b2 == NULL) {
      SysFreeString(b1);
      Nan::ThrowError("No dest address passed to renameNode");
      return;
    }

    HRESULT hr = clw->cl->renameNode(b1, b2);
    SysFreeString(b1);
    SysFreeString(b2);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(DeleteNode) {
    CommandListWrapper* clw = Unwrap(info);
    BSTR b1 = Tk5Utils::paramAsBSTR(info, 0);
    if (b1 == NULL) {
      Nan::ThrowError("No address passed to deleteNode");
      return;
    }

    HRESULT hr = clw->cl->deleteNode(b1);
    SysFreeString(b1);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(DeleteEffect) {
    CommandListWrapper* clw = Unwrap(info);
    BSTR b1 = Tk5Utils::paramAsBSTR(info, 0);
    if (b1 == NULL) {
      Nan::ThrowError("No address passed to deleteEffect");
      return;
    }

    HRESULT hr = clw->cl->deleteEffect(b1);
    SysFreeString(b1);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(DoAction) {
    CommandListWrapper* clw = Unwrap(info);
    BSTR b1 = Tk5Utils::paramAsBSTR(info, 0);
    if (b1 == NULL) {
      Nan::ThrowError("No action name passed to doAction");
      return;
    }
      
    HRESULT hr = clw->cl->doAction(b1);
    SysFreeString(b1);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(BeginTransaction) {
    CommandListWrapper* clw = Unwrap(info);
    variant_t v = Tk5Utils::argToVariant(info[0]);
    HRESULT hr = clw->cl->beginTransaction(v);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(EndTransaction) {
    CommandListWrapper* clw = Unwrap(info);
    HRESULT hr = clw->cl->endTransaction();
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(RollTransaction) {
    CommandListWrapper* clw = Unwrap(info);
    variant_t v = Tk5Utils::argToVariant(info[0]);
    HRESULT hr = clw->cl->rollTransaction(v);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(Callback) {
    CommandListWrapper* clw = Unwrap(info);
    long id = info[0]->Uint32Value();
    HRESULT hr = clw->cl->callback(&id);
    info.GetReturnValue().Set(id);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(Preload) {
    CommandListWrapper* clw = Unwrap(info);
    BSTR b1 = Tk5Utils::paramAsBSTR(info, 0);
    if (b1 == NULL) {
      Nan::ThrowError("No address passed to preload");
      return;
    }

    HRESULT hr = clw->cl->preload(b1);
    SysFreeString(b1);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(BeginSequencePreview) {
    CommandListWrapper* clw = Unwrap(info);
    long id = info[0]->Uint32Value();
    HRESULT hr = clw->cl->beginSequencePreview(id);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(EndSequencePreview) {
    CommandListWrapper* clw = Unwrap(info);
    int id = info[0]->Uint32Value();
    HRESULT hr = clw->cl->endSequencePreview(id);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(CaptureStillPreview) {
    CommandListWrapper* clw = Unwrap(info);
    int id = info[0]->Uint32Value();
    HRESULT hr = clw->cl->captureStillPreview(id);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(SetZoneState) {
    CommandListWrapper* clw = Unwrap(info);
    BOOL state = info[0]->BooleanValue();
    HRESULT hr = clw->cl->setZoneState(state);
    Tk5Utils::CheckAndThrowCOMError(hr);
  }

  static NAN_METHOD(LoadScene) {
    CommandListWrapper* clw = Unwrap(info);
    BSTR b1 = Tk5Utils::paramAsBSTR(info, 0);
    BSTR b2 = Tk5Utils::paramAsBSTR(info, 1);
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