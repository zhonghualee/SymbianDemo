/*
 ============================================================================
 Name		: SymbianDemo1AppUi.cpp
 Author	  : 
 Copyright   : Your copyright notice
 Description : CSymbianDemo1AppUi implementation
 ============================================================================
 */

// INCLUDE FILES
#include <avkon.hrh>
#include <aknmessagequerydialog.h>
#include <aknnotewrappers.h>
#include <stringloader.h>
#include <f32file.h>
#include <s32file.h>
#include <hlplch.h>
#include <e32std.h> 
#include <bautils.h>

#include <symbiandemo1_0xe68a9f1f.rsg>

#ifdef _HELP_AVAILABLE_
#include "SymbianDemo1_0xe68a9f1f.hlp.hrh"
#endif
#include "SymbianDemo1.hrh"
#include "SymbianDemo1.pan"
#include "SymbianDemo1Application.h"
#include "SymbianDemo1AppUi.h"
#include "SymbianDemo1AppView.h"
#include "PayApi.h"

_LIT( KFileName, "C:\\private\\e68a9f1f\\SymbianDemo1.txt" );
_LIT( KPaidFileName, "5.txt");
_LIT( KText, "Hello World!");

const TUint appId = 100;
extern void AppendInt32ToStreamL(RFs& aFs,
			const TDesC& aFileName, TInt32 aValue);


// ============================ MEMBER FUNCTIONS ===============================

void CSymbianDemo1AppUi::WriteFile()
	{
	AppendInt32ToStreamL(CCoeEnv::Static()->FsSession(), KPaidFileName, 89);
	AppendInt32ToStreamL(CCoeEnv::Static()->FsSession(), KPaidFileName, 87);
	AppendInt32ToStreamL(CCoeEnv::Static()->FsSession(), KPaidFileName, 86);
	AppendInt32ToStreamL(CCoeEnv::Static()->FsSession(), KPaidFileName, 85);
	}


void CSymbianDemo1AppUi::WriteInt32ToStreamL(RFs& aFs,
		const TDesC& aFileName, TInt32 aValue)
	{
	// Open the file stream.
	RFileWriteStream writeStream;
	User::LeaveIfError(writeStream.Replace(aFs, aFileName, EFileWrite));
	writeStream.PushL();
	
	// Write a TInt32 to the stream.
	writeStream.WriteInt32L(aValue);
	
	// Commit the change and close the stream.
	writeStream.CommitL();
	CleanupStack::Pop(&writeStream);
	writeStream.Release();
	}

TInt32 CSymbianDemo1AppUi::ReadInt32FromStreamL(RFs& aFs,
		const TDesC& aFileName)
	{
	// Open the file stream.
	RFileReadStream readStream;
	User::LeaveIfError(readStream.Open(aFs, aFileName, EFileRead));
	CleanupClosePushL(readStream);

	// Read a TInt32 from the stream.
	TInt32 value;
	readStream >> value;
	
	// Close the stream and return the read TInt32.
	CleanupStack::PopAndDestroy(&readStream);
	return value;
	}

void AppendInt32ToStreamL(RFs& aFs,
		const TDesC& aFileName, TInt32 aValue)
	{
	// Open the file stream.
	RFileWriteStream writeStream;
	TInt err = KErrNone;
	if (BaflUtils::FileExists(CCoeEnv::Static()->FsSession(), aFileName))
		{
		err = writeStream.Open(aFs, aFileName, EFileWrite);
		}
	else
		{
		err = writeStream.Create(aFs, aFileName, EFileWrite);
		}
	User::LeaveIfError(err);
	writeStream.PushL();
	
	// Move the file pointer to the end of file.
	writeStream.Sink()->SeekL(MStreamBuf::EWrite, EStreamEnd, 0);
	
	// Write a TInt32 at the end of file.
	writeStream.WriteInt32L(aValue);
	
	// Commit the change and close the file.
	writeStream.CommitL();
	CleanupStack::Pop(&writeStream);
	writeStream.Release();
	}

void CSymbianDemo1AppUi::ReadAllTInt32FromStreamL(RFs& aFs,
		const TDesC& aFileName, RArray<TInt>& aArray)
	{
	// Open the file stream.
	RFileReadStream readStream;
	User::LeaveIfError(readStream.Open(aFs, aFileName, EFileRead));
	CleanupClosePushL(readStream);

	// Get the EOF position.
	TStreamPos eofPos(readStream.Source()->SizeL());
	
	// Get the current position of file pointer.
	TStreamPos currentPos(0);

	// Read all TInt2's until EOF.
	while (currentPos < eofPos)
		{
		TInt32 value;
		readStream >> value;
		aArray.Append(value);
		
		currentPos = readStream.Source()->TellL(MStreamBuf::ERead);
		}
	
	CleanupStack::PopAndDestroy(&readStream);
	}


void CSymbianDemo1AppUi::checkPaidResult()
	{
	// Create an array.
	RArray<TInt> array;
	CleanupClosePushL(array);
	
	// Read all TInt32's from the file.
	ReadAllTInt32FromStreamL(iCoeEnv->FsSession(), KPaidFileName, array);
//	TBuf<32> buf;
	// Display all TInt32's on the main view.
	for (TInt i = 0; i < array.Count(); i++)
		{
//		buf.Format(_L("%d %d"), array[i], appId);
//		iEikonEnv->AlertWin(buf);
//		
		if (array[i] == appId)
			{
			isPaid = true;
			}
		}
	CleanupStack::PopAndDestroy(&array); // buffer and array
//	iEikonEnv->AlertWin(_L("end of fun"));
	}
//
//void  CSymbianDemo1AppUi::checkPaidResult()
//	{
//		iEikonEnv->AlertWin(_L("1"));
//		isPaid = false;
//		TInt32 someInt = 0;
//		RFileReadStream writerStream;
//		// writerStream on cleanup stack
//		writerStream.PushL(); 
//		//fs is ur file session and fileName is name of ur file.
//		User::LeaveIfError(writerStream.Open(CCoeEnv::Static()->FsSession(), KPaidFileName, EFileWrite));
//				
//		TBuf<32> ptrBuf;
//		TRAPD(err, writerStream.ReadL(ptrBuf,(TChar)'\n'));
//		TBuf<512> buf;
//		int i =0;
//		while(err != KErrEof)
//			{
//			i++;
////			iEikonEnv->AlertWin(_L("There is data"));		
//			
//			TLex myLexer(ptrBuf);
//			TInt value;
//			User::LeaveIfError(myLexer.Val(value));	
//			
////			buf.Format(_L("%d_value"), value);
//			
//			iEikonEnv->AlertWin(buf);
//			TRAPD(err, writerStream.ReadL(ptrBuf,(TChar)'\n'));
//			
////			if(value == appId)
////				{
////				iEikonEnv->AlertWin(_L("already paid"));		
////				isPaid = true;
////				break;
////				}
//			
////			buf.Format(_L("%d_value"), err);
////			iEikonEnv->AlertWin(buf);
//			}
//		buf.Format(_L("%d_value"), i);
//		iEikonEnv->AlertWin(buf);
//		
//		iEikonEnv->AlertWin(_L("4"));
//		// free writerStream
//		writerStream.Pop(); 
//		writerStream.Release();
//		iEikonEnv->AlertWin(_L("6"));		
//	}

// -----------------------------------------------------------------------------
// CSymbianDemo1AppUi::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CSymbianDemo1AppUi::ConstructL()
	{
	// Initialise app UI with standard value.
	BaseConstructL(CAknAppUi::EAknEnableSkin);

	// Create view object
	iAppView = CSymbianDemo1AppView::NewL(ClientRect());
	
	iPayApi = CPayApi::NewL(*iAppView,this);

	// Create a file to write the text to
	TInt err = CCoeEnv::Static()->FsSession().MkDirAll(KFileName);
	if ((KErrNone != err) && (KErrAlreadyExists != err))
		{
		return;
		}

	RFile file;
	err = file.Replace(CCoeEnv::Static()->FsSession(), KFileName, EFileWrite);
	CleanupClosePushL(file);
	if (KErrNone != err)
		{
		CleanupStack::PopAndDestroy(1); // file
		return;
		}

	RFileWriteStream outputFileStream(file);
	CleanupClosePushL(outputFileStream);
	outputFileStream << KText;

	CleanupStack::PopAndDestroy(2); // outputFileStream, file

	}
// -----------------------------------------------------------------------------
// CSymbianDemo1AppUi::CSymbianDemo1AppUi()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CSymbianDemo1AppUi::CSymbianDemo1AppUi()
	{
	// No implementation required
//	checkPaidResult();
	}

// -----------------------------------------------------------------------------
// CSymbianDemo1AppUi::~CSymbianDemo1AppUi()
// Destructor.
// -----------------------------------------------------------------------------
//
CSymbianDemo1AppUi::~CSymbianDemo1AppUi()
	{
	if (iAppView)
		{
		delete iAppView;
		iAppView = NULL;
		}
	}

// -----------------------------------------------------------------------------
// CSymbianDemo1AppUi::HandleCommandL()
// Takes care of command handling.
// -----------------------------------------------------------------------------
//
void CSymbianDemo1AppUi::HandleCommandL(TInt aCommand)
	{
	switch (aCommand)
		{
		case EEikCmdExit:
		case EAknSoftkeyExit:
			Exit();
			break;

		case ECommand1:
			{			
//			WriteFile();
//			ReadFile();
			_LIT8(KPoint,"1");
			_LIT8(KAttachment,"1");
			_LIT8(KFee,"100");
			_LIT8(KAppId, "89");
			_LIT8(KDeveloperId,"86");
			checkPaidResult();
			if(isPaid)
				{
				iEikonEnv->AlertWin(_L("Already paid"));
				}
			else
				{
					iEikonEnv->AlertWin(_L("Not paid"));
//					pictureShow = false;
					iPayApi->IssuePayL(KPoint,KAttachment,KFee,KAppId,KDeveloperId);
					AppendInt32ToStreamL(CCoeEnv::Static()->FsSession(), KPaidFileName, appId);
//					iEikonEnv->AlertWin(_L("IssuePay"));
				}
			}
			break;
		case ECommand2:
			{
			checkPaidResult();
			if (isPaid)
				{
				iEikonEnv->AlertWin(_L("Already paid"));
				}
			else
				{
				iEikonEnv->AlertWin(_L("Not paid"));
							}	
			}
			break;
		case EHelp:
			{
			CArrayFix < TCoeHelpContext > *buf = CCoeAppUi::AppHelpContextL();
			HlpLauncher::LaunchHelpApplicationL(iEikonEnv->WsSession(), buf);
			}
			break;
		case EAbout:
			{

			CAknMessageQueryDialog* dlg = new (ELeave) CAknMessageQueryDialog();
			dlg->PrepareLC(R_ABOUT_QUERY_DIALOG);
			HBufC* title = iEikonEnv->AllocReadResourceLC(R_ABOUT_DIALOG_TITLE);
			dlg->QueryHeading()->SetTextL(*title);
			CleanupStack::PopAndDestroy(); //title
			HBufC* msg = iEikonEnv->AllocReadResourceLC(R_ABOUT_DIALOG_TEXT);
			dlg->SetMessageTextL(*msg);
			CleanupStack::PopAndDestroy(); //msg
			dlg->RunLD();
			}
			break;
		default:
			Panic( ESymbianDemo1Ui);
			break;
		}
	}
// -----------------------------------------------------------------------------
//  Called by the framework when the application status pane
//  size is changed.  Passes the new client rectangle to the
//  AppView
// -----------------------------------------------------------------------------
//
void CSymbianDemo1AppUi::HandleStatusPaneSizeChange()
	{
	iAppView->SetRect(ClientRect());
	}

CArrayFix<TCoeHelpContext>* CSymbianDemo1AppUi::HelpContextL() const
	{
#warning "Please see comment about help and UID3..."
	// Note: Help will not work if the application uid3 is not in the
	// protected range.  The default uid3 range for projects created
	// from this template (0xE0000000 - 0xEFFFFFFF) are not in the protected range so that they
	// can be self signed and installed on the device during testing.
	// Once you get your official uid3 from Symbian Ltd. and find/replace
	// all occurrences of uid3 in your project, the context help will
	// work. Alternatively, a patch now exists for the versions of 
	// HTML help compiler in SDKs and can be found here along with an FAQ:
	// http://www3.symbian.com/faq.nsf/AllByDate/E9DF3257FD565A658025733900805EA2?OpenDocument
#ifdef _HELP_AVAILABLE_
	CArrayFixFlat<TCoeHelpContext>* array = new(ELeave)CArrayFixFlat<TCoeHelpContext>(1);
	CleanupStack::PushL(array);
	array->AppendL(TCoeHelpContext(KUidSymbianDemo1App, KGeneral_Information));
	CleanupStack::Pop(array);
	return array;
#else
	return NULL;
#endif
	}

// End of File
