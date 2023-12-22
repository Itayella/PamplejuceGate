/*================================================================================================*/
/*
 *	Copyright 2009-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/
#include "DemoGain_String.h"


DemoGain_String::DemoGain_String() :
	mString("")
{
}

uint32_t DemoGain_String::Length () const
{
	return uint32_t(mString.length());
}

uint32_t DemoGain_String::MaxLength () const
{
	return kMaxStringLength;
}

const char * DemoGain_String::Get ()	const
{
	return mString.c_str();
}

void DemoGain_String::Set ( const char * iString )
{
	mString = iString;
}

AAX_IString & DemoGain_String::operator=(const AAX_IString & iOther)
{	
	mString = iOther.Get();
	return *this;
}

AAX_IString & DemoGain_String::operator=(const char * iString)
{
	mString = iString;
	return *this;
}
