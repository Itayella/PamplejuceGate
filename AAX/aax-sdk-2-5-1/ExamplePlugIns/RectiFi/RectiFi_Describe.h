/*================================================================================================*/
/*
 *	Copyright 2009-2015, 2018, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   Rectifi_Describe.h
 *
 *	\brief  Declaration of GetEffectDescriptions function.
 *
 *  \author Rus Maxham
 */ 
/*================================================================================================*/

#include "AAX.h"

class AAX_ICollection;
class AAX_IEffectDescriptor;

AAX_Result GetEffectDescriptions ( AAX_ICollection * outDescriptions );
AAX_Result Rectifi_GetPlugInDescription ( AAX_IEffectDescriptor & outDescriptor );
	
