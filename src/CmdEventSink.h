#pragma once
#include "../Toolkit5_h.h"

class CmdEventSink : IGSCmdEvents
{
private:
  long m_cRef;
  DWORD eventCookie;
  IConnectionPoint * m_pIConnectionPoint = NULL;
public:
  void DisconnectSink();
  // IUnknown
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  HRESULT __stdcall QueryInterface(REFIID riid, void** ppv);

  //IDispatch
  HRESULT __stdcall  GetTypeInfoCount(UINT * pctinfo);
  HRESULT __stdcall  GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
  HRESULT __stdcall  GetIDsOfNames(REFIID riid, LPOLESTR *rgczNames, UINT cNames, LCID lcid, DISPID * rgDispId);
  HRESULT __stdcall  Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExceptInfo, UINT *puArgErr);


  // IOutGoing
  void __stdcall onCommand(int cmd);
  void __stdcall onDisconnect();
  HRESULT __stdcall onPickResult(BSTR xmlResult);
  HRESULT __stdcall onZoneChange(BSTR zoneName, BOOL zoneState);
  HRESULT __stdcall onMessage(BSTR message);

  CmdEventSink(IDispatch *parent);
  ~CmdEventSink();
};
