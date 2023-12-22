/*================================================================================================*/
/*
 *	Copyright 2013-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license. TO ANY THIRD-PARTY WITHOUT THE PRIOR WRITTEN	CONSENT 
 *	OF Avid Technology, INC.
 */
/*================================================================================================*/

#include "CSimpleDelayLine.h"

#include <cstring>


//==============================================================================
// CSimpleDelayLine definition
//==============================================================================

CSimpleDelayLine::CSimpleDelayLine()
: mPos(0)
{
	Clear();
}

CSimpleDelayLine::~CSimpleDelayLine()
{
}

void CSimpleDelayLine::ProcessSamples(int32_t inNumSamples, uint32_t inDelaySamples, const float* inAudioInput, float* outAudioOutput)
{
    //Write the new values into the delay line and pull the output values out.
    for (int32_t index=0; index < inNumSamples; ++index, ++mPos)
    {
        mDelayLine[mPos & sDelayLineMask] = inAudioInput[index];
        outAudioOutput[index] = mDelayLine[(mPos-inDelaySamples) & sDelayLineMask];
    }
}

void CSimpleDelayLine::Clear()
{
	std::memset(mDelayLine, 0, sDelayLineLength*sizeof(float));
}
