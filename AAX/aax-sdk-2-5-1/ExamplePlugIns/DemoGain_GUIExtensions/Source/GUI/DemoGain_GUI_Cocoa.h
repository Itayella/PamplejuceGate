/*================================================================================================*/
/*
 *	Copyright 2009-2015, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoGain_GUI_Cocoa.h
 *
  *	\brief	DemoGain_GUI class definition.
 */ 
/*================================================================================================*/
#pragma once
#ifndef DEMOGAIN_GUI_COCOA_H
#define DEMOGAIN_GUI_COCOA_H

#include "AAX_CEffectGUI_Cocoa.h"

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#import "DemoGain_ViewController.h"
#else
class DemoGain_ViewController;
#endif

//==============================================================================
class DemoGain_GUI : public AAX_CEffectGUI_Cocoa
{
public:
	static AAX_IEffectGUI *		AAX_CALLBACK Create ();

	DemoGain_GUI();
	~DemoGain_GUI() AAX_OVERRIDE;

	void				CreateViewContents () AAX_OVERRIDE;
	AAX_Result			ParameterUpdated ( AAX_CParamID iParameterID ) AAX_OVERRIDE;
	AAX_Result			TimerWakeup() AAX_OVERRIDE;
	
protected:
	void				CreateViewContainer () AAX_OVERRIDE; // AAX_CEffectGUI_Cocoa

private:
	DemoGain_ViewController	*	mDemoGainViewController;
};

#endif
