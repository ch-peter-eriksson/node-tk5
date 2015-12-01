#pragma once
#include "CmdEventSink.h"

CmdEventSink::CmdEventSink(IDispatch *parent)
{
  m_cRef = 0;

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
  if (riid == DIID_IGSCmdEvents) {
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
  *rgDispId = NULL;
  return E_NOTIMPL;
}

HRESULT __stdcall CmdEventSink::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExceptInfo, UINT *puArgErr) {
  return S_OK;
}


void __stdcall CmdEventSink::onCommand(int cmd) {

}

void __stdcall CmdEventSink::onDisconnect() {

}

HRESULT __stdcall CmdEventSink::onPickResult(BSTR xmlResult) {
  return S_OK;
}

HRESULT __stdcall CmdEventSink::onZoneChange(BSTR zoneName, BOOL zoneState) {
  return S_OK;
}

HRESULT __stdcall CmdEventSink::onMessage(BSTR message) {
  return S_OK;
}
