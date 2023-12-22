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

#include "DemoGain_Alg.h"
#include "AAX.h"


SDemoGain_BGBuffer * gBGBuffer[cMaxNumInstances];
float * gBGGain[cMaxNumInstances];
AAX_CBoolean gInstanceIsActive[cMaxNumInstances];
uint32_t gNumInstances = 0;
