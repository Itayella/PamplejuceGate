/*================================================================================================*/
/*

 *	Copyright 2014-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file   AAX_CAutoreleasePool.h
 *	
 *	\brief Autorelease pool helper utility
 */ 
/*================================================================================================*/


#pragma once

#ifndef _AAX_CAUTORELEASEPOOL_H_
#define _AAX_CAUTORELEASEPOOL_H_


/*	\brief Creates an autorelease pool for the scope of the stack based class
	to clearn up any autoreleased memory that was allocated in the lifetime of
	the pool.
	
	\details
	This may be used on either Mac or Windows platforms and will not pull in
	any Cocoa dependencies.
	
	usage:
\code
{
	AAX_CAutoreleasePool myAutoReleasePool
	delete myCocoaObject;

	// Pool is released when the AAX_CAutoreleasePool is destroyed
}
\endcode
 */
class AAX_CAutoreleasePool
{
	public:
		AAX_CAutoreleasePool();
		~AAX_CAutoreleasePool();

	private:
		AAX_CAutoreleasePool (const AAX_CAutoreleasePool&);
		AAX_CAutoreleasePool& operator= (const AAX_CAutoreleasePool&);

	private:
		void* mAutoreleasePool; //!< Opaque pool instance
 };


#endif // #ifndef _AAX_CAUTORELEASEPOOL_H_
