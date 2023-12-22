/*================================================================================================*/
/*
 *	Copyright 2013-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   HostProcessor_Describe.h
 *
 *	\brief  Declaration of GetEffectDescriptions function.
 *
 *  \author Rob Majors
 */ 
/*================================================================================================*/

#ifndef __DemoDelay_HostProcessor__Delay_Describe__
#define __DemoDelay_HostProcessor__Delay_Describe__

#include "AAX.h"

class AAX_ICollection;

AAX_Result HostProcessor_GetEffectDescriptions( AAX_ICollection * outCollection );

#endif /* defined(__DemoDelay_HostProcessor__Delay_Describe__) */
