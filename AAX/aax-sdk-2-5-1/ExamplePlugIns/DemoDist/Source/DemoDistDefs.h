/*================================================================================================*/
/*
 *	Copyright 2014-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoDistDefs.h
 *
 *	\brief  Definitions shared by the DemoDelay classes in one easy-to-maintain file.
 */ 
/*================================================================================================*/

#pragma once
#ifndef __DEMODISTDEFS__H__
#define __DEMODISTDEFS__H__

#include "AAX.h"			// for AAX_CTypeID


// Type, product, and relation IDs
const AAX_CTypeID cDemoDist_ManufactureID =			'AVID';
const AAX_CTypeID cDemoDist_ProductID =				'DmDE';

const AAX_CTypeID cDemoDist_TypeID_AS =				'DmAS';
const AAX_CTypeID cDemoDist_TypeID_MonoNative =		'DmRT';
const AAX_CTypeID cDemoDist_TypeID_StereoNative =	'DsRT';

const AAX_CTypeID cDemoDist_TypeID_MonoTI =			'DDT1';
const AAX_CTypeID cDemoDist_TypeID_StereoTI =		'DDT2';


// Meter IDs
const AAX_CTypeID cDemoDist_MeterID_In =			'Min ';
const AAX_CTypeID cDemoDist_MeterID_InL =			'MinL';
const AAX_CTypeID cDemoDist_MeterID_InR =			'MinR';
const AAX_CTypeID cDemoDist_MeterID_DistOut =		'MdsO';
const AAX_CTypeID cDemoDist_MeterID_DistL =			'MdsL';
const AAX_CTypeID cDemoDist_MeterID_DistR =			'MdsR';

const AAX_CTypeID cDemoDist_MeterID_Mono [2] =		{cDemoDist_MeterID_In,
													cDemoDist_MeterID_DistOut};

const AAX_CTypeID cDemoDist_MeterID_Stereo [4] =	{cDemoDist_MeterID_InL,
                                                    cDemoDist_MeterID_InR,
												    cDemoDist_MeterID_DistL,
                                                    cDemoDist_MeterID_DistR};



// Default values for the DemoDist plug-in:

// Control defaults
const float cDefaultParameterMix	= 1.0f;
const float cDefaultParameterFilt	= 0.33f;
const float cDefaultParameterDist	= 0.8f;
const float cDefaultParameterInpG	= 1.0f;
const float cDefaultParameterOutG	= 0.2f;

// Algorithm constants
const float cDistortionPower	= 6.0f;

// Parameter IDs
#define DemoDist_MixID		"Mix"
#define DemoDist_FiltID		"Lowpass"
#define DemoDist_DistID		"Distortion"
#define DemoDist_InpGID		"Input Gain"
#define DemoDist_OutGID		"Output Gain"

#endif // __DEMODISTDEFS__H__







