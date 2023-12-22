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
#include "AAX_CEffectGUI_VST.h"

#import <Cocoa/Cocoa.h>

// *******************************************************************************
// METHOD:	AAX_CEffectGUI_VST::CreateViewContainer
// *******************************************************************************
void AAX_CEffectGUI_VST::CreateViewContainer ()
{
	if ( this->GetViewContainerType () == AAX_eViewContainer_Type_NSView )
	{
		NSView * theView = (NSView *) this->GetViewContainerPtr ();
		if ( theView )
		{
#if MAC_COCOA && MAC_CARBON
			CFrame::setCocoaMode ( true );
#endif
			this->CreateEffectView ( theView );
		}
	}
}
