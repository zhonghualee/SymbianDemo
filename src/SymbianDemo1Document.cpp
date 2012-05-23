/*
 ============================================================================
 Name		: SymbianDemo1Document.cpp
 Author	  : 
 Copyright   : Your copyright notice
 Description : CSymbianDemo1Document implementation
 ============================================================================
 */

// INCLUDE FILES
#include "SymbianDemo1AppUi.h"
#include "SymbianDemo1Document.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CSymbianDemo1Document::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CSymbianDemo1Document* CSymbianDemo1Document::NewL(CEikApplication& aApp)
	{
	CSymbianDemo1Document* self = NewLC(aApp);
	CleanupStack::Pop(self);
	return self;
	}

// -----------------------------------------------------------------------------
// CSymbianDemo1Document::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CSymbianDemo1Document* CSymbianDemo1Document::NewLC(CEikApplication& aApp)
	{
	CSymbianDemo1Document* self = new (ELeave) CSymbianDemo1Document(aApp);

	CleanupStack::PushL(self);
	self->ConstructL();
	return self;
	}

// -----------------------------------------------------------------------------
// CSymbianDemo1Document::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CSymbianDemo1Document::ConstructL()
	{
	// No implementation required
	}

// -----------------------------------------------------------------------------
// CSymbianDemo1Document::CSymbianDemo1Document()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CSymbianDemo1Document::CSymbianDemo1Document(CEikApplication& aApp) :
	CAknDocument(aApp)
	{
	// No implementation required
	}

// ---------------------------------------------------------------------------
// CSymbianDemo1Document::~CSymbianDemo1Document()
// Destructor.
// ---------------------------------------------------------------------------
//
CSymbianDemo1Document::~CSymbianDemo1Document()
	{
	// No implementation required
	}

// ---------------------------------------------------------------------------
// CSymbianDemo1Document::CreateAppUiL()
// Constructs CreateAppUi.
// ---------------------------------------------------------------------------
//
CEikAppUi* CSymbianDemo1Document::CreateAppUiL()
	{
	// Create the application user interface, and return a pointer to it;
	// the framework takes ownership of this object
	return new (ELeave) CSymbianDemo1AppUi;
	}

// End of File
