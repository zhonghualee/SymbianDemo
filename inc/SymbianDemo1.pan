/*
 ============================================================================
 Name		: SymbianDemo1.pan
 Author	  : 
 Copyright   : Your copyright notice
 Description : This file contains panic codes.
 ============================================================================
 */

#ifndef __SYMBIANDEMO1_PAN__
#define __SYMBIANDEMO1_PAN__

/** SymbianDemo1 application panic codes */
enum TSymbianDemo1Panics
	{
	ESymbianDemo1Ui = 1
	// add further panics here
	};

inline void Panic(TSymbianDemo1Panics aReason)
	{
	_LIT(applicationName, "SymbianDemo1");
	User::Panic(applicationName, aReason);
	}

#endif // __SYMBIANDEMO1_PAN__
