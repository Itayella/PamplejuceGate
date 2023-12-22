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
#include "RectiFi_Alg.h"
#include "RectiFi_AlgProc.cpp"		// Needed for templates
#include "AAX.h"
#include "../TI/CCSv5/elf_linkage_aax_ccsv5.h"

const AAX_EStemFormat kStemFormat = AAX_eStemFormat_Stereo;
const int kNumChannels = AAX_STEM_FORMAT_CHANNEL_COUNT(kStemFormat);

// The main algorithm entry point
extern "C"
TI_EXPORT
void AlgEntry(	SRectiFi_Algorithm_Context * const		inInstancesBegin [],
				const void *						inInstancesEnd)
{
	RectiFi_Algorithm_ProcessFunction<kNumChannels, kNumChannels, 1 << AAX_eAudioBufferLengthDSP_Default>(
				inInstancesBegin,
				inInstancesEnd);
}

