/*
 ============================================================================
 Name		: SymbianDemo1Application.cpp
 Author	  : 
 Copyright   : Your copyright notice
 Description : Main application class
 ============================================================================
 */

// INCLUDE FILES
#include "SymbianDemo1.hrh"
#include "SymbianDemo1Document.h"
#include "SymbianDemo1Application.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CSymbianDemo1Application::CreateDocumentL()
// Creates CApaDocument object
// -----------------------------------------------------------------------------
//
CApaDocument* CSymbianDemo1Application::CreateDocumentL()
	{
	// Create an SymbianDemo1 document, and return a pointer to it
	return CSymbianDemo1Document::NewL(*this);
	}

// -----------------------------------------------------------------------------
// CSymbianDemo1Application::AppDllUid()
// Returns application UID
// -----------------------------------------------------------------------------
//
TUid CSymbianDemo1Application::AppDllUid() const
	{
	// Return the UID for the SymbianDemo1 application
	return KUidSymbianDemo1App;
	}

// End of File
