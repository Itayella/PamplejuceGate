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

#include "RectiFi_Alg.h"

template<int kNumChannelsIn, int kNumChannelsOut>
void RectiFi_Algorithm_ResetFunction(
	SRectiFi_Algorithm_Context * const inInstancesBegin [],
	const void * AAX_RESTRICT					inInstancesEnd)
{
	for (SRectiFi_Algorithm_Context * const * walk = inInstancesBegin; walk != inInstancesEnd; ++walk)
	{
		SRectiFi_Algorithm_Context* contextP = *walk;

		RectiFi_Algorithm_InitStateBlock(eAlgFieldIndex_State, contextP->mStateP, sizeof(SRectiFiStateBlock), 0);
	}
}
