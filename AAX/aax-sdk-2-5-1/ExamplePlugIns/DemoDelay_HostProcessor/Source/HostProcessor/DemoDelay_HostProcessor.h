/*================================================================================================*/
/*
 *	Copyright 2013-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoDelay_HostProcessor.h
 *
 *  \author Rob Majors
 */ 
/*================================================================================================*/

#ifndef __DemoDelay_HostProcessor__DemoDelay_HostProcessor__
#define __DemoDelay_HostProcessor__DemoDelay_HostProcessor__

#include "AAX_CHostProcessor.h"
#include <stdint.h>

class CSimpleDelayLine;

class DemoDelay_HostProcessor : public AAX_CHostProcessor
{
public:
	//Construction and destruction
	static AAX_CHostProcessor *AAX_CALLBACK	Create();
	/* default constructor */				DemoDelay_HostProcessor (void);
	virtual /* destructor */				~DemoDelay_HostProcessor();
	
	//Overrides from AAX_CHostProcessor
	virtual AAX_Result	RenderAudio ( const float * const inAudioIns [], int32_t inAudioInCount, float * const inAudioOuts [], int32_t inAudioOutCount, int32_t * ioWindowSize );
	virtual AAX_Result	PreRender ( int32_t iAudioInCount, int32_t iAudioOutCount, int32_t iWindowSize );
	virtual AAX_Result	PostRender ();
	
private:
	void CreateDelayLines(int32_t inNumDelayLines);
	void DeleteDelayLines();
	
	CSimpleDelayLine* mDelayLines;
	int32_t mDelaySamples;
};

#endif /* defined(__DemoDelay_HostProcessor__DemoDelay_HostProcessor__) */
