/*================================================================================================*/
/*
 *	Copyright 2012-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/

#import "DemoGain_SliderCellCocoa.h"

#include "DemoGain_SliderCocoa.h"

@implementation DemoGain_SliderCellCocoa

- (BOOL)continueTracking:(NSPoint)lastPoint at:(NSPoint)currentPoint inView:(NSView *)controlView
{
	// HACK? We all know that this is the right class for
	// this object, and other solutions seem too obtuse.
	DemoGain_SliderCocoa* sliderView;
	sliderView = (DemoGain_SliderCocoa* )[self controlView];
	if ([sliderView GetDefaultCommandState])
	{
		return YES;
	}
	else
	{
		return [super continueTracking:lastPoint at:currentPoint inView:controlView];
	}
}

- (void)stopTracking:(NSPoint)lastPoint at:(NSPoint)stopPoint inView:(NSView *)controlView mouseIsUp:(BOOL)flag
{
	// Call inherited first in order to release the control after the final update has been submitted
	[super stopTracking:lastPoint at:stopPoint inView:controlView mouseIsUp:flag];
	
	// HACK? We all know that this is the right class for
	// this object, and other solutions seem too obtuse.
	DemoGain_SliderCocoa* sliderView;
	sliderView = (DemoGain_SliderCocoa* )[self controlView];
	[sliderView EndControlEditEvent];
}

@end
