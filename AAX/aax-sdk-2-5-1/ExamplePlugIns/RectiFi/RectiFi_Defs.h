/*================================================================================================*/
/*
 *	Copyright 2014-2017, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   RectiFiDefs.h
 *
 *	\brief  Definitions shared by the RectiFi classes in one easy-to-maintain file.
 */ 
/*================================================================================================*/

#ifndef RECTIFI_DEFS_H
#define RECTIFI_DEFS_H

#include "AAX.h"

/*===================================================================================================*/
#define RectiFi_ID_PreFilter		"Pre-Filter"
#define RectiFi_ID_Rectification	"Rectification"
#define RectiFi_ID_Gain				"Gain"
#define RectiFi_ID_PostFilter		"Post-Filter"
#define RectiFi_ID_Mix				"Mix"
//#define RectiFi_ID_WetDry			"Wet/Dry"
/*===================================================================================================*/
//Meter ID
#define cOutputMeterVal				'OutM'
#define cInputMeterVal				'InpM'

#define cOutputMeterValStereo		'OutS'
#define cInputMeterValStereo		'InpS'

const AAX_CTypeID cMeterIDs_Mono[] = { cInputMeterVal, cOutputMeterVal };
const AAX_CTypeID cMeterIDs_Stereo[] = { cInputMeterVal, cInputMeterValStereo, cOutputMeterVal, cOutputMeterValStereo };

#define RectiFi_Name_InputMeterL	"Input L"
#define RectiFi_Name_InputMeterR	"Input R"
#define RectiFi_Name_OutputMeterL	"Output L"
#define RectiFi_Name_OutputMeterR	"Output R"

/*===================================================================================================*/
const double kMaxFilterFrequency	=		(44100.0/2.0);
const double kMinFilterFrequency	=		(44100.0/1024.0);
/*===================================================================================================*/
#define kCompleteStateChunk			'All '

const AAX_CTypeID  	cManufacturerID		= 'AVID';
const AAX_CTypeID   kProductID			= 'RFex';

/*===================================================================================================*/
// Define the ProcessType here
const AAX_CTypeID   kASMToMProcessTypeID	= 'ASRF';	//AS

const AAX_CTypeID   kMMProcessTypeID		= 'T1RF';	//TDM
const AAX_CTypeID   kSSProcessTypeID		= 'T2RF';	//TDM

const AAX_CTypeID   kRTASMToMProcessTypeID	= 'HMRF';	//RTAS
const AAX_CTypeID   kRTASSToSProcessTypeID	= 'HSRF';	//RTAS

#endif // RECTIFI_DEFS_H
