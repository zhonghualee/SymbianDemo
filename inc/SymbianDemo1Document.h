/*
 ============================================================================
 Name		: SymbianDemo1Document.h
 Author	  : 
 Copyright   : Your copyright notice
 Description : Declares document class for application.
 ============================================================================
 */

#ifndef __SYMBIANDEMO1DOCUMENT_h__
#define __SYMBIANDEMO1DOCUMENT_h__

// INCLUDES
#include <akndoc.h>

// FORWARD DECLARATIONS
class CSymbianDemo1AppUi;
class CEikApplication;

// CLASS DECLARATION

/**
 * CSymbianDemo1Document application class.
 * An instance of class CSymbianDemo1Document is the Document part of the
 * AVKON application framework for the SymbianDemo1 example application.
 */
class CSymbianDemo1Document : public CAknDocument
	{
public:
	// Constructors and destructor

	/**
	 * NewL.
	 * Two-phased constructor.
	 * Construct a CSymbianDemo1Document for the AVKON application aApp
	 * using two phase construction, and return a pointer
	 * to the created object.
	 * @param aApp Application creating this document.
	 * @return A pointer to the created instance of CSymbianDemo1Document.
	 */
	static CSymbianDemo1Document* NewL(CEikApplication& aApp);

	/**
	 * NewLC.
	 * Two-phased constructor.
	 * Construct a CSymbianDemo1Document for the AVKON application aApp
	 * using two phase construction, and return a pointer
	 * to the created object.
	 * @param aApp Application creating this document.
	 * @return A pointer to the created instance of CSymbianDemo1Document.
	 */
	static CSymbianDemo1Document* NewLC(CEikApplication& aApp);

	/**
	 * ~CSymbianDemo1Document
	 * Virtual Destructor.
	 */
	virtual ~CSymbianDemo1Document();

public:
	// Functions from base classes

	/**
	 * CreateAppUiL
	 * From CEikDocument, CreateAppUiL.
	 * Create a CSymbianDemo1AppUi object and return a pointer to it.
	 * The object returned is owned by the Uikon framework.
	 * @return Pointer to created instance of AppUi.
	 */
	CEikAppUi* CreateAppUiL();

private:
	// Constructors

	/**
	 * ConstructL
	 * 2nd phase constructor.
	 */
	void ConstructL();

	/**
	 * CSymbianDemo1Document.
	 * C++ default constructor.
	 * @param aApp Application creating this document.
	 */
	CSymbianDemo1Document(CEikApplication& aApp);

	};

#endif // __SYMBIANDEMO1DOCUMENT_h__
// End of File
