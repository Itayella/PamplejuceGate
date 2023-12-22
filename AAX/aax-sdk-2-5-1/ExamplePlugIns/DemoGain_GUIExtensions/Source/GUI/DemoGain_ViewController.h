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
 *	\file   DemoGain_ViewController.h
 *
 *	\brief  DemoGain_ViewController class definition.
 */ 
/*================================================================================================*/
#import <Cocoa/Cocoa.h>

#import "DemoGain_SliderCocoa.h"

#import <AppKit/NSTextField.h>
#import <AppKit/NSLevelIndicator.h>

class AAX_IEffectParameters;
class AAX_IController;
class AAX_IViewContainer;

// *******************************************************
// INTERFACE:	DemoGain_ViewController
// *******************************************************
@interface DemoGain_ViewController : NSViewController <NSTextFieldDelegate>
{	
	IBOutlet DemoGain_SliderCocoa *	mGainSlider;
	IBOutlet NSTextField *		mGainText;
	IBOutlet NSLevelIndicator * mInputLevelIndicator;
	IBOutlet NSLevelIndicator * mOutputLevelIndicator;
	
	AAX_IEffectParameters *		mEffectParameters;
	AAX_IController *			mController;
}

@property (nonatomic, retain) DemoGain_SliderCocoa *		mGainSlider;
@property (nonatomic, retain) NSTextField *			mGainText;
@property (nonatomic, retain) NSLevelIndicator *	mInputLevelIndicator;
@property (nonatomic, retain) NSLevelIndicator *	mOutputLevelIndicator;

- (void)		SetParameters:(AAX_IEffectParameters *) iEffectParameters;
- (void)		SetController:(AAX_IController *) iController;
- (void)		SetViewContainerOnViews:(AAX_IViewContainer *) iViewContainer; // Should be called after views have been created
- (void)		SetEffectParametersOnViews:(AAX_IEffectParameters *) iEffectParameters; // Should be called after views have been created
- (void)		UpdateGainValues;
- (void)		UpdateMeters;
- (void)		controlTextDidEndEditing:(NSNotification *)obj;
- (IBAction)	ChangeGainSlider:(id) iSender;
//- (IBAction)	ChangeGainText:(id) iSender;

@end
