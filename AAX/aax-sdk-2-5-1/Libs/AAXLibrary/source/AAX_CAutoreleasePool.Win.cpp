/*================================================================================================*/
/*
 *	Copyright 2013-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file  AAX_CAutoreleasePool.Win.cpp
 *	
 *	\brief Windows implementation of a basic Autorelease pool helper utility
 *
 */ 
/*================================================================================================*/

#include "AAX_CAutoreleasePool.h"
#include "stddef.h"

AAX_CAutoreleasePool::AAX_CAutoreleasePool() : mAutoreleasePool(NULL)
{
	// Nothing to do on Windows yet...maybe someday if Apple ever opens objective-C libs on the Windows platform.
}

AAX_CAutoreleasePool::~AAX_CAutoreleasePool()
{
	// Nothing to do on Windows yet...maybe someday if Apple ever opens objective-C libs on the Windows platform.
}
