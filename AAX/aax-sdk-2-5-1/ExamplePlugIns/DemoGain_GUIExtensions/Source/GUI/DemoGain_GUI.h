/*================================================================================================*/
/*
 *	Copyright 2009-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoGain_GUI.h
 */ 
/*================================================================================================*/
#pragma once
#ifndef DEMOGAIN_GUI_H
#define DEMOGAIN_GUI_H

#if WINDOWS_VERSION
#include "DemoGain_GUI_Win32.h"
#else
#include "DemoGain_GUI_Cocoa.h"
#endif

#endif
