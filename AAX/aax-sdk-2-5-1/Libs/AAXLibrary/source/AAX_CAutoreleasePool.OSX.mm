/*================================================================================================*/
/*
 *	Copyright 2011-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/

#include "AAX_CAutoreleasePool.h"

#import <Foundation/Foundation.h>

AAX_CAutoreleasePool::AAX_CAutoreleasePool()
{
	mAutoreleasePool = [[NSAutoreleasePool alloc] init];
}

AAX_CAutoreleasePool::~AAX_CAutoreleasePool()
{
	[((NSAutoreleasePool*) mAutoreleasePool) release];
}
