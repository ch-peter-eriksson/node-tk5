#include "nan.h"
#include "Tk5Utils.h"

using namespace std;

namespace Tk5Utils {
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
  BSTR StrToBSTR(char* str) {
    string s = string(str);
    std::wstring wstr(s.length() + 1, 0);

    MultiByteToWideChar(CP_ACP,
      0,
      s.c_str(),
      s.length(),
      &wstr[0],
      s.length());

    BSTR b = SysAllocString(wstr.c_str());
    return b;
  }
}