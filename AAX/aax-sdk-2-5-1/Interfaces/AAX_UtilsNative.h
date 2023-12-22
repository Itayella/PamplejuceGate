/*================================================================================================*/
/*

 *	Copyright 2013-2017, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file   AAX_UtilsNative.h
 *	
 *	\brief  Various utility definitions for %AAX Native
 *
 */ 
/*================================================================================================*/


#pragma once

#ifndef _AAX_UTILSNATIVE_H_
#define _AAX_UTILSNATIVE_H_


#ifndef _TMS320C6X

// AAX Includes
#include "AAX_CString.h"
#include "AAX_IString.h"
#include "AAX_Assert.h"
#include "AAX.h"

// Standard Library Includes
#include <cmath> // for log()
#include <string.h>


//------------------------------------------------
#pragma mark Utility functions

namespace AAX
{
	
	/**	\brief Double-precision safe log function.  Returns zero
	 *	for input values that are <= 0.0
	 */
	inline double SafeLog (double aValue) { return aValue <= 0.0 ? 0.0 : log(aValue); }

	/**	\brief Single-precision safe log function.  Returns zero
	 *	for input values that are <= 0.0
	 */
	inline float SafeLogf (float aValue) { return aValue <= 0.0f ? 0.0f : logf(aValue); }

	/** \brief Helper function to check if two parameter IDs are equivalent
	 */
	inline AAX_CBoolean IsParameterIDEqual ( AAX_CParamID iParam1, AAX_CParamID iParam2 ) { return static_cast<AAX_CBoolean>( strcmp ( iParam1, iParam2 ) == 0 ); }

	/** \brief Helper function to check if two Effect IDs are equivalent
	 */
	inline AAX_CBoolean IsEffectIDEqual ( const AAX_IString * iEffectID1, const AAX_IString * iEffectID2 ) { return static_cast<AAX_CBoolean>( strcmp ( iEffectID1->Get(), iEffectID2->Get() ) == 0 ); }
		
	/** \brief Helper function to check if a notification ID is reserved for host notifications
	 */
	inline AAX_CBoolean IsAvidNotification ( AAX_CTypeID inNotificationID )
	{
		return (AAX_CBoolean)((('A' == ((inNotificationID & 0xFF000000) >> 24)) &&
				 ('X' == ((inNotificationID & 0x00FF0000) >> 16))) ||
				(inNotificationID == 'ASPv'));
	}
		
} // namespace AAX


#endif // #ifndef _TMS320C6X

#endif // #ifndef _AAX_UTILSNATIVE_H_
