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
 *	\file   DemoSampler_Defs.h
 *
 *	\brief  Definitions shared by the DemoMIDI_Sampler classes in one easy-to-maintain file.
 *
 *  \author Andriy Goshko
 */ 
/*================================================================================================*/
#pragma once
#ifndef DEMOSAMPLER_DEFS_H
#define DEMOSAMPLER_DEFS_H

#include "AAX.h"			// for AAX_CTypeID

// Type, product, and relation IDs
const AAX_CTypeID cDemoSampler_ManufactureID =			'AVID';
const AAX_CTypeID cDemoSampler_ProductID =				'DmSM';
const AAX_CTypeID cDemoSampler_PlugInID_Native =		'DmSR';
const AAX_CTypeID cDemoSampler_PlugInID_AudioSuite =	'DmSA';

#define kSupportedSR									44100

#endif // DEMOGAIN_DEFS_H
