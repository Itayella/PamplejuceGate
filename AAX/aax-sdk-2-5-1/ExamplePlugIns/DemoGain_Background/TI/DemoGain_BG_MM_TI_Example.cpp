/*================================================================================================*/
/*
 *	Copyright 2014-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/

// Host Alg wrapper shim headers
#include "DemoGain_AlgProc.cpp"
#include "../TI/CCSv5/elf_linkage_aax_ccsv5.h"


// The main algorithm entry point
extern "C"
TI_EXPORT
void AlgEntry(	SDemoGain_Alg_Context * const		inInstancesBegin [],
				const void *						inInstancesEnd)
{
	DemoGain_AlgorithmProcessFunction(
		inInstancesBegin,
		inInstancesEnd);
}

extern "C"
TI_EXPORT
int32_t AlgInit(SDemoGain_Alg_Context const *    inInstance,
				AAX_EComponentInstanceInitAction inAction)
{
	return DemoGain_AlgorithmInitFunction(inInstance, inAction);
}

extern "C"
TI_EXPORT
int32_t BGEntry()
{
	return DemoGain_AlgorithmBackgroundFunction();
}

