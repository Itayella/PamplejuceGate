/*================================================================================================*/
/*
 *	Copyright 2010-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/

#include "AAX_CEffectGUI_Juce.h"

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#endif

// *******************************************************************************
// METHOD:	AAX_CEffectGUI_Juce::CreateViewContainer
// *******************************************************************************
void AAX_CEffectGUI_Juce::CreateViewContainer ()
{
	void* nativeViewToAttachTo = NULL;
	
	if ( this->GetViewContainerType () == AAX_eViewContainer_Type_NSView )
	{
		nativeViewToAttachTo = ((NSView *) this->GetViewContainerPtr () );
	}
	
	if ( nativeViewToAttachTo && mViewComponent )
	{
		mViewComponent->SetViewContainer ( this->GetViewContainer () );
		mViewComponent->addToDesktop ( 0, nativeViewToAttachTo );
	}
}

// *******************************************************************************
// METHOD:	AAX_CEffectGUI_Juce::DeleteViewContainer
// *******************************************************************************
void AAX_CEffectGUI_Juce::DeleteViewContainer ()
{
	NSAutoreleasePool* autoreleasePool = [[NSAutoreleasePool alloc] init];
	if (mViewComponent)
	{
		mViewComponent->SetViewContainer ( 0 );
		mViewComponent->removeFromDesktop ();
	}
	
	[autoreleasePool release];
}
