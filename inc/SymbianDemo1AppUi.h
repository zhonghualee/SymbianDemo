/*
 ============================================================================
 Name		: SymbianDemo1AppUi.h
 Author	  : 
 Copyright   : Your copyright notice
 Description : Declares UI class for application.
 ============================================================================
 */

#ifndef __SYMBIANDEMO1APPUI_h__
#define __SYMBIANDEMO1APPUI_h__

// INCLUDES
#include <aknappui.h>

// FORWARD DECLARATIONS
class CSymbianDemo1AppView;
class CPayApi;

// CLASS DECLARATION
/**
 * CSymbianDemo1AppUi application UI class.
 * Interacts with the user through the UI and request message processing
 * from the handler class
 */
class CSymbianDemo1AppUi : public CAknAppUi
	{
public:
	// Constructors and destructor

	/**
	 * ConstructL.
	 * 2nd phase constructor.
	 */
	void ConstructL();

	/**
	 * CSymbianDemo1AppUi.
	 * C++ default constructor. This needs to be public due to
	 * the way the framework constructs the AppUi
	 */
	CSymbianDemo1AppUi();

	/**
	 * ~CSymbianDemo1AppUi.
	 * Virtual Destructor.
	 */
	virtual ~CSymbianDemo1AppUi();

private:
	// Functions from base classes

	/**
	 * From CEikAppUi, HandleCommandL.
	 * Takes care of command handling.
	 * @param aCommand Command to be handled.
	 */
	void HandleCommandL(TInt aCommand);

	/**
	 *  HandleStatusPaneSizeChange.
	 *  Called by the framework when the application status pane
	 *  size is changed.
	 */
	void HandleStatusPaneSizeChange();

	/**
	 *  From CCoeAppUi, HelpContextL.
	 *  Provides help context for the application.
	 *  size is changed.
	 */
	CArrayFix<TCoeHelpContext>* HelpContextL() const;
	void WriteFile();
//	void ReadFile();
	void checkPaidResult();

	void WriteInt32ToStreamL(RFs& aFs,
			const TDesC& aFileName, TInt32 aValue);
	TInt32 ReadInt32FromStreamL(RFs& aFs,
			const TDesC& aFileName);
//	void AppendInt32ToStreamL(RFs& aFs,
//			const TDesC& aFileName, TInt32 aValue);
	void ReadAllTInt32FromStreamL(RFs& aFs,
			const TDesC& aFileName, RArray<TInt>& aArray);

private:
	// Data

	/**
	 * The application view
	 * Owned by CSymbianDemo1AppUi
	 */
	CSymbianDemo1AppView* iAppView;
	CPayApi* iPayApi;
	bool isPaid;

	};

#endif // __SYMBIANDEMO1APPUI_h__
// End of File
