/*================================================================================================*/
/*
 *	Copyright 2013-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/
// Host Alg wrapper shim headers
#include "DemoDelay_Alg.h"
#include "../TI/CCSv5/elf_linkage_aax_ccsv5.h"
#include "AAX.h"
#include "AAX_Enums.h"

extern "C"
TI_EXPORT
void AlgEntry( SDemoDelayHybrid_LowLatency_Context * const	inInstancesBegin [],
			   const void *						            inInstancesEnd)
{
      DemoDelay_AlgorithmProcessFunction(
            inInstancesBegin,
            inInstancesEnd);
}
