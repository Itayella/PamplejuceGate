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
#include "DemoGain_AlgProc_Burst.cpp"
#include "DemoGain_AlgProc_ScatterGather.cpp"

#include "../TI/CCSv5/elf_linkage_aax_ccsv5.h"


// The main algorithm entry point - burst
extern "C"
TI_EXPORT
void AlgEntry_Burst(
	SDemoGain_DMABurst_Alg_Context * const	inInstancesBegin [],
	const void *							inInstancesEnd)
{
	DemoGain_DMABurst_AlgorithmProcessFunction(
		inInstancesBegin,
		inInstancesEnd);
}

// The main algorithm entry point - scatter/gather
extern "C"
TI_EXPORT
void AlgEntry_ScatterGather(
	SDemoGain_DMASG_Alg_Context * const		inInstancesBegin [],
	const void *							inInstancesEnd)
{
	DemoGain_DMASG_AlgorithmProcessFunction(
		inInstancesBegin,
		inInstancesEnd);
}
