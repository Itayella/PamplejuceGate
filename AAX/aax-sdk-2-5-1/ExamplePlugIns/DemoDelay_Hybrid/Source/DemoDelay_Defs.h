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
 *	\file   DemoDelay_Defs.h
 *
 *	\brief  Definitions shared by the DemoDelay_Hybrid classes in one easy-to-maintain file.
 *
 *  \author Dave Tremblay
 */ 
/*================================================================================================*/
#pragma once
#ifndef DemoDelay_DEFS_H
#define DemoDelay_DEFS_H

#include "AAX.h"			// for AAX_CTypeID


// Type, product, and relation IDs
const AAX_CTypeID cDemoDelay_ManufactureID =		'AVID';
const AAX_CTypeID cDemoDelay_ProductID =			'DmDH';
const AAX_CTypeID cDemoDelay_PlugInID_Native =		'DHna';
const AAX_CTypeID cDemoDelay_PlugInID_TI =			'DHti';

const AAX_CTypeID cDemoDelay_MeterID [2] =			{'mtrI','mtrO'};

#define DemoDelay_DelayID		"Delay"

#endif // DemoDelay_DEFS_H
