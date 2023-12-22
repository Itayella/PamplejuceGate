/*================================================================================================*/
/*
 *	Copyright 2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   CSimpleSynth.h
 *
 *  \author Rob Majors
 */ 

/*================================================================================================*/
#ifndef __DemoMIDI_Synth__CSimpleSynth__
#define __DemoMIDI_Synth__CSimpleSynth__

#include "CSimpleTone.h"


//================================================================================
// Synthesizer

/** \brief A simple polyphonic synthesizer class
 
 Uses: CSimpleTone
 
 This class is decoupled from any AAX-specific details. This example is
 designed to mimic the kind of custom processing class that is often
 created for cross-format plug-in development.
 */
class CSimpleSynth
{
public:
	enum EWaveType
	{
		eWaveType_Begin = 0
		,eWaveType_Saw = eWaveType_Begin
		,eWaveType_Tri = 1
		,eWaveType_Square = 2
		,eWaveType_End
	};
	
public:
	CSimpleSynth();
	
public:
	void SetBypass(bool inBypass);
	void SetGain(float inGain);
	void SetWaveType(EWaveType inWaveType);
	void SetTuning(float inAHz);
	
	void InitializeVoices(float inSampleRate, float inAHz);
	int32_t MaxNumVoices() const;
	static const char* GetWaveTypeName(EWaveType inWaveType);
	
public:
	void GetSamples(float* outBuffer, int32_t outBufferSize);
	void HandleNoteOn(unsigned char inNote, unsigned char inVelocity);
	void HandleNoteOff(unsigned char inNote, unsigned char inVelocity);
	void HandleAllNotesOff();
	
private:
	static const IToneGeneratorDelegate* GetToneGenerator(EWaveType inWaveType);
	
private:
	CSimpleTone						mVoices[128];
	bool							mBypassed;
	float							mGain;
	const IToneGeneratorDelegate*	mToneGenerator;
};

#endif /* defined(__DemoMIDI_Synth__CSimpleSynth__) */
