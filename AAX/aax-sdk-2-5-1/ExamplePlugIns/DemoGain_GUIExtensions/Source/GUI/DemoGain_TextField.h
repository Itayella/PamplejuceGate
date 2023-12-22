/*================================================================================================*/
/*
 *	Copyright 2010-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoGain_TextField.h
 *
 */ 
/*================================================================================================*/
#import <Cocoa/Cocoa.h>
#import <AppKit/NSTextField.h>

@interface DemoGain_TextField : NSTextField
{	
	NSColor	* mOrigTextColor;
	NSColor	* mOrigBackgroundColor;
}

@property (nonatomic, retain) NSColor *	mOrigTextColor;
@property (nonatomic, retain) NSColor *	mOrigBackgroundColor;

@end
