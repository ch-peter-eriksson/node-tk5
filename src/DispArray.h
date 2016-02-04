#pragma once
#include "windows.h"
#include "ole2.h"

class DispArray : public IDispatch {
private:
  long m_cRef = 0;
  float _arr[10];
  int _length = 0;
public:
  DispArray(float arr[], int length) { 
    memcpy(_arr, arr, length * sizeof(float));
    _length = length; 
  }
  ~DispArray() { 
  }
  // IUnknown
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  HRESULT __stdcall QueryInterface(REFIID riid, void** ppv);

  //IDispatch
  HRESULT __stdcall  GetTypeInfoCount(UINT * pctinfo);
  HRESULT __stdcall  GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
  HRESULT __stdcall  GetIDsOfNames(REFIID riid, LPOLESTR *rgczNames, UINT cNames, LCID lcid, DISPID * rgDispId);
  HRESULT __stdcall  Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExceptInfo, UINT *puArgErr);
};

