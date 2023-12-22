/*================================================================================================*/
/*
 *	Copyright 2014-2015, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoDelay_Alg.h
 *
 *	\brief  Algorithm component definitions for DemoDelay_DynamicsLatencyComp.
 *
 *  \author Dave Tremblay
 */ 
/*================================================================================================*/

#pragma once
#ifndef DemoDelay_ALG_H
#define DemoDelay_ALG_H



// AAX includes
#include "AAX.h"

class CSimpleDelayLine;


//==============================================================================
// General definitions
//==============================================================================

// Meter layout
enum EDemoDelay_MeterTaps
{
	eMeterTap_Input = 0,
	eMeterTap_Output,
	
	eMeterTap_Count
};


//==============================================================================
// Algorithm Structures
//==============================================================================

#include AAX_ALIGN_FILE_BEGIN
#include AAX_ALIGN_FILE_ALG
#include AAX_ALIGN_FILE_END

// Gain coefficient structure (extend this to add more coeffs)
struct SDemoDelay_Coefs
{
    bool    mBypass;
    float	mDryGain;
    float   mWetGain;
};

// Context structure
struct SDemoDelay_AlgContext
{
	SDemoDelay_Coefs			* mCoefsDelayP;					// Inter-component message destination
	int32_t						* mDelaySamplesP;				// Inter-component message destination
	
	CSimpleDelayLine			* mDelayLineP;					// Private data
	
	float*						* mInputPP;						// Audio signal destination
	float*						* mOutputPP;					// Audio signal source
	int32_t						* mBufferLengthP;				// Buffer size
	
	float*						* mMeterOutputPP;				// Meter taps
};
#include AAX_ALIGN_FILE_BEGIN
#include AAX_ALIGN_FILE_RESET
#include AAX_ALIGN_FILE_END


//==============================================================================
// Callback declarations
//==============================================================================

void
AAX_CALLBACK
DemoDelay_AlgorithmProcessFunction (
									SDemoDelay_AlgContext * const	inInstancesBegin [],
									const void *					inInstancesEnd);

#endif //DemoDelay_ALG_H
