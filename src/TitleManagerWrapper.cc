#include "TitleManagerWrapper.h"

using namespace v8;
using namespace std;

TitleManagerWrapper::TitleManagerWrapper()
{
  CoInitialize(NULL);
  HRESULT hr = CoCreateInstance(CLSID_TitleManager, NULL, CLSCTX_ALL, IID_IGSTitleManager, (void **)&ptm);
  eventSink = new CmdEventSink((IDispatch*)ptm);
  hr = ptm->QueryInterface(IID_ISupportErrorInfo, (void **)&supportErrorInfo);
  if SUCCEEDED(hr) {
    hr = supportErrorInfo->InterfaceSupportsErrorInfo(IID_IGSTitleManager);
  }
}

TitleManagerWrapper::~TitleManagerWrapper()
{
  if (ptm) {
    if (eventSink) {
      eventSink->DisconnectSink();
      eventSink = NULL;
    }

    ptm->Release();
    CoUninitialize();
  }
}
