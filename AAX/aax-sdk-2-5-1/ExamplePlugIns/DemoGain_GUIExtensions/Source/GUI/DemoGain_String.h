/*================================================================================================*/
/*
 *	Copyright 2009-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoGain_String.h
 *
 */ 
/*================================================================================================*/

#ifndef _DEMOGAIN_STRING_
#define _DEMOGAIN_STRING_

#include "AAX_IString.h"
#include <string>

class DemoGain_String : public AAX_IString
{
public: ////////////////////////////////////////////// DemoGain_String
	static const uint32_t	kMaxStringLength = static_cast<uint32_t>(-2);
	
	/** Constructs an empty string. */
	DemoGain_String();

public: ////////////////////////////////////////////// AAX_IString	
	/** Length methods */
	virtual uint32_t		Length () const;
	virtual uint32_t		MaxLength () const;
	
	/** C string methods */
	virtual const char *	Get ()	const;
	virtual void			Set ( const char * iString );		
	
	/** Assignment operators */
	virtual AAX_IString &	operator=(const AAX_IString & iOther);
	virtual AAX_IString &	operator=(const char * iString);
	
private: ///////////////////////////////////////////// DemoGain_String
	std::string mString;
};

#endif // _DEMOGAIN_STRING_
