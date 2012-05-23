/*
 ============================================================================
 Name		: SymbianDemo1AppView.h
 Author	  : 
 Copyright   : Your copyright notice
 Description : Declares view class for application.
 ============================================================================
 */

#ifndef __SYMBIANDEMO1APPVIEW_h__
#define __SYMBIANDEMO1APPVIEW_h__

// INCLUDES
#include <coecntrl.h>
#include <MStateHandler.h>

// CLASS DECLARATION
class CSymbianDemo1AppView : public CCoeControl, public MStateHandler
	{
public:
	// New methods

	/**
	 * NewL.
	 * Two-phased constructor.
	 * Create a CSymbianDemo1AppView object, which will draw itself to aRect.
	 * @param aRect The rectangle this view will be drawn to.
	 * @return a pointer to the created instance of CSymbianDemo1AppView.
	 */
	static CSymbianDemo1AppView* NewL(const TRect& aRect);

	/**
	 * NewLC.
	 * Two-phased constructor.
	 * Create a CSymbianDemo1AppView object, which will draw itself
	 * to aRect.
	 * @param aRect Rectangle this view will be drawn to.
	 * @return A pointer to the created instance of CSymbianDemo1AppView.
	 */
	static CSymbianDemo1AppView* NewLC(const TRect& aRect);

	/**
	 * ~CSymbianDemo1AppView
	 * Virtual Destructor.
	 */
	virtual ~CSymbianDemo1AppView();

public:
	// Functions from base classes

	/**
	 * From CCoeControl, Draw
	 * Draw this CSymbianDemo1AppView to the screen.
	 * @param aRect the rectangle of this view that needs updating
	 */
	void Draw(const TRect& aRect) const;

	/**
	 * From CoeControl, SizeChanged.
	 * Called by framework when the view size is changed.
	 */
	virtual void SizeChanged();

	/**
	 * From CoeControl, HandlePointerEventL.
	 * Called by framework when a pointer touch event occurs.
	 * Note: although this method is compatible with earlier SDKs, 
	 * it will not be called in SDKs without Touch support.
	 * @param aPointerEvent the information about this event
	 */
	virtual void HandlePointerEventL(const TPointerEvent& aPointerEvent);
	
	void ClientEvent(const TDesC& aEventDescription);
	void PayResult(PAY_RESULT& aPayResult);

private:
	// Constructors

	/**
	 * ConstructL
	 * 2nd phase constructor.
	 * Perform the second phase construction of a
	 * CSymbianDemo1AppView object.
	 * @param aRect The rectangle this view will be drawn to.
	 */
	void ConstructL(const TRect& aRect);

	/**
	 * CSymbianDemo1AppView.
	 * C++ default constructor.
	 */
	CSymbianDemo1AppView();

	};

#endif // __SYMBIANDEMO1APPVIEW_h__
// End of File
