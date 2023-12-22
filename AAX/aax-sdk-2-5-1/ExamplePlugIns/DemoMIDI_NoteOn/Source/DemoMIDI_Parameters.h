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
 *	\file   DemoMIDI_Parameters.h
 *
 *	\brief  DemoMIDI_Parameters class declaration.
 */ 
/*================================================================================================*/ 
#pragma once
#ifndef DEMOMIDI_PARAMETERS_H
#define DEMOMIDI_PARAMETERS_H

#include "AAX_CEffectParameters.h"

//==============================================================================
class DemoMIDI_Parameters : public AAX_CEffectParameters
{
public:
	
	//Constructor
	DemoMIDI_Parameters (void);
	static AAX_CEffectParameters *AAX_CALLBACK	Create();
	
	//Overrides from AAX_CEffectParameters
	virtual AAX_Result							EffectInit();
	
	// Override this method to receive MIDI 
	// packets for the described MIDI nodes
	virtual AAX_Result							UpdateMIDINodes ( AAX_CFieldIndex inFieldIndex,	AAX_CMidiPacket& inPacket );
};

#endif
