/*================================================================================================*/
/*
 *	Copyright 2012-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoSampler_SampleBase.h
 *
 *	\brief  Definitions shared by the DemoMIDI_Sampler classes in one easy-to-maintain file.
 */ 
/*================================================================================================*/
#pragma once
#ifndef _DEMOSAMPLERSAMPLEBASE
#define _DEMOSAMPLERSAMPLEBASE

#include "AAX.h"

const int32_t bass_size = 44096;
extern float bass_bank[bass_size];

const int32_t snare_size = 14992;
extern float snare_bank[snare_size];

const int32_t tom_size = 10192;
extern float tom_bank[tom_size];

#endif	//	_DEMOSAMPLERSAMPLEBASE
