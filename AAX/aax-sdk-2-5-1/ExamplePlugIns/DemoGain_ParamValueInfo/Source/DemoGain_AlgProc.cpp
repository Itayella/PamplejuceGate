/*================================================================================================*/
/*
 *	Copyright 2012-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */ 
/*================================================================================================*/

// Component includes
#include "DemoGain_Alg.h"

// AAX includes
#include "AAX.h"

// Standard includes
#include <math.h>		// for fabsf()
#include <algorithm>	// for max()



//==============================================================================
// Processing function definition
//==============================================================================

void
AAX_CALLBACK
DemoGain_AlgorithmProcessFunction (
	SDemoGain_Alg_Context * const	inInstancesBegin [],
	const void *					inInstancesEnd)
{
	// Get a pointer to the beginning of the memory block table
	SDemoGain_Alg_Context* AAX_RESTRICT instance = inInstancesBegin [0];


	//--------- Iterate over plug-in instances ---------//
	//
	for (SDemoGain_Alg_Context * const * walk = inInstancesBegin; walk < inInstancesEnd; ++walk)
	{
		instance = *walk;

		//--------- Retrieve instance-specific information ---------//
		//
		// Memory blocks
		const SDemoGain_CoefsGain* const AAX_RESTRICT	coefsGainP =	instance->mCoefsGainP;	// Input (const)		
		const int32_t	bypass		= *instance->mCtrlBypassP; // 'int' not 'bool' for optimization
		const float		gain		= coefsGainP->mGain;
		const int32_t	buffersize	= *instance->mBufferSize;
		// Audio channels
		const float* const AAX_RESTRICT pdI = instance->mInputPP [0]; // First channel
		float* const AAX_RESTRICT pdO = instance->mOutputPP [0]; // First channel
		// Meter taps
		float* const AAX_RESTRICT	meterTaps	= *instance->mMetersPP;

		//--------- Run processing loop over each sample ---------//
		//
		for (int t = 0; t < buffersize; t++)
		{
			// Process audio samples
			//
			pdO [t] = gain * pdI [t];
			if (bypass) { pdO [t] = pdI [t]; }
		} // Go to the next sample

		// Do metering
		//
		// Accumulate the max value for metering. This will get cleared for us by the shell
		// when it sends the accumulated value up to the host.
		for (int t = 0; t < buffersize; t++)
		{
			meterTaps[eMeterTap_PreGain] = std::max(fabsf(pdI [t]), meterTaps[eMeterTap_PreGain]);
			meterTaps[eMeterTap_PostGain] = std::max(fabsf(pdO [t]), meterTaps[eMeterTap_PostGain]);
		} // Go to the next sample

	} // End instance-iteration loop

}
