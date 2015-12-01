#pragma once
#include <v8.h>
#include "comutil.h"

namespace Tk5Utils {
  bool CheckAndThrowCOMError(HRESULT hr);
  BSTR StrToBSTR(char* str);
}