/*================================================================================================*/
/*
 *	Copyright 2010-2015, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**	
 *  \file AAX_CEffectGUI_Cocoa.h
 *
 */
/*================================================================================================*/

#ifndef AAX_CEFFECTGUI_COCOA_H
#define AAX_CEFFECTGUI_COCOA_H

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#else
class NSWindow;
class NSViewController;
class NSView;
#endif

#include "AAX_CEffectGUI.h"

#include <string>
#include <vector>

class AAX_CEffectGUI_Cocoa : public AAX_CEffectGUI
{
public:
	AAX_CEffectGUI_Cocoa ();
	~AAX_CEffectGUI_Cocoa () AAX_OVERRIDE;

protected:
	AAX_Result	GetViewSize ( AAX_Point * oEffectViewSize ) const AAX_OVERRIDE;
	void		CreateViewContainer () AAX_OVERRIDE;
	void		DeleteViewContainer () AAX_OVERRIDE;

	void		SetViewController ( NSViewController * iViewController ) { mViewController = iViewController; }
	void		AddViewContents ();

protected:
	NSView *			mNSView;	
	NSViewController *	mViewController;
};

#endif //AAX_CEFFECTGUI_COCOA_H
