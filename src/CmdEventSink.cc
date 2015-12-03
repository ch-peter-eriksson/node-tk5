#pragma once
#include "CmdEventSink.h"


CmdEventSink::CmdEventSink(IDispatch *parent, void* owner)
{
  m_cRef = 0;
  _owner = owner;

  IConnectionPointContainer* pIConnectionPointContainerTemp = NULL;
  IUnknown* pIUnknown = NULL;
  HRESULT hr = NULL;

  hr = parent->QueryInterface(IID_IConnectionPointContainer, (void**)&pIConnectionPointContainerTemp);

  if (pIConnectionPointContainerTemp)
  {
    pIConnectionPointContainerTemp ->
      FindConnectionPoint(__uuidof(IGSCmdEvents), &m_pIConnectionPoint);
    pIConnectionPointContainerTemp->Release();
    pIConnectionPointContainerTemp = NULL;
  }
  if (m_pIConnectionPoint)
  {
    hr = m_pIConnectionPoint->Advise((IUnknown*)this, &eventCookie);
  }
}

CmdEventSink::~CmdEventSink()
{
}

void CmdEventSink::DisconnectSink() {
  if (m_pIConnectionPoint) {
    m_pIConnectionPoint->Unadvise(eventCookie);
  }
}

ULONG __stdcall CmdEventSink::AddRef()
{
  return ++m_cRef;
}

ULONG __stdcall CmdEventSink::Release() {
  --m_cRef;
  if (m_cRef == 0) {
    delete this;
    return 0;
  }
  return m_cRef;
}

HRESULT __stdcall CmdEventSink::QueryInterface(REFIID riid, void** ppv)
{
  if ((riid == DIID_IGSCmdEvents) || (true)) {
    *ppv = (IGSCmdEvents*)this;
  }
  else {
    *ppv = NULL;
    return E_NOINTERFACE;
  }
  ((IUnknown*)(*ppv))->AddRef();
  return S_OK;
}

HRESULT __stdcall CmdEventSink::GetTypeInfoCount(UINT * pctinfo) {
  *pctinfo = 0;
  return S_OK;
}

HRESULT __stdcall CmdEventSink::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo) {
  *ppTInfo = NULL;
  return E_NOTIMPL;
}

HRESULT __stdcall CmdEventSink::GetIDsOfNames(REFIID riid, LPOLESTR *rgczNames, UINT cNames, LCID lcid, DISPID * rgDispId) {
  return E_NOTIMPL;
}

HRESULT __stdcall CmdEventSink::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExceptInfo, UINT *puArgErr) {
  switch (dispIdMember) {
  case 1: 
    onCommand(pDispParams->rgvarg[0].intVal);
    break;
  case 2:
    onDisconnect();
    break;
  case 3:
    onPickResult(pDispParams->rgvarg[0].bstrVal);
    break;
  case 4:
    onZoneChange(pDispParams->rgvarg[0].bstrVal, pDispParams->rgvarg[1].boolVal);
    break;
  case 5:
    onMessage(pDispParams->rgvarg[0].bstrVal);
    break;
  }
  return S_OK;
}


void __stdcall CmdEventSink::onCommand(int cmd) {
  if (onCommandEvent) {
    onCommandEvent(_owner, cmd);
  }
}

void __stdcall CmdEventSink::onDisconnect() {
  if (onDisconnectEvent) {
    onDisconnectEvent(_owner);
  }
}

HRESULT __stdcall CmdEventSink::onPickResult(BSTR xmlResult) {
  if (onPickResultEvent) {
    onPickResultEvent(_owner, xmlResult);
  }
  return S_OK;
}

HRESULT __stdcall CmdEventSink::onZoneChange(BSTR zoneName, BOOL zoneState) {
  if (onZoneChangeEvent) {
    onZoneChangeEvent(_owner, zoneName, zoneState);
  }
  return S_OK;
}

HRESULT __stdcall CmdEventSink::onMessage(BSTR message) {
  if (onMessageEvent) {
    onMessageEvent(_owner, message);
  }
  return S_OK;
}
