/*================================================================================================*/
/*
 *	Copyright 2013-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/

#include "AAX_CEffectGUI_Cocoa.h"
#include "AAX_IParameter.h"

// *******************************************************************************
// METHOD:	AAX_CEffectGUI_Cocoa
// *******************************************************************************
AAX_CEffectGUI_Cocoa::AAX_CEffectGUI_Cocoa()
:   mNSView(0),
    mViewController(0)
{
}

// *******************************************************************************
// METHOD:	~AAX_CEffectGUI_Cocoa
// *******************************************************************************
AAX_CEffectGUI_Cocoa::~AAX_CEffectGUI_Cocoa()
{
	this->DeleteViewContainer ();
}

// *******************************************************************************
// METHOD:	CreateViewContainer
// *******************************************************************************
void AAX_CEffectGUI_Cocoa::CreateViewContainer ()
{
	if ( this->GetViewContainerType ()  == AAX_eViewContainer_Type_NSView )
	{
		mNSView = (NSView *) this->GetViewContainerPtr ();
		this->AddViewContents ();
	}
}

// *******************************************************************************
// ROUTINE:	AddViewContents
// *******************************************************************************
void AAX_CEffectGUI_Cocoa::AddViewContents ()
{	
	if ( mNSView && mViewController )
	{
		if ( mViewController && mViewController.view )
			[mNSView addSubview:mViewController.view];
	}
}

// *******************************************************************************
// ROUTINE:	DeleteViewContainer
// *******************************************************************************
void AAX_CEffectGUI_Cocoa::DeleteViewContainer ()
{	
	if ( mNSView && mViewController && mViewController.view )
	{
		[mViewController.view removeFromSuperview];
		[mViewController release];
		mViewController = 0;
	}
}	

// *******************************************************************************
// METHOD:	GetViewSize
// *******************************************************************************
AAX_Result AAX_CEffectGUI_Cocoa::GetViewSize ( AAX_Point *oEffectViewSize ) const
{
	if ( mViewController && mViewController.view )
	{
		oEffectViewSize->horz = mViewController.view.frame.size.width;
		oEffectViewSize->vert = mViewController.view.frame.size.height;
	}

	return AAX_SUCCESS;
}
