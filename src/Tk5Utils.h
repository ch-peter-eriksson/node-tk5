#pragma once
#include <v8.h>
#include "comutil.h"

using namespace std;

namespace Tk5Utils {
  vector<string> split(string str, char delimiter);
  BSTR paramAsBSTR(Nan::NAN_METHOD_ARGS_TYPE info, int idx);
  bool CheckAndThrowCOMError(HRESULT hr);
  BSTR Utf8StrToBSTR(char* str);
  std::string v8StrToStdStr(v8::Local<v8::String> s);
  variant_t argToVariant(v8::Local<v8::Value> arg);
  void returnVariant(Nan::ReturnValue<v8::Value> val, variant_t v);
 }