/*
 ============================================================================
 Name		: PayApi.h
 Author	  : 
 Version	 : 1.0
 Copyright   : Your copyright notice
 Description : CPayApi declaration
 ============================================================================
 */

#ifndef PAYAPI_H
#define PAYAPI_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include "ES_SOCK.H"
#include <MStateHandler.h>
#include <e32msgqueue.h>
#include <eikappui.h>

// CLASS DECLARATION
class CPayInfo;
class CClientEngine;
/**
 *  CPayApi
 * 
 */
class CPayApi: public CActive
{
public:
    // Constructors and destructor

    /**
     * Destructor.
     */
    ~CPayApi();

    /**
     * Two-phased constructor.
     */
    IMPORT_C static CPayApi* NewL(MStateHandler& aObserver,CEikAppUi* aAppUi);

    /**
     * Two-phased constructor.
     */
    IMPORT_C static CPayApi* NewLC(MStateHandler& aObserver,CEikAppUi* aAppUi);
    
    /*
    * IssuePayL()
    *
    *
    * Params:
    *   aPoint: 申请时提交的计费点
    *   aAttachment: 交易标识
    *   aFee: 资费
    *   aAppId: 应用id
    *   aDeveloperId: nokia 分配给开发者的id
    *
    * Returns:
    *     -
    *
    */   
    IMPORT_C void IssuePayL(const TDesC8& aPoint,const TDesC8& aAttachment,const TDesC8& aFee,
                            const TDesC8& aAppId,const TDesC8& aDeveloperId);
    
    IMPORT_C void GetPayResult(const TDesC8& aOrderId);

private:

    /**
     * Constructor for performing 1st stage construction
     */
    CPayApi(MStateHandler& aObserver,CEikAppUi* aAppUi);

    /**
     * EPOC default constructor for performing 2nd stage construction
     */
    void ConstructL();
    
protected: // from CActive
    /*!
      @function DoCancel
       
      @discussion cancel any outstanding operation
      */
    void DoCancel();

    /*!
      @function RunL
       
      @discussion called when operation complete
      */
    void RunL();    


public:
    void InitL();
    void ConnectL();
    void SendInfoL(const TDesC8& aPoint,const TDesC8& aAttachment,const TDesC8& aFee,
                   const TDesC8& aAppId,const TDesC8& aDeveloperId);
    
    CPayInfo* GetPayInfo(){return iPayInfo;}
    TDesC8& GetKey(){return iKey;}
    TDesC8& GetIv(){return iIv;}
    
private:
    void RecvInfoL();
    void IssueRead();
    TBool ParseInfo(const TDesC8& aData);   
    void CloseSocket();
    void SendToClientL(const TDesC8& aData);
    void OpenUrlL(const TDesC& aUrl);
    
private:
    RSocketServ iSocketServ;
    RSocket iSocket;
    MStateHandler& iObserver; // Used for 
    CPayInfo* iPayInfo;
    CEikAppUi* iAppUi;
    CClientEngine* iClientEngine;
    TBool iStart;
    TBuf8<256>    iBuffer;
    TBuf8<1024>   iMessage;
    TSockXfrLength iDummyLength;
    TBuf8<24> iKey;
    TBuf8<8> iIv;
    RMsgQueue< TUint8[256] > iMsgQueue;
    TUint8 iMsg[256];
};

#endif // PAYAPI_H
