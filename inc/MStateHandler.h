#ifndef MSTATEHANDLER_H_
#define MSTATEHANDLER_H_

typedef struct
{
    TBuf8<10> aOrderId;
    TInt aPayResult;
    TInt aErrorCode;   
    TBuf8<256> aMDesc;
}PAY_RESULT;

/*
 * MStateHandler
 * CPayApi passes events and responses result data with this interface.
 * An instance of this class must be provided for construction of CPayApi.
 */
class MStateHandler
{
public:
    /**
     * ClientEvent()
     *
     * Called when event occurs in CPayApi.
     *
     * Params:
     *   aEventDescription: A event in textual format, e.g. "Transaction Successful"
     *                                                       
     *
     * Returns:
     *   -
     *
     */
    virtual void ClientEvent(const TDesC& aEventDescription) = 0;

    /**
     * PayResult()
     *
     * Called when event occurs in CPayApi.
     *
     * Params:
     *   aResult: the result data received. 
     *                                       
     *
     * Returns:
     *   -
     *
     */
    virtual void PayResult(PAY_RESULT& aPayResult) = 0;
};
#endif /*MSTATEHANDLER_H_*/
