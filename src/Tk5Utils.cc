#include "nan.h"
#include "Tk5Utils.h"
#include "DispArray.h"
#include <iostream>
#include <sstream>
  
using namespace std;
using namespace v8;

namespace Tk5Utils {
  void returnVariant(Nan::ReturnValue<v8::Value> val, variant_t v) {
    //v.vt
    switch (v.vt) {
    case VT_BSTR: {
      val.Set(Nan::New<v8::String>((uint16_t*)v.bstrVal).ToLocalChecked());
      break;
    }
    case VT_BOOL: {
      val.Set(Nan::New<v8::Boolean>(v.boolVal));
      break;
    }
    case VT_I4: {
      val.Set(Nan::New<v8::Integer>(v.intVal));
      break;
    }
    case VT_I8: {
      val.Set(Nan::New<v8::Integer>(v.intVal));
      break;
    }
    case VT_R4: {
      val.Set(Nan::New<v8::Number>(v.fltVal));
      break;
    }
    case VT_R8: {
      val.Set(Nan::New<v8::Number>(v.fltVal));
      break;
    }
    }
  }

  vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while (getline(ss, tok, delimiter)) {
      internal.push_back(tok);
    }

    return internal;
  }

  std::string v8StrToStdStr(v8::Local<v8::String> s) {
    char *buf = new char[s->Length() + 1];
    s->WriteUtf8(buf);
    std::string result(buf);
    delete[] buf;
    return result;
  }

  bool CheckAndThrowCOMError(HRESULT hr) {
    if (FAILED(hr)) {
      IErrorInfo *inf = NULL;
      GetErrorInfo(0, &inf);
      BSTR desc;
      inf->GetDescription(&desc);
      Nan::ThrowError(Nan::Error(Nan::New((uint16_t*)desc).ToLocalChecked()));
      inf->Release();
      SysFreeString(desc);
      return false;
    }
    return true;
  }

  variant_t argToVariant(v8::Local<v8::Value> arg) {
    variant_t val;
    DispArray * dispArr = NULL;

    if (arg->IsString()) {
      String::Utf8Value cmd(arg);
      val = Tk5Utils::Utf8StrToBSTR(*cmd);
    }
    else if (arg->IsBoolean()) {
      val = arg->BooleanValue();
    }
    else if (arg->IsArray()) {
      Local<Array> argv_handle = v8::Local<Array>::Cast(arg);
      int argc = argv_handle->Length();
      float numbers[10] = {};
      int i;
      for (i = 0; (i < argc) && (i < 10); i++) {
        numbers[i] = argv_handle->Get(Nan::New(i))->NumberValue();
      }

      dispArr = new DispArray(numbers, argc);
      val = dispArr;
    }
    else if (arg->IsInt32()) {
      val = arg->Int32Value();
    }
    else if (arg->IsNumber()) {
      val = arg->NumberValue();
    }
    return val;
  }

  BSTR Utf8StrToBSTR(char* str) {
    string s(str);
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &s[0], (int)s.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &s[0], (int)s.size(), &wstrTo[0], size_needed);
    return SysAllocString(wstrTo.c_str());
  }

  BSTR paramAsBSTR(Nan::NAN_METHOD_ARGS_TYPE info, int idx) {
    if (info[idx]->IsString()) {
      String::Utf8Value cmd(info[idx]);
      BSTR b = Tk5Utils::Utf8StrToBSTR(*cmd);
      return b;
    }
    else {
      return NULL;
    }
  }
}