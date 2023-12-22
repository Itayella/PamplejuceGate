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
 *	\file   DemoSynth_Defs.h
 *
 *	\brief  Definitions shared by the DemoMIDI_Synth classes in one easy-to-maintain file.
 *
 *  \author Andriy Goshko 
 */ 
/*================================================================================================*/
#pragma once
#ifndef DEMOSYNTH_DEFS_H
#define DEMOSYNTH_DEFS_H

#include "AAX.h"			// for AAX_CTypeID

// Type, product, and relation IDs
static const AAX_CTypeID cDemoSynth_ManufactureID =				'AVID';
static const AAX_CTypeID cDemoSynth_ProductID =					'DmSY';
static const AAX_CTypeID cDemoSynth_PlugInID_Native_Mono =		'mono';
static const AAX_CTypeID cDemoSynth_PlugInID_Native_Stereo =	'ster';
static const AAX_CTypeID cDemoSynth_PlugInID_AudioSuite =		'offl';

#endif // DEMOGAIN_DEFS_H
