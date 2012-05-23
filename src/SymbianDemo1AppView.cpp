/*
 ============================================================================
 Name		: SymbianDemo1AppView.cpp
 Author	  : 
 Copyright   : Your copyright notice
 Description : Application view implementation
 ============================================================================
 */

// INCLUDE FILES
#include <coemain.h>
#include "SymbianDemo1AppView.h"
_LIT( KPaidFileName, "5.txt");
const TUint appId = 100;
extern void AppendInt32ToStreamL(RFs& aFs,
			const TDesC& aFileName, TInt32 aValue);

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CSymbianDemo1AppView::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CSymbianDemo1AppView* CSymbianDemo1AppView::NewL(const TRect& aRect)
	{
	CSymbianDemo1AppView* self = CSymbianDemo1AppView::NewLC(aRect);
	CleanupStack::Pop(self);
	return self;
	}

// -----------------------------------------------------------------------------
// CSymbianDemo1AppView::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CSymbianDemo1AppView* CSymbianDemo1AppView::NewLC(const TRect& aRect)
	{
	CSymbianDemo1AppView* self = new (ELeave) CSymbianDemo1AppView;
	CleanupStack::PushL(self);
	self->ConstructL(aRect);
	return self;
	}

// -----------------------------------------------------------------------------
// CSymbianDemo1AppView::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CSymbianDemo1AppView::ConstructL(const TRect& aRect)
	{
	// Create a window for this application view
	CreateWindowL();

	// Set the windows size
	SetRect(aRect);

	// Activate the window, which makes it ready to be drawn
	ActivateL();
	}

// -----------------------------------------------------------------------------
// CSymbianDemo1AppView::CSymbianDemo1AppView()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CSymbianDemo1AppView::CSymbianDemo1AppView()
	{
	// No implementation required
	}

// -----------------------------------------------------------------------------
// CSymbianDemo1AppView::~CSymbianDemo1AppView()
// Destructor.
// -----------------------------------------------------------------------------
//
CSymbianDemo1AppView::~CSymbianDemo1AppView()
	{
	// No implementation required
	}

// -----------------------------------------------------------------------------
// CSymbianDemo1AppView::Draw()
// Draws the display.
// -----------------------------------------------------------------------------
//
void CSymbianDemo1AppView::Draw(const TRect& /*aRect*/) const
	{
	// Get the standard graphics context
	CWindowGc& gc = SystemGc();

	// Gets the control's extent
	TRect drawRect(Rect());

	// Clears the screen
	gc.Clear(drawRect);

	}

// -----------------------------------------------------------------------------
// CSymbianDemo1AppView::SizeChanged()
// Called by framework when the view size is changed.
// -----------------------------------------------------------------------------
//
void CSymbianDemo1AppView::SizeChanged()
	{
	DrawNow();
	}

// -----------------------------------------------------------------------------
// CSymbianDemo1AppView::HandlePointerEventL()
// Called by framework to handle pointer touch events.
// Note: although this method is compatible with earlier SDKs, 
// it will not be called in SDKs without Touch support.
// -----------------------------------------------------------------------------
//
void CSymbianDemo1AppView::HandlePointerEventL(
		const TPointerEvent& aPointerEvent)
	{

	// Call base class HandlePointerEventL()
	CCoeControl::HandlePointerEventL(aPointerEvent);
	}


void CSymbianDemo1AppView::ClientEvent(const TDesC& aEventDescription)
{
//	TBuf<32> buf;
//	buf.Format(_L("ClientEvent"));
//	iEikonEnv->AlertWin(buf);
}

void CSymbianDemo1AppView::PayResult(PAY_RESULT& aResult)
{
    //save successful paid status to file
//  if(aResult.aPayResult == 1 || aResult.aPayResult == 2)
    {
    	AppendInt32ToStreamL(CCoeEnv::Static()->FsSession(), KPaidFileName, appId);
    }
   
    
//    TBuf<32> buf;
//	buf.Format(_L("ClientEvent"));
//    iEikonEnv->AlertWin(buf);
}
// End of File
	
