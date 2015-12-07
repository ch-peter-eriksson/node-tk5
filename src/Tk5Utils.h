#pragma once
#include <v8.h>
#include "comutil.h"

namespace Tk5Utils {
  BSTR paramAsBSTR(Nan::NAN_METHOD_ARGS_TYPE info, int idx);
  bool CheckAndThrowCOMError(HRESULT hr);
  BSTR Utf8StrToBSTR(char* str);
  variant_t argToVariant(v8::Local<v8::Value> arg);
}