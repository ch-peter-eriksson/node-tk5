#include "DispArray.h"
#include "iostream"
#include <comutil.h>
#include <string>

using namespace std;

ULONG __stdcall DispArray::AddRef()
{
  return ++m_cRef;
}

ULONG __stdcall DispArray::Release() {
  --m_cRef;
  if (m_cRef == 0) {
    delete this;
    return 0;
  }
  return m_cRef;
}

HRESULT __stdcall DispArray::QueryInterface(REFIID riid, void** ppv)
{
  return E_NOINTERFACE;
}

HRESULT __stdcall DispArray::GetTypeInfoCount(UINT * pctinfo) {
  *pctinfo = 0;
  return S_OK;
}

HRESULT __stdcall DispArray::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo) {
  *ppTInfo = NULL;
  return E_NOTIMPL;
}

HRESULT __stdcall DispArray::GetIDsOfNames(REFIID riid, LPOLESTR *rgczNames, UINT cNames, LCID lcid, DISPID * rgDispId) {
  LPOLESTR s = *rgczNames;
  wstring strArray(s);
  if (strArray.compare(L"length") == 0) {
    *rgDispId = (DISPID)_length;
  }
  else {
    wstring strArray(*rgczNames);
    int i = std::stoi(strArray);
    *rgDispId = (DISPID)i;
  }
  return S_OK;
}

HRESULT __stdcall DispArray::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExceptInfo, UINT *puArgErr) {
  if (dispIdMember == _length) {
    pVarResult->vt = VT_INT;
    pVarResult->intVal = _length;
    return S_OK;
  }
  
  VariantClear(pVarResult);
  pVarResult->vt = VT_R4;
  pVarResult->fltVal = _arr[dispIdMember];

  return S_OK;
}
