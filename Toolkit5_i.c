

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Nov 26 15:24:03 2015
 */
/* Compiler settings for ..\Toolkit5.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IGSCommandList,0x5704a8e7,0x80fb,0x4d40,0xb9,0x65,0x8d,0x99,0xb6,0xbe,0x33,0x0a);


MIDL_DEFINE_GUID(IID, IID_IGSAsyncProcessor,0x88E5886B,0x99CB,0x4904,0xB7,0x26,0x87,0x55,0xD8,0xA7,0x2C,0x30);


MIDL_DEFINE_GUID(IID, IID_IGSTitle,0x1555802a,0xceb6,0x403b,0xa0,0x83,0x66,0x0e,0x18,0xf3,0x74,0xcd);


MIDL_DEFINE_GUID(IID, IID_IGSClient,0xd1a4f8f0,0xd3c6,0x11e0,0x95,0x72,0x08,0x00,0x20,0x0c,0x9a,0x66);


MIDL_DEFINE_GUID(IID, IID_IGSAnimationOptions,0x613903EE,0x277F,0x48FE,0x82,0x08,0xA9,0x32,0x25,0x86,0x9A,0xB2);


MIDL_DEFINE_GUID(IID, IID_IGSAnimationChannel,0x352C3290,0x110B,0x401C,0xA6,0x96,0x48,0xD4,0x15,0x88,0xDF,0xA6);


MIDL_DEFINE_GUID(IID, IID_IGSAnimation,0x282B87AD,0x135C,0x4447,0x9E,0x1C,0xF5,0xD5,0x8E,0x16,0x50,0x44);


MIDL_DEFINE_GUID(IID, IID_IGSTitleManager,0x3C465EB7,0xC811,0x4C96,0x8C,0xD2,0xF8,0x66,0x39,0x1E,0x3C,0x91);


MIDL_DEFINE_GUID(IID, LIBID_GSTK5Lib,0xA5C1DDCF,0x7F92,0x4BC4,0x87,0xD3,0x8D,0x64,0x8A,0x78,0x13,0xC9);


MIDL_DEFINE_GUID(IID, DIID_IGSCmdEvents,0x59345D3D,0x0651,0x4851,0xA8,0x84,0xDA,0x26,0x32,0x17,0xA0,0x2B);


MIDL_DEFINE_GUID(CLSID, CLSID_TitleManager,0x101B34A5,0xC886,0x4249,0x9E,0x7E,0x17,0xD3,0xB1,0xA6,0x73,0xB7);


MIDL_DEFINE_GUID(CLSID, CLSID_Client,0x42BA7776,0x2B09,0x4D12,0xA4,0x98,0x7D,0x0A,0xF2,0x85,0x06,0x21);


MIDL_DEFINE_GUID(CLSID, CLSID_Animation,0xA15E8E2F,0xB1D1,0x49DF,0x92,0x2B,0xD9,0xDA,0x64,0xA5,0x97,0xBE);


MIDL_DEFINE_GUID(CLSID, CLSID_CommandList,0x254f640e,0x8586,0x4dca,0xb1,0x34,0xca,0x7c,0xd5,0xb3,0x0a,0x9b);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



