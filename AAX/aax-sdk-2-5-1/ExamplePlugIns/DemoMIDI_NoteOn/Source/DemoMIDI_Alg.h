/*================================================================================================*/
/*
 *	Copyright 2013-2017, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoMIDI_Alg.h
 *
 *	\brief  Algorithm component definitions for DemoDelay.
 *
 *  \author Danny Plazas
 */ 
/*================================================================================================*/
#pragma once
#ifndef DEMOMIDI_ALG_H
#define DEMOMIDI_ALG_H



// AAX includes
#include "AAX.h"
#include "AAX_IMIDINode.h"

//==============================================================================
// General definitions
//==============================================================================

// Meter layout
enum EDemoMIDI_MeterTaps
{
	eMeterTap_PreGain = 0,
	eMeterTap_PostGain,
	
	eMeterTap_Count
};


//==============================================================================
// Component context definitions
//==============================================================================

#include AAX_ALIGN_FILE_BEGIN
#include AAX_ALIGN_FILE_ALG
#include AAX_ALIGN_FILE_END

struct SDemoMIDI_NoteBits
{
	uint32_t mIsOn[4]; // one bit flag for each of the 128 possible note values
	int32_t mHoldState; // current state of the note hold
};

// Context structure
struct SDemoMIDI_Alg_Context
{
	int32_t						* mCtrlBypassP;					// Control message destination
	float						* mGainP;						// Coefficient message destination
	int32_t						* mCtrlHoldP;
	
	AAX_IMIDINode				* mMIDINodeInP;					// Buffered local MIDI input node Pointer
	AAX_IMIDINode				* mMIDINodeOutPassThroughP;		// Buffered local MIDI output node Pointer
	
	SDemoMIDI_NoteBits			* mIsOn;						// Private data
	
	float*						* mInputPP;						// Audio signal destination
	float*						* mOutputPP;					// Audio signal source
	int32_t						* mBufferSizeP;					// Buffer size
	float*						* mMetersPP;					// Meter taps
};

#include AAX_ALIGN_FILE_BEGIN
#include AAX_ALIGN_FILE_RESET
#include AAX_ALIGN_FILE_END


// Physical addresses within the context
enum EDemoMIDI_Alg_PortID
{
	eAlgPortID_BypassIn				= AAX_FIELD_INDEX (SDemoMIDI_Alg_Context, mCtrlBypassP)
	,eAlgPortID_CoefsGainIn			= AAX_FIELD_INDEX (SDemoMIDI_Alg_Context, mGainP)
	,eAlgPortID_HoldIn				= AAX_FIELD_INDEX (SDemoMIDI_Alg_Context, mCtrlHoldP)
	,eAlgPortID_MIDINodeIn			= AAX_FIELD_INDEX (SDemoMIDI_Alg_Context, mMIDINodeInP)
	,eAlgPortID_MIDINodeOutPT		= AAX_FIELD_INDEX (SDemoMIDI_Alg_Context, mMIDINodeOutPassThroughP)
	,eAlgPortID_IsOn				= AAX_FIELD_INDEX (SDemoMIDI_Alg_Context, mIsOn)
	,eAlgFieldID_AudioIn			= AAX_FIELD_INDEX (SDemoMIDI_Alg_Context, mInputPP)
	,eAlgFieldID_AudioOut			= AAX_FIELD_INDEX (SDemoMIDI_Alg_Context, mOutputPP)
	,eAlgFieldID_BufferSize			= AAX_FIELD_INDEX (SDemoMIDI_Alg_Context, mBufferSizeP)
	,eAlgFieldID_Meters				= AAX_FIELD_INDEX (SDemoMIDI_Alg_Context, mMetersPP)
};


//==============================================================================
// Callback declarations
//==============================================================================
/*
 void
 AAX_CALLBACK
 DemoMIDI_AlgorithmProcessFunction (
 SDemoMIDI_Alg_Context * const	inInstancesBegin [],
 const void *					inInstancesEnd);
 */

#endif
