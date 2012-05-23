/*
 ============================================================================
 Name		: SymbianDemo1Application.h
 Author	  : 
 Copyright   : Your copyright notice
 Description : Declares main application class.
 ============================================================================
 */

#ifndef __SYMBIANDEMO1APPLICATION_H__
#define __SYMBIANDEMO1APPLICATION_H__

// INCLUDES
#include <aknapp.h>
#include "SymbianDemo1.hrh"

// UID for the application;
// this should correspond to the uid defined in the mmp file
const TUid KUidSymbianDemo1App =
	{
	_UID3
	};

// CLASS DECLARATION

/**
 * CSymbianDemo1Application application class.
 * Provides factory to create concrete document object.
 * An instance of CSymbianDemo1Application is the application part of the
 * AVKON application framework for the SymbianDemo1 example application.
 */
class CSymbianDemo1Application : public CAknApplication
	{
public:
	// Functions from base classes

	/**
	 * From CApaApplication, AppDllUid.
	 * @return Application's UID (KUidSymbianDemo1App).
	 */
	TUid AppDllUid() const;

protected:
	// Functions from base classes

	/**
	 * From CApaApplication, CreateDocumentL.
	 * Creates CSymbianDemo1Document document object. The returned
	 * pointer in not owned by the CSymbianDemo1Application object.
	 * @return A pointer to the created document object.
	 */
	CApaDocument* CreateDocumentL();
	};

#endif // __SYMBIANDEMO1APPLICATION_H__
// End of File
