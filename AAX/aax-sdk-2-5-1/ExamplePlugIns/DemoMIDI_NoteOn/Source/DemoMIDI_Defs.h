/*================================================================================================*/
/*
 *	Copyright 2013-2015, 2018, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoMIDI_Defs.h
 *
 *	\brief  Definitions shared by the DemoMIDI_NoteOn classes in one easy-to-maintain file.
 */ 
/*================================================================================================*/
#pragma once
#ifndef DEMOMIDI_DEFS_H
#define DEMOMIDI_DEFS_H

#include "AAX.h"			// for AAX_CTypeID

// Type, product, and relation IDs
const AAX_CTypeID cDemoMIDI_ManufactureID =			'AVID';
const AAX_CTypeID cDemoMIDI_ProductID =				'DmMD';
const AAX_CTypeID cDemoMIDI_PlugInID_Native =		'DmMR';
const AAX_CTypeID cDemoMIDI_PlugInID_AudioSuite =	'DmMA';

const AAX_CTypeID cDemoMIDI_MeterID [2] =			{'mtrI','mtrO'};

#define DemoMIDI_GainID			"Gain"
#define DemoMIDI_HoldID			"hold"

#endif // DEMOGAIN_DEFS_H
