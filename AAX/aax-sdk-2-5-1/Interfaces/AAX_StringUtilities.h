/*================================================================================================*/
/*
 *
 *  Copyright 2014-2016, 2018, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/** 
 *	\file   AAX_StringUtilities.h
 *
 *	\brief  Various string utility definitions for %AAX Native
 */
/*================================================================================================*/
#pragma once

#ifndef	AAXLibrary_AAX_StringUtilities_h
#define	AAXLibrary_AAX_StringUtilities_h

// AAX headers
#include "AAX.h"
#include "AAX_Enums.h"

// Standard Library headers
#include <string>

class AAX_IString;


//------------------------------------------------
#pragma mark Utility functions

namespace AAX
{
	inline void			GetCStringOfLength(char *stringOut, const char* stringIn, int32_t aMaxChars);
	inline int32_t		Caseless_strcmp(const char* cs, const char* ct);
	
	inline std::string	Binary2String(uint32_t binaryValue, int32_t numBits);
	inline uint32_t		String2Binary(const AAX_IString& s);
	
	inline bool			IsASCII(char inChar);
	inline bool			IsFourCharASCII(uint32_t inFourChar);
	
	inline std::string	AsStringFourChar(uint32_t inFourChar);
	inline std::string	AsStringPropertyValue(AAX_EProperty inProperty, AAX_CPropertyValue inPropertyValue);
	inline std::string	AsStringInt32(int32_t inInt32);
	inline std::string	AsStringUInt32(uint32_t inUInt32);
	inline std::string	AsStringIDTriad(const AAX_SPlugInIdentifierTriad& inIDTriad);
	inline std::string	AsStringStemFormat(AAX_EStemFormat inStemFormat, bool inAbbreviate = false);
	inline std::string	AsStringStemChannel(AAX_EStemFormat inStemFormat, uint32_t inChannelIndex, bool inAbbreviate);
	inline std::string	AsStringResult(AAX_Result inResult);
} // namespace AAX


//------------------------------------------------------
#pragma mark Implementation header

#include "AAX_StringUtilities.hpp"


#endif /* AAXLibrary_AAX_StringUtilities_h */
