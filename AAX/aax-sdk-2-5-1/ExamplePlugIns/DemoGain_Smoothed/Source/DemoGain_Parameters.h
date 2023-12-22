/*================================================================================================*/
/*
 *	Copyright 2009-2015, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoGain_Parameters.h
 *
 *	\brief  DemoGain_Parameters class declaration.
 */ 
/*================================================================================================*/ 
#pragma once
#ifndef DEMOGAIN_PARAMETERS_H
#define DEMOGAIN_PARAMETERS_H

#include "AAX_CEffectParameters.h"


class DemoGain_Parameters : public AAX_CEffectParameters
{
public:
	DemoGain_Parameters (void);
	AAX_DEFAULT_DTOR_OVERRIDE (DemoGain_Parameters);
	
	// Create callback
	static AAX_CEffectParameters *AAX_CALLBACK Create();

public:
	//Overrides from AAX_CEffectParameters
	AAX_Result EffectInit() AAX_OVERRIDE;

private:
	AAX_Result UpdatePacket_Gain(AAX_CPacket& ioPacket);
};


#endif
