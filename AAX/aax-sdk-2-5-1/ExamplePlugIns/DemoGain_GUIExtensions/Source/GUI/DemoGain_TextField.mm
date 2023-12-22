/*================================================================================================*/
/*
 *	Copyright 2009-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/
#import  "DemoGain_TextField.h"


@implementation DemoGain_TextField

@synthesize	mOrigTextColor;
@synthesize	mOrigBackgroundColor;

- (void)awakeFromNib
{
	mOrigTextColor = [[self textColor] copy];
	mOrigBackgroundColor = [[self backgroundColor] copy];
}

- (BOOL) becomeFirstResponder
{
	BOOL result = [super becomeFirstResponder];
	if ( result )
	{
		[self setTextColor:[NSColor blackColor]];
		[self setBackgroundColor:[NSColor whiteColor]];
	}
		
	return result;
}

- (void)textDidEndEditing:(NSNotification *)notification
{
	[super textDidEndEditing:notification];

	[self setTextColor:mOrigTextColor];
	[self setBackgroundColor:mOrigBackgroundColor];

}

@end

