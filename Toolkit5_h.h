

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Dec 08 21:55:07 2015
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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Toolkit5_h_h__
#define __Toolkit5_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IGSCommandList_FWD_DEFINED__
#define __IGSCommandList_FWD_DEFINED__
typedef interface IGSCommandList IGSCommandList;

#endif 	/* __IGSCommandList_FWD_DEFINED__ */


#ifndef __IGSAsyncProcessor_FWD_DEFINED__
#define __IGSAsyncProcessor_FWD_DEFINED__
typedef interface IGSAsyncProcessor IGSAsyncProcessor;

#endif 	/* __IGSAsyncProcessor_FWD_DEFINED__ */


#ifndef __IGSTitle_FWD_DEFINED__
#define __IGSTitle_FWD_DEFINED__
typedef interface IGSTitle IGSTitle;

#endif 	/* __IGSTitle_FWD_DEFINED__ */


#ifndef __IGSClient_FWD_DEFINED__
#define __IGSClient_FWD_DEFINED__
typedef interface IGSClient IGSClient;

#endif 	/* __IGSClient_FWD_DEFINED__ */


#ifndef __IGSAnimationOptions_FWD_DEFINED__
#define __IGSAnimationOptions_FWD_DEFINED__
typedef interface IGSAnimationOptions IGSAnimationOptions;

#endif 	/* __IGSAnimationOptions_FWD_DEFINED__ */


#ifndef __IGSAnimationChannel_FWD_DEFINED__
#define __IGSAnimationChannel_FWD_DEFINED__
typedef interface IGSAnimationChannel IGSAnimationChannel;

#endif 	/* __IGSAnimationChannel_FWD_DEFINED__ */


#ifndef __IGSAnimation_FWD_DEFINED__
#define __IGSAnimation_FWD_DEFINED__
typedef interface IGSAnimation IGSAnimation;

#endif 	/* __IGSAnimation_FWD_DEFINED__ */


#ifndef __IGSTitleManager_FWD_DEFINED__
#define __IGSTitleManager_FWD_DEFINED__
typedef interface IGSTitleManager IGSTitleManager;

#endif 	/* __IGSTitleManager_FWD_DEFINED__ */


#ifndef __IGSCmdEvents_FWD_DEFINED__
#define __IGSCmdEvents_FWD_DEFINED__
typedef interface IGSCmdEvents IGSCmdEvents;

#endif 	/* __IGSCmdEvents_FWD_DEFINED__ */


#ifndef __TitleManager_FWD_DEFINED__
#define __TitleManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class TitleManager TitleManager;
#else
typedef struct TitleManager TitleManager;
#endif /* __cplusplus */

#endif 	/* __TitleManager_FWD_DEFINED__ */


#ifndef __Client_FWD_DEFINED__
#define __Client_FWD_DEFINED__

#ifdef __cplusplus
typedef class Client Client;
#else
typedef struct Client Client;
#endif /* __cplusplus */

#endif 	/* __Client_FWD_DEFINED__ */


#ifndef __Animation_FWD_DEFINED__
#define __Animation_FWD_DEFINED__

#ifdef __cplusplus
typedef class Animation Animation;
#else
typedef struct Animation Animation;
#endif /* __cplusplus */

#endif 	/* __Animation_FWD_DEFINED__ */


#ifndef __CommandList_FWD_DEFINED__
#define __CommandList_FWD_DEFINED__

#ifdef __cplusplus
typedef class CommandList CommandList;
#else
typedef struct CommandList CommandList;
#endif /* __cplusplus */

#endif 	/* __CommandList_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IGSCommandList_INTERFACE_DEFINED__
#define __IGSCommandList_INTERFACE_DEFINED__

/* interface IGSCommandList */
/* [helpstring][unique][dual][uuid][object] */ 


EXTERN_C const IID IID_IGSCommandList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5704a8e7-80fb-4d40-b965-8d99b6be330a")
    IGSCommandList : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE animate( 
            VARIANT animNameOrObject,
            BSTR address,
            /* [optional] */ VARIANT options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE stopAnimation( 
            BSTR animName,
            BSTR address) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE set( 
            BSTR address,
            BSTR attrName,
            VARIANT value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE createNode( 
            BSTR nodeType,
            BSTR newAddress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE createEffect( 
            BSTR effectType,
            BSTR newAddress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE copyNode( 
            BSTR srcAddress,
            BSTR newAddress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE renameNode( 
            BSTR address,
            BSTR newName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE deleteNode( 
            BSTR address) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE deleteEffect( 
            BSTR address) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE loadScene( 
            BSTR sceneName,
            BSTR newAddress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE doAction( 
            BSTR actionName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE beginTransaction( 
            /* [optional] */ VARIANT transactionName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE endTransaction( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE rollTransaction( 
            /* [optional] */ VARIANT transactionName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE callback( 
            /* [retval][out] */ long *id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE preload( 
            BSTR address) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE beginSequencePreview( 
            int previewID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE endSequencePreview( 
            int previewID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE captureStillPreview( 
            int previewID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setZoneState( 
            BOOL state) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGSCommandListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGSCommandList * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGSCommandList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGSCommandList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGSCommandList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGSCommandList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGSCommandList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGSCommandList * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *animate )( 
            IGSCommandList * This,
            VARIANT animNameOrObject,
            BSTR address,
            /* [optional] */ VARIANT options);
        
        HRESULT ( STDMETHODCALLTYPE *stopAnimation )( 
            IGSCommandList * This,
            BSTR animName,
            BSTR address);
        
        HRESULT ( STDMETHODCALLTYPE *set )( 
            IGSCommandList * This,
            BSTR address,
            BSTR attrName,
            VARIANT value);
        
        HRESULT ( STDMETHODCALLTYPE *createNode )( 
            IGSCommandList * This,
            BSTR nodeType,
            BSTR newAddress);
        
        HRESULT ( STDMETHODCALLTYPE *createEffect )( 
            IGSCommandList * This,
            BSTR effectType,
            BSTR newAddress);
        
        HRESULT ( STDMETHODCALLTYPE *copyNode )( 
            IGSCommandList * This,
            BSTR srcAddress,
            BSTR newAddress);
        
        HRESULT ( STDMETHODCALLTYPE *renameNode )( 
            IGSCommandList * This,
            BSTR address,
            BSTR newName);
        
        HRESULT ( STDMETHODCALLTYPE *deleteNode )( 
            IGSCommandList * This,
            BSTR address);
        
        HRESULT ( STDMETHODCALLTYPE *deleteEffect )( 
            IGSCommandList * This,
            BSTR address);
        
        HRESULT ( STDMETHODCALLTYPE *loadScene )( 
            IGSCommandList * This,
            BSTR sceneName,
            BSTR newAddress);
        
        HRESULT ( STDMETHODCALLTYPE *doAction )( 
            IGSCommandList * This,
            BSTR actionName);
        
        HRESULT ( STDMETHODCALLTYPE *beginTransaction )( 
            IGSCommandList * This,
            /* [optional] */ VARIANT transactionName);
        
        HRESULT ( STDMETHODCALLTYPE *endTransaction )( 
            IGSCommandList * This);
        
        HRESULT ( STDMETHODCALLTYPE *rollTransaction )( 
            IGSCommandList * This,
            /* [optional] */ VARIANT transactionName);
        
        HRESULT ( STDMETHODCALLTYPE *callback )( 
            IGSCommandList * This,
            /* [retval][out] */ long *id);
        
        HRESULT ( STDMETHODCALLTYPE *preload )( 
            IGSCommandList * This,
            BSTR address);
        
        HRESULT ( STDMETHODCALLTYPE *beginSequencePreview )( 
            IGSCommandList * This,
            int previewID);
        
        HRESULT ( STDMETHODCALLTYPE *endSequencePreview )( 
            IGSCommandList * This,
            int previewID);
        
        HRESULT ( STDMETHODCALLTYPE *captureStillPreview )( 
            IGSCommandList * This,
            int previewID);
        
        HRESULT ( STDMETHODCALLTYPE *setZoneState )( 
            IGSCommandList * This,
            BOOL state);
        
        END_INTERFACE
    } IGSCommandListVtbl;

    interface IGSCommandList
    {
        CONST_VTBL struct IGSCommandListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGSCommandList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGSCommandList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGSCommandList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGSCommandList_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGSCommandList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGSCommandList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGSCommandList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGSCommandList_animate(This,animNameOrObject,address,options)	\
    ( (This)->lpVtbl -> animate(This,animNameOrObject,address,options) ) 

#define IGSCommandList_stopAnimation(This,animName,address)	\
    ( (This)->lpVtbl -> stopAnimation(This,animName,address) ) 

#define IGSCommandList_set(This,address,attrName,value)	\
    ( (This)->lpVtbl -> set(This,address,attrName,value) ) 

#define IGSCommandList_createNode(This,nodeType,newAddress)	\
    ( (This)->lpVtbl -> createNode(This,nodeType,newAddress) ) 

#define IGSCommandList_createEffect(This,effectType,newAddress)	\
    ( (This)->lpVtbl -> createEffect(This,effectType,newAddress) ) 

#define IGSCommandList_copyNode(This,srcAddress,newAddress)	\
    ( (This)->lpVtbl -> copyNode(This,srcAddress,newAddress) ) 

#define IGSCommandList_renameNode(This,address,newName)	\
    ( (This)->lpVtbl -> renameNode(This,address,newName) ) 

#define IGSCommandList_deleteNode(This,address)	\
    ( (This)->lpVtbl -> deleteNode(This,address) ) 

#define IGSCommandList_deleteEffect(This,address)	\
    ( (This)->lpVtbl -> deleteEffect(This,address) ) 

#define IGSCommandList_loadScene(This,sceneName,newAddress)	\
    ( (This)->lpVtbl -> loadScene(This,sceneName,newAddress) ) 

#define IGSCommandList_doAction(This,actionName)	\
    ( (This)->lpVtbl -> doAction(This,actionName) ) 

#define IGSCommandList_beginTransaction(This,transactionName)	\
    ( (This)->lpVtbl -> beginTransaction(This,transactionName) ) 

#define IGSCommandList_endTransaction(This)	\
    ( (This)->lpVtbl -> endTransaction(This) ) 

#define IGSCommandList_rollTransaction(This,transactionName)	\
    ( (This)->lpVtbl -> rollTransaction(This,transactionName) ) 

#define IGSCommandList_callback(This,id)	\
    ( (This)->lpVtbl -> callback(This,id) ) 

#define IGSCommandList_preload(This,address)	\
    ( (This)->lpVtbl -> preload(This,address) ) 

#define IGSCommandList_beginSequencePreview(This,previewID)	\
    ( (This)->lpVtbl -> beginSequencePreview(This,previewID) ) 

#define IGSCommandList_endSequencePreview(This,previewID)	\
    ( (This)->lpVtbl -> endSequencePreview(This,previewID) ) 

#define IGSCommandList_captureStillPreview(This,previewID)	\
    ( (This)->lpVtbl -> captureStillPreview(This,previewID) ) 

#define IGSCommandList_setZoneState(This,state)	\
    ( (This)->lpVtbl -> setZoneState(This,state) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGSCommandList_INTERFACE_DEFINED__ */


#ifndef __IGSAsyncProcessor_INTERFACE_DEFINED__
#define __IGSAsyncProcessor_INTERFACE_DEFINED__

/* interface IGSAsyncProcessor */
/* [unique][dual][uuid][object] */ 


EXTERN_C const IID IID_IGSAsyncProcessor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("88E5886B-99CB-4904-B726-8755D8A72C30")
    IGSAsyncProcessor : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE waitEvent( 
            /* [retval][out] */ VARIANT_BOOL *retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE process( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE close( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGSAsyncProcessorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGSAsyncProcessor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGSAsyncProcessor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGSAsyncProcessor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGSAsyncProcessor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGSAsyncProcessor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGSAsyncProcessor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGSAsyncProcessor * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *waitEvent )( 
            IGSAsyncProcessor * This,
            /* [retval][out] */ VARIANT_BOOL *retval);
        
        HRESULT ( STDMETHODCALLTYPE *process )( 
            IGSAsyncProcessor * This);
        
        HRESULT ( STDMETHODCALLTYPE *close )( 
            IGSAsyncProcessor * This);
        
        END_INTERFACE
    } IGSAsyncProcessorVtbl;

    interface IGSAsyncProcessor
    {
        CONST_VTBL struct IGSAsyncProcessorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGSAsyncProcessor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGSAsyncProcessor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGSAsyncProcessor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGSAsyncProcessor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGSAsyncProcessor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGSAsyncProcessor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGSAsyncProcessor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGSAsyncProcessor_waitEvent(This,retval)	\
    ( (This)->lpVtbl -> waitEvent(This,retval) ) 

#define IGSAsyncProcessor_process(This)	\
    ( (This)->lpVtbl -> process(This) ) 

#define IGSAsyncProcessor_close(This)	\
    ( (This)->lpVtbl -> close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGSAsyncProcessor_INTERFACE_DEFINED__ */


#ifndef __IGSTitle_INTERFACE_DEFINED__
#define __IGSTitle_INTERFACE_DEFINED__

/* interface IGSTitle */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGSTitle;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1555802a-ceb6-403b-a083-660e18f374cd")
    IGSTitle : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE setTitleName( 
            BSTR name) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE destroy( void) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE begin( void) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE end( void) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE loadScene( 
            BSTR sceneName,
            BSTR newAddress) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE createNode( 
            BSTR nodeType,
            BSTR newAddress) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE createEffect( 
            BSTR effectType,
            BSTR newAddress) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE copyNode( 
            BSTR srcAddress,
            BSTR newAddress) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE deleteNode( 
            BSTR nodeName) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE deleteEffect( 
            BSTR effectName) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE set( 
            BSTR address,
            BSTR attrName,
            VARIANT value) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE animate( 
            VARIANT animNameOrObject,
            BSTR address,
            /* [optional] */ VARIANT options) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE stopAnimation( 
            BSTR animName,
            BSTR address) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE callSceneAction( 
            BSTR actionName) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE transactionBegin( 
            VARIANT transactionName) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE transactionEnd( void) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE transactionRoll( 
            VARIANT transactionName) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE commandCallback( 
            /* [retval][out] */ long *id) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE getZone( 
            /* [retval][out] */ BSTR *name) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE setProject( 
            BSTR name) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE setDestroyTransactionName( 
            BSTR name) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE previewSchedule( 
            int previewID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE destroyInTransaction( 
            VARIANT transactionName) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE preload( 
            BSTR nodeName) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE previewScheduleBegin( 
            int previewID) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE previewScheduleEnd( 
            int previewID) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE renameNode( 
            BSTR nodeAddress,
            BSTR newNodeName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE enableZoneNotification( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE execute( 
            IGSCommandList *cmdList,
            /* [optional] */ VARIANT nodePrefix) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGSTitleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGSTitle * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGSTitle * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGSTitle * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGSTitle * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGSTitle * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGSTitle * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGSTitle * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *setTitleName )( 
            IGSTitle * This,
            BSTR name);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *destroy )( 
            IGSTitle * This);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *begin )( 
            IGSTitle * This);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *end )( 
            IGSTitle * This);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *loadScene )( 
            IGSTitle * This,
            BSTR sceneName,
            BSTR newAddress);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *createNode )( 
            IGSTitle * This,
            BSTR nodeType,
            BSTR newAddress);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *createEffect )( 
            IGSTitle * This,
            BSTR effectType,
            BSTR newAddress);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *copyNode )( 
            IGSTitle * This,
            BSTR srcAddress,
            BSTR newAddress);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *deleteNode )( 
            IGSTitle * This,
            BSTR nodeName);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *deleteEffect )( 
            IGSTitle * This,
            BSTR effectName);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *set )( 
            IGSTitle * This,
            BSTR address,
            BSTR attrName,
            VARIANT value);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *animate )( 
            IGSTitle * This,
            VARIANT animNameOrObject,
            BSTR address,
            /* [optional] */ VARIANT options);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *stopAnimation )( 
            IGSTitle * This,
            BSTR animName,
            BSTR address);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *callSceneAction )( 
            IGSTitle * This,
            BSTR actionName);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *transactionBegin )( 
            IGSTitle * This,
            VARIANT transactionName);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *transactionEnd )( 
            IGSTitle * This);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *transactionRoll )( 
            IGSTitle * This,
            VARIANT transactionName);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *commandCallback )( 
            IGSTitle * This,
            /* [retval][out] */ long *id);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *getZone )( 
            IGSTitle * This,
            /* [retval][out] */ BSTR *name);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *setProject )( 
            IGSTitle * This,
            BSTR name);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *setDestroyTransactionName )( 
            IGSTitle * This,
            BSTR name);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *previewSchedule )( 
            IGSTitle * This,
            int previewID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *destroyInTransaction )( 
            IGSTitle * This,
            VARIANT transactionName);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *preload )( 
            IGSTitle * This,
            BSTR nodeName);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *previewScheduleBegin )( 
            IGSTitle * This,
            int previewID);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *previewScheduleEnd )( 
            IGSTitle * This,
            int previewID);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *renameNode )( 
            IGSTitle * This,
            BSTR nodeAddress,
            BSTR newNodeName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *enableZoneNotification )( 
            IGSTitle * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *execute )( 
            IGSTitle * This,
            IGSCommandList *cmdList,
            /* [optional] */ VARIANT nodePrefix);
        
        END_INTERFACE
    } IGSTitleVtbl;

    interface IGSTitle
    {
        CONST_VTBL struct IGSTitleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGSTitle_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGSTitle_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGSTitle_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGSTitle_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGSTitle_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGSTitle_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGSTitle_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGSTitle_setTitleName(This,name)	\
    ( (This)->lpVtbl -> setTitleName(This,name) ) 

#define IGSTitle_destroy(This)	\
    ( (This)->lpVtbl -> destroy(This) ) 

#define IGSTitle_begin(This)	\
    ( (This)->lpVtbl -> begin(This) ) 

#define IGSTitle_end(This)	\
    ( (This)->lpVtbl -> end(This) ) 

#define IGSTitle_loadScene(This,sceneName,newAddress)	\
    ( (This)->lpVtbl -> loadScene(This,sceneName,newAddress) ) 

#define IGSTitle_createNode(This,nodeType,newAddress)	\
    ( (This)->lpVtbl -> createNode(This,nodeType,newAddress) ) 

#define IGSTitle_createEffect(This,effectType,newAddress)	\
    ( (This)->lpVtbl -> createEffect(This,effectType,newAddress) ) 

#define IGSTitle_copyNode(This,srcAddress,newAddress)	\
    ( (This)->lpVtbl -> copyNode(This,srcAddress,newAddress) ) 

#define IGSTitle_deleteNode(This,nodeName)	\
    ( (This)->lpVtbl -> deleteNode(This,nodeName) ) 

#define IGSTitle_deleteEffect(This,effectName)	\
    ( (This)->lpVtbl -> deleteEffect(This,effectName) ) 

#define IGSTitle_set(This,address,attrName,value)	\
    ( (This)->lpVtbl -> set(This,address,attrName,value) ) 

#define IGSTitle_animate(This,animNameOrObject,address,options)	\
    ( (This)->lpVtbl -> animate(This,animNameOrObject,address,options) ) 

#define IGSTitle_stopAnimation(This,animName,address)	\
    ( (This)->lpVtbl -> stopAnimation(This,animName,address) ) 

#define IGSTitle_callSceneAction(This,actionName)	\
    ( (This)->lpVtbl -> callSceneAction(This,actionName) ) 

#define IGSTitle_transactionBegin(This,transactionName)	\
    ( (This)->lpVtbl -> transactionBegin(This,transactionName) ) 

#define IGSTitle_transactionEnd(This)	\
    ( (This)->lpVtbl -> transactionEnd(This) ) 

#define IGSTitle_transactionRoll(This,transactionName)	\
    ( (This)->lpVtbl -> transactionRoll(This,transactionName) ) 

#define IGSTitle_commandCallback(This,id)	\
    ( (This)->lpVtbl -> commandCallback(This,id) ) 

#define IGSTitle_getZone(This,name)	\
    ( (This)->lpVtbl -> getZone(This,name) ) 

#define IGSTitle_setProject(This,name)	\
    ( (This)->lpVtbl -> setProject(This,name) ) 

#define IGSTitle_setDestroyTransactionName(This,name)	\
    ( (This)->lpVtbl -> setDestroyTransactionName(This,name) ) 

#define IGSTitle_previewSchedule(This,previewID)	\
    ( (This)->lpVtbl -> previewSchedule(This,previewID) ) 

#define IGSTitle_destroyInTransaction(This,transactionName)	\
    ( (This)->lpVtbl -> destroyInTransaction(This,transactionName) ) 

#define IGSTitle_preload(This,nodeName)	\
    ( (This)->lpVtbl -> preload(This,nodeName) ) 

#define IGSTitle_previewScheduleBegin(This,previewID)	\
    ( (This)->lpVtbl -> previewScheduleBegin(This,previewID) ) 

#define IGSTitle_previewScheduleEnd(This,previewID)	\
    ( (This)->lpVtbl -> previewScheduleEnd(This,previewID) ) 

#define IGSTitle_renameNode(This,nodeAddress,newNodeName)	\
    ( (This)->lpVtbl -> renameNode(This,nodeAddress,newNodeName) ) 

#define IGSTitle_enableZoneNotification(This)	\
    ( (This)->lpVtbl -> enableZoneNotification(This) ) 

#define IGSTitle_execute(This,cmdList,nodePrefix)	\
    ( (This)->lpVtbl -> execute(This,cmdList,nodePrefix) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGSTitle_INTERFACE_DEFINED__ */


#ifndef __IGSClient_INTERFACE_DEFINED__
#define __IGSClient_INTERFACE_DEFINED__

/* interface IGSClient */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGSClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d1a4f8f0-d3c6-11e0-9572-0800200c9a66")
    IGSClient : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE setServerAddress( 
            BSTR hostname) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE connect( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE disconnect( void) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE setZoneState( 
            BSTR zoneName,
            BOOL state) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE getZoneState( 
            BSTR zoneName,
            /* [retval][out] */ BOOL *state) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE getServerVersion( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE switchCamera( 
            BSTR cameraName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE previewGenerateID( 
            /* [retval][out] */ int *previewID) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE previewSchedule( 
            int previewID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE previewGetStillImageFile( 
            int previewID,
            BSTR fileName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE writeRenderPicture( void) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_onDisconnectListener( 
            IDispatch *handler) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE previewGetSequenceImageFiles( 
            int previewID,
            BSTR fileName,
            /* [retval][out] */ int *numberOfImages) = 0;
        
        virtual /* [hidden][propput][id] */ HRESULT STDMETHODCALLTYPE put_onPickResultListener( 
            IDispatch *handler) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE sendPickRequest( 
            float x,
            float y) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE getServerAddress( 
            /* [retval][out] */ BSTR *hostname) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE sendPickRequestTag( 
            BSTR tagName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE writeScene( void) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_onMessageListener( 
            IDispatch *handler) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE roaSet( 
            BSTR object,
            BSTR field,
            VARIANT value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE roaGet( 
            BSTR object,
            BSTR field,
            /* [retval][out] */ VARIANT *value) = 0;
        
        virtual /* [vararg] */ HRESULT STDMETHODCALLTYPE roaCall( 
            BSTR object,
            BSTR funcName,
            SAFEARRAY * args,
            /* [retval][out] */ VARIANT *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setPassword( 
            BSTR password) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE createAsyncProcessor( 
            /* [retval][out] */ IGSAsyncProcessor **processor) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGSClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGSClient * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGSClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGSClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGSClient * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGSClient * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGSClient * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGSClient * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *setServerAddress )( 
            IGSClient * This,
            BSTR hostname);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *connect )( 
            IGSClient * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *disconnect )( 
            IGSClient * This);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *setZoneState )( 
            IGSClient * This,
            BSTR zoneName,
            BOOL state);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *getZoneState )( 
            IGSClient * This,
            BSTR zoneName,
            /* [retval][out] */ BOOL *state);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *getServerVersion )( 
            IGSClient * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *switchCamera )( 
            IGSClient * This,
            BSTR cameraName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *previewGenerateID )( 
            IGSClient * This,
            /* [retval][out] */ int *previewID);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *previewSchedule )( 
            IGSClient * This,
            int previewID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *previewGetStillImageFile )( 
            IGSClient * This,
            int previewID,
            BSTR fileName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *writeRenderPicture )( 
            IGSClient * This);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_onDisconnectListener )( 
            IGSClient * This,
            IDispatch *handler);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *previewGetSequenceImageFiles )( 
            IGSClient * This,
            int previewID,
            BSTR fileName,
            /* [retval][out] */ int *numberOfImages);
        
        /* [hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_onPickResultListener )( 
            IGSClient * This,
            IDispatch *handler);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *sendPickRequest )( 
            IGSClient * This,
            float x,
            float y);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *getServerAddress )( 
            IGSClient * This,
            /* [retval][out] */ BSTR *hostname);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *sendPickRequestTag )( 
            IGSClient * This,
            BSTR tagName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *writeScene )( 
            IGSClient * This);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_onMessageListener )( 
            IGSClient * This,
            IDispatch *handler);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *roaSet )( 
            IGSClient * This,
            BSTR object,
            BSTR field,
            VARIANT value);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *roaGet )( 
            IGSClient * This,
            BSTR object,
            BSTR field,
            /* [retval][out] */ VARIANT *value);
        
        /* [vararg] */ HRESULT ( STDMETHODCALLTYPE *roaCall )( 
            IGSClient * This,
            BSTR object,
            BSTR funcName,
            SAFEARRAY * args,
            /* [retval][out] */ VARIANT *result);
        
        HRESULT ( STDMETHODCALLTYPE *setPassword )( 
            IGSClient * This,
            BSTR password);
        
        HRESULT ( STDMETHODCALLTYPE *createAsyncProcessor )( 
            IGSClient * This,
            /* [retval][out] */ IGSAsyncProcessor **processor);
        
        END_INTERFACE
    } IGSClientVtbl;

    interface IGSClient
    {
        CONST_VTBL struct IGSClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGSClient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGSClient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGSClient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGSClient_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGSClient_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGSClient_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGSClient_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGSClient_setServerAddress(This,hostname)	\
    ( (This)->lpVtbl -> setServerAddress(This,hostname) ) 

#define IGSClient_connect(This)	\
    ( (This)->lpVtbl -> connect(This) ) 

#define IGSClient_disconnect(This)	\
    ( (This)->lpVtbl -> disconnect(This) ) 

#define IGSClient_setZoneState(This,zoneName,state)	\
    ( (This)->lpVtbl -> setZoneState(This,zoneName,state) ) 

#define IGSClient_getZoneState(This,zoneName,state)	\
    ( (This)->lpVtbl -> getZoneState(This,zoneName,state) ) 

#define IGSClient_getServerVersion(This,pVal)	\
    ( (This)->lpVtbl -> getServerVersion(This,pVal) ) 

#define IGSClient_switchCamera(This,cameraName)	\
    ( (This)->lpVtbl -> switchCamera(This,cameraName) ) 

#define IGSClient_previewGenerateID(This,previewID)	\
    ( (This)->lpVtbl -> previewGenerateID(This,previewID) ) 

#define IGSClient_previewSchedule(This,previewID)	\
    ( (This)->lpVtbl -> previewSchedule(This,previewID) ) 

#define IGSClient_previewGetStillImageFile(This,previewID,fileName)	\
    ( (This)->lpVtbl -> previewGetStillImageFile(This,previewID,fileName) ) 

#define IGSClient_writeRenderPicture(This)	\
    ( (This)->lpVtbl -> writeRenderPicture(This) ) 

#define IGSClient_put_onDisconnectListener(This,handler)	\
    ( (This)->lpVtbl -> put_onDisconnectListener(This,handler) ) 

#define IGSClient_previewGetSequenceImageFiles(This,previewID,fileName,numberOfImages)	\
    ( (This)->lpVtbl -> previewGetSequenceImageFiles(This,previewID,fileName,numberOfImages) ) 

#define IGSClient_put_onPickResultListener(This,handler)	\
    ( (This)->lpVtbl -> put_onPickResultListener(This,handler) ) 

#define IGSClient_sendPickRequest(This,x,y)	\
    ( (This)->lpVtbl -> sendPickRequest(This,x,y) ) 

#define IGSClient_getServerAddress(This,hostname)	\
    ( (This)->lpVtbl -> getServerAddress(This,hostname) ) 

#define IGSClient_sendPickRequestTag(This,tagName)	\
    ( (This)->lpVtbl -> sendPickRequestTag(This,tagName) ) 

#define IGSClient_writeScene(This)	\
    ( (This)->lpVtbl -> writeScene(This) ) 

#define IGSClient_put_onMessageListener(This,handler)	\
    ( (This)->lpVtbl -> put_onMessageListener(This,handler) ) 

#define IGSClient_roaSet(This,object,field,value)	\
    ( (This)->lpVtbl -> roaSet(This,object,field,value) ) 

#define IGSClient_roaGet(This,object,field,value)	\
    ( (This)->lpVtbl -> roaGet(This,object,field,value) ) 

#define IGSClient_roaCall(This,object,funcName,args,result)	\
    ( (This)->lpVtbl -> roaCall(This,object,funcName,args,result) ) 

#define IGSClient_setPassword(This,password)	\
    ( (This)->lpVtbl -> setPassword(This,password) ) 

#define IGSClient_createAsyncProcessor(This,processor)	\
    ( (This)->lpVtbl -> createAsyncProcessor(This,processor) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGSClient_INTERFACE_DEFINED__ */


#ifndef __IGSAnimationOptions_INTERFACE_DEFINED__
#define __IGSAnimationOptions_INTERFACE_DEFINED__

/* interface IGSAnimationOptions */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGSAnimationOptions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("613903EE-277F-48FE-8208-A93225869AB2")
    IGSAnimationOptions : public IDispatch
    {
    public:
        virtual /* [id][hidden] */ HRESULT STDMETHODCALLTYPE getNative( 
            /* [out] */ int **__MIDL__IGSAnimationOptions0000) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_offset( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_offset( 
            float newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_skip( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_skip( 
            float newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_end( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_end( 
            float newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_playMode( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_playMode( 
            BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_enableFinish( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_enableFinish( 
            BOOL newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_name( 
            BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_watchID( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_watchID( 
            int newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGSAnimationOptionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGSAnimationOptions * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGSAnimationOptions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGSAnimationOptions * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGSAnimationOptions * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGSAnimationOptions * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGSAnimationOptions * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGSAnimationOptions * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id][hidden] */ HRESULT ( STDMETHODCALLTYPE *getNative )( 
            IGSAnimationOptions * This,
            /* [out] */ int **__MIDL__IGSAnimationOptions0000);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_offset )( 
            IGSAnimationOptions * This,
            /* [retval][out] */ float *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_offset )( 
            IGSAnimationOptions * This,
            float newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_skip )( 
            IGSAnimationOptions * This,
            /* [retval][out] */ float *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_skip )( 
            IGSAnimationOptions * This,
            float newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_end )( 
            IGSAnimationOptions * This,
            /* [retval][out] */ float *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_end )( 
            IGSAnimationOptions * This,
            float newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_playMode )( 
            IGSAnimationOptions * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_playMode )( 
            IGSAnimationOptions * This,
            BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_enableFinish )( 
            IGSAnimationOptions * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_enableFinish )( 
            IGSAnimationOptions * This,
            BOOL newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_name )( 
            IGSAnimationOptions * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_name )( 
            IGSAnimationOptions * This,
            BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_watchID )( 
            IGSAnimationOptions * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_watchID )( 
            IGSAnimationOptions * This,
            int newVal);
        
        END_INTERFACE
    } IGSAnimationOptionsVtbl;

    interface IGSAnimationOptions
    {
        CONST_VTBL struct IGSAnimationOptionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGSAnimationOptions_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGSAnimationOptions_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGSAnimationOptions_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGSAnimationOptions_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGSAnimationOptions_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGSAnimationOptions_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGSAnimationOptions_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGSAnimationOptions_getNative(This,__MIDL__IGSAnimationOptions0000)	\
    ( (This)->lpVtbl -> getNative(This,__MIDL__IGSAnimationOptions0000) ) 

#define IGSAnimationOptions_get_offset(This,pVal)	\
    ( (This)->lpVtbl -> get_offset(This,pVal) ) 

#define IGSAnimationOptions_put_offset(This,newVal)	\
    ( (This)->lpVtbl -> put_offset(This,newVal) ) 

#define IGSAnimationOptions_get_skip(This,pVal)	\
    ( (This)->lpVtbl -> get_skip(This,pVal) ) 

#define IGSAnimationOptions_put_skip(This,newVal)	\
    ( (This)->lpVtbl -> put_skip(This,newVal) ) 

#define IGSAnimationOptions_get_end(This,pVal)	\
    ( (This)->lpVtbl -> get_end(This,pVal) ) 

#define IGSAnimationOptions_put_end(This,newVal)	\
    ( (This)->lpVtbl -> put_end(This,newVal) ) 

#define IGSAnimationOptions_get_playMode(This,pVal)	\
    ( (This)->lpVtbl -> get_playMode(This,pVal) ) 

#define IGSAnimationOptions_put_playMode(This,newVal)	\
    ( (This)->lpVtbl -> put_playMode(This,newVal) ) 

#define IGSAnimationOptions_get_enableFinish(This,pVal)	\
    ( (This)->lpVtbl -> get_enableFinish(This,pVal) ) 

#define IGSAnimationOptions_put_enableFinish(This,newVal)	\
    ( (This)->lpVtbl -> put_enableFinish(This,newVal) ) 

#define IGSAnimationOptions_get_name(This,pVal)	\
    ( (This)->lpVtbl -> get_name(This,pVal) ) 

#define IGSAnimationOptions_put_name(This,newVal)	\
    ( (This)->lpVtbl -> put_name(This,newVal) ) 

#define IGSAnimationOptions_get_watchID(This,pVal)	\
    ( (This)->lpVtbl -> get_watchID(This,pVal) ) 

#define IGSAnimationOptions_put_watchID(This,newVal)	\
    ( (This)->lpVtbl -> put_watchID(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGSAnimationOptions_INTERFACE_DEFINED__ */


#ifndef __IGSAnimationChannel_INTERFACE_DEFINED__
#define __IGSAnimationChannel_INTERFACE_DEFINED__

/* interface IGSAnimationChannel */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGSAnimationChannel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("352C3290-110B-401C-A696-48D41588DFA6")
    IGSAnimationChannel : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_destination( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_destination( 
            BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_after( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_after( 
            BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_before( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_before( 
            BSTR newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE addKeyframe( 
            float time,
            float value,
            BSTR inInterpolation,
            BSTR outInterpolation) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE addKeyframeWithTangents( 
            float time,
            float value,
            BSTR inInterpolation,
            BSTR outInterpolation,
            float inTanX,
            float inTanY,
            float outTanX,
            float outTanY) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGSAnimationChannelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGSAnimationChannel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGSAnimationChannel * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGSAnimationChannel * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGSAnimationChannel * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGSAnimationChannel * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGSAnimationChannel * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGSAnimationChannel * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_destination )( 
            IGSAnimationChannel * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_destination )( 
            IGSAnimationChannel * This,
            BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_after )( 
            IGSAnimationChannel * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_after )( 
            IGSAnimationChannel * This,
            BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_before )( 
            IGSAnimationChannel * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_before )( 
            IGSAnimationChannel * This,
            BSTR newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *addKeyframe )( 
            IGSAnimationChannel * This,
            float time,
            float value,
            BSTR inInterpolation,
            BSTR outInterpolation);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *addKeyframeWithTangents )( 
            IGSAnimationChannel * This,
            float time,
            float value,
            BSTR inInterpolation,
            BSTR outInterpolation,
            float inTanX,
            float inTanY,
            float outTanX,
            float outTanY);
        
        END_INTERFACE
    } IGSAnimationChannelVtbl;

    interface IGSAnimationChannel
    {
        CONST_VTBL struct IGSAnimationChannelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGSAnimationChannel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGSAnimationChannel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGSAnimationChannel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGSAnimationChannel_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGSAnimationChannel_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGSAnimationChannel_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGSAnimationChannel_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGSAnimationChannel_get_destination(This,pVal)	\
    ( (This)->lpVtbl -> get_destination(This,pVal) ) 

#define IGSAnimationChannel_put_destination(This,newVal)	\
    ( (This)->lpVtbl -> put_destination(This,newVal) ) 

#define IGSAnimationChannel_get_after(This,pVal)	\
    ( (This)->lpVtbl -> get_after(This,pVal) ) 

#define IGSAnimationChannel_put_after(This,newVal)	\
    ( (This)->lpVtbl -> put_after(This,newVal) ) 

#define IGSAnimationChannel_get_before(This,pVal)	\
    ( (This)->lpVtbl -> get_before(This,pVal) ) 

#define IGSAnimationChannel_put_before(This,newVal)	\
    ( (This)->lpVtbl -> put_before(This,newVal) ) 

#define IGSAnimationChannel_addKeyframe(This,time,value,inInterpolation,outInterpolation)	\
    ( (This)->lpVtbl -> addKeyframe(This,time,value,inInterpolation,outInterpolation) ) 

#define IGSAnimationChannel_addKeyframeWithTangents(This,time,value,inInterpolation,outInterpolation,inTanX,inTanY,outTanX,outTanY)	\
    ( (This)->lpVtbl -> addKeyframeWithTangents(This,time,value,inInterpolation,outInterpolation,inTanX,inTanY,outTanX,outTanY) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGSAnimationChannel_INTERFACE_DEFINED__ */


#ifndef __IGSAnimation_INTERFACE_DEFINED__
#define __IGSAnimation_INTERFACE_DEFINED__

/* interface IGSAnimation */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGSAnimation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("282B87AD-135C-4447-9E1C-F5D58E165044")
    IGSAnimation : public IDispatch
    {
    public:
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE getNative( 
            /* [out] */ int **__MIDL__IGSAnimation0000) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE createChannel( 
            /* [retval][out] */ IGSAnimationChannel **channel) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGSAnimationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGSAnimation * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGSAnimation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGSAnimation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGSAnimation * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGSAnimation * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGSAnimation * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGSAnimation * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *getNative )( 
            IGSAnimation * This,
            /* [out] */ int **__MIDL__IGSAnimation0000);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *createChannel )( 
            IGSAnimation * This,
            /* [retval][out] */ IGSAnimationChannel **channel);
        
        END_INTERFACE
    } IGSAnimationVtbl;

    interface IGSAnimation
    {
        CONST_VTBL struct IGSAnimationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGSAnimation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGSAnimation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGSAnimation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGSAnimation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGSAnimation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGSAnimation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGSAnimation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGSAnimation_getNative(This,__MIDL__IGSAnimation0000)	\
    ( (This)->lpVtbl -> getNative(This,__MIDL__IGSAnimation0000) ) 

#define IGSAnimation_createChannel(This,channel)	\
    ( (This)->lpVtbl -> createChannel(This,channel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGSAnimation_INTERFACE_DEFINED__ */


#ifndef __IGSTitleManager_INTERFACE_DEFINED__
#define __IGSTitleManager_INTERFACE_DEFINED__

/* interface IGSTitleManager */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGSTitleManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C465EB7-C811-4C96-8CD2-F866391E3C91")
    IGSTitleManager : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE setProject( 
            BSTR name) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE createTitle( 
            /* [optional] */ VARIANT zoneName,
            /* [retval][out] */ IGSTitle **title) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE getClient( 
            /* [retval][out] */ IGSClient **client) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE addCommandCallbackListener( 
            IDispatch *handler) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_onCommandCallback( 
            IDispatch *handler) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE createAnimation( 
            /* [retval][out] */ IGSAnimation **anim) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE createAnimationOptions( 
            /* [retval][out] */ IGSAnimationOptions **anim) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE findTitleByZone( 
            BSTR zoneName,
            /* [retval][out] */ IGSTitle **title) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE findTitleByName( 
            BSTR titleName,
            /* [retval][out] */ IGSTitle **title) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE createTitleInChannel( 
            BSTR zoneName,
            int channelID,
            /* [retval][out] */ IGSTitle **title) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE getToolkitVersion( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE createCommandList( 
            /* [retval][out] */ IGSCommandList **cmdList) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGSTitleManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGSTitleManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGSTitleManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGSTitleManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGSTitleManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGSTitleManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGSTitleManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGSTitleManager * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *setProject )( 
            IGSTitleManager * This,
            BSTR name);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *createTitle )( 
            IGSTitleManager * This,
            /* [optional] */ VARIANT zoneName,
            /* [retval][out] */ IGSTitle **title);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *getClient )( 
            IGSTitleManager * This,
            /* [retval][out] */ IGSClient **client);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *addCommandCallbackListener )( 
            IGSTitleManager * This,
            IDispatch *handler);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_onCommandCallback )( 
            IGSTitleManager * This,
            IDispatch *handler);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *createAnimation )( 
            IGSTitleManager * This,
            /* [retval][out] */ IGSAnimation **anim);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *createAnimationOptions )( 
            IGSTitleManager * This,
            /* [retval][out] */ IGSAnimationOptions **anim);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *findTitleByZone )( 
            IGSTitleManager * This,
            BSTR zoneName,
            /* [retval][out] */ IGSTitle **title);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *findTitleByName )( 
            IGSTitleManager * This,
            BSTR titleName,
            /* [retval][out] */ IGSTitle **title);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *createTitleInChannel )( 
            IGSTitleManager * This,
            BSTR zoneName,
            int channelID,
            /* [retval][out] */ IGSTitle **title);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *getToolkitVersion )( 
            IGSTitleManager * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *createCommandList )( 
            IGSTitleManager * This,
            /* [retval][out] */ IGSCommandList **cmdList);
        
        END_INTERFACE
    } IGSTitleManagerVtbl;

    interface IGSTitleManager
    {
        CONST_VTBL struct IGSTitleManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGSTitleManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGSTitleManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGSTitleManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGSTitleManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGSTitleManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGSTitleManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGSTitleManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGSTitleManager_setProject(This,name)	\
    ( (This)->lpVtbl -> setProject(This,name) ) 

#define IGSTitleManager_createTitle(This,zoneName,title)	\
    ( (This)->lpVtbl -> createTitle(This,zoneName,title) ) 

#define IGSTitleManager_getClient(This,client)	\
    ( (This)->lpVtbl -> getClient(This,client) ) 

#define IGSTitleManager_addCommandCallbackListener(This,handler)	\
    ( (This)->lpVtbl -> addCommandCallbackListener(This,handler) ) 

#define IGSTitleManager_put_onCommandCallback(This,handler)	\
    ( (This)->lpVtbl -> put_onCommandCallback(This,handler) ) 

#define IGSTitleManager_createAnimation(This,anim)	\
    ( (This)->lpVtbl -> createAnimation(This,anim) ) 

#define IGSTitleManager_createAnimationOptions(This,anim)	\
    ( (This)->lpVtbl -> createAnimationOptions(This,anim) ) 

#define IGSTitleManager_findTitleByZone(This,zoneName,title)	\
    ( (This)->lpVtbl -> findTitleByZone(This,zoneName,title) ) 

#define IGSTitleManager_findTitleByName(This,titleName,title)	\
    ( (This)->lpVtbl -> findTitleByName(This,titleName,title) ) 

#define IGSTitleManager_createTitleInChannel(This,zoneName,channelID,title)	\
    ( (This)->lpVtbl -> createTitleInChannel(This,zoneName,channelID,title) ) 

#define IGSTitleManager_getToolkitVersion(This,pVal)	\
    ( (This)->lpVtbl -> getToolkitVersion(This,pVal) ) 

#define IGSTitleManager_createCommandList(This,cmdList)	\
    ( (This)->lpVtbl -> createCommandList(This,cmdList) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGSTitleManager_INTERFACE_DEFINED__ */



#ifndef __GSTK5Lib_LIBRARY_DEFINED__
#define __GSTK5Lib_LIBRARY_DEFINED__

/* library GSTK5Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_GSTK5Lib;

#ifndef __IGSCmdEvents_DISPINTERFACE_DEFINED__
#define __IGSCmdEvents_DISPINTERFACE_DEFINED__

/* dispinterface IGSCmdEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_IGSCmdEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("59345D3D-0651-4851-A884-DA263217A02B")
    IGSCmdEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IGSCmdEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGSCmdEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGSCmdEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGSCmdEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGSCmdEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGSCmdEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGSCmdEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGSCmdEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IGSCmdEventsVtbl;

    interface IGSCmdEvents
    {
        CONST_VTBL struct IGSCmdEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGSCmdEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGSCmdEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGSCmdEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGSCmdEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGSCmdEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGSCmdEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGSCmdEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IGSCmdEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TitleManager;

#ifdef __cplusplus

class DECLSPEC_UUID("101B34A5-C886-4249-9E7E-17D3B1A673B7")
TitleManager;
#endif

EXTERN_C const CLSID CLSID_Client;

#ifdef __cplusplus

class DECLSPEC_UUID("42BA7776-2B09-4D12-A498-7D0AF2850621")
Client;
#endif

EXTERN_C const CLSID CLSID_Animation;

#ifdef __cplusplus

class DECLSPEC_UUID("A15E8E2F-B1D1-49DF-922B-D9DA64A597BE")
Animation;
#endif

EXTERN_C const CLSID CLSID_CommandList;

#ifdef __cplusplus

class DECLSPEC_UUID("254f640e-8586-4dca-b134-ca7cd5b30a9b")
CommandList;
#endif
#endif /* __GSTK5Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


