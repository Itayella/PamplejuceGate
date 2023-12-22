/*================================================================================================*/
/*
 *	Copyright 2011-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoGain_SliderCocoa.h
 *
 *	\brief	DemoGain_SliderCocoa class definition.
 *
 *  \author Rob Majors
 */ 
/*================================================================================================*/
#import <Cocoa/Cocoa.h>
#import <AppKit/NSSlider.h>

class AAX_IViewContainer;
class AAX_IEffectParameters;

@interface DemoGain_SliderCocoa : NSSlider
{
	AAX_IViewContainer *		mViewContainer;
	AAX_IEffectParameters *		mEffectParameters;
	
	boolean_t					mSetToDefault;
}

- (void)		SetViewContainer:(AAX_IViewContainer *) iViewContainer;
- (void)		SetEffectParameters:(AAX_IEffectParameters *) iEffectParameters;
- (void)		BeginControlEditEvent:(boolean_t) iDefaultCommandState;
- (void)		EndControlEditEvent;
- (boolean_t)	GetDefaultCommandState;
- (void)		SetDefaultCommandState:(boolean_t) iDefaultCommandState;
- (uint32_t)	GetAAXModifiersFromNSEvent:(NSEvent *) theEvent;

@end
