/*================================================================================================*/
/*
 *	Copyright 2008-2015, 2018, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoGain_Defs.h
 *
 *	\brief  Definitions shared by the DemoGain_LinkedParameters classes in one easy-to-maintain file.
 */ 
/*================================================================================================*/
#pragma once
#ifndef DEMOGAIN_DEFS_H
#define DEMOGAIN_DEFS_H

#include "AAX.h"			// for AAX_CTypeID

// Effect IDs
const AAX_CEffectID kEffectID_DemoGain =			"com.avid.aax.sdk.demogain.link";

// Type, product, and relation IDs
const AAX_CTypeID cDemoGain_ManufactureID =			'AVID';
const AAX_CTypeID cDemoGain_ProductID =				'DmGL';
const AAX_CTypeID cDemoGain_PlugInID_Native =		'DGDR';
const AAX_CTypeID cDemoGain_PlugInID_AudioSuite =	'DGDA';
const AAX_CTypeID cDemoGain_PlugInID_TI =			'DGDT';

const AAX_CTypeID cDemoGain_MeterID [4] =			{'mtIL','mtIR','mtOL','mtOR'};

#define DemoGain_GainLeftID		"Gain Left"
#define DemoGain_GainRightID	"Gain Right"
#define DemoGain_LinkToggleID	"Link"
#define DemoGain_TypeToggleID	"Type"

#endif // DEMOGAIN_DEFS_H
