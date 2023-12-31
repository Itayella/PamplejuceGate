/*================================================================================================*/
/*
 *	Copyright 2008-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoGain_Defs.h
 *
 *	\brief  Definitions shared by the DemoDist_DMA classes in one easy-to-maintain file.
 */ 
/*================================================================================================*/

#pragma once
#ifndef DEMOGAIN_DEFS_H
#define DEMOGAIN_DEFS_H

#include "AAX.h"			// for AAX_CTypeID

// Effect IDs
const AAX_CEffectID kEffectID_DemoGain			= "com.avid.aax.sdk.demogain.dma";
const AAX_CEffectID kEffectID_DemoGain_DMASG	= "com.avid.aax.sdk.demogain.dma.scattergather";
const AAX_CEffectID kEffectID_DemoGain_DMABurst	= "com.avid.aax.sdk.demogain.dma.burst";

// Type, product, and relation IDs
const AAX_CTypeID cDemoGain_ManufactureID =                 'AVID';
const AAX_CTypeID cDemoGain_ProductID =                     'DGDM';
const AAX_CTypeID cDemoGain_DMASG_PlugInID_Native =         'GsgN';
const AAX_CTypeID cDemoGain_DMASG_PlugInID_AudioSuite =     'GsgA';
const AAX_CTypeID cDemoGain_DMASG_PlugInID_TI =             'GsgT';
const AAX_CTypeID cDemoGain_DMABurst_PlugInID_Native =      'GbrN';
const AAX_CTypeID cDemoGain_DMABurst_PlugInID_AudioSuite =  'GbrA';
const AAX_CTypeID cDemoGain_DMABurst_PlugInID_TI =          'GbrT';


// Meter layout
enum EDemoGain_MeterTaps
{
	eMeterTap_PreGain = 0,
	eMeterTap_PostGain,
	
	eMeterTap_Count
};

const AAX_CTypeID cDemoGain_MeterID [2] =			{'mtrI','mtrO'};


#define DemoGain_GainID		"Gain"

#endif // DEMOGAIN_DEFS_H
