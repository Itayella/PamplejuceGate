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
 *	\file   DemoGain_ViewControllerFactory.h
 *
 *	\brief  DemoGain_ViewControllerFactory class definition
 *
 *  \author David Hearst
 */ 
/*================================================================================================*/
class AAX_IEffectParameters;
class AAX_IController;
class AAX_IViewContainer;

@interface DemoGain_ViewControllerFactory : NSObject
{
}

- (NSViewController*)viewControllerFromBundle:(NSBundle*)bundle effectParameters:(AAX_IEffectParameters*)effectParameters
																controller:(AAX_IController*)controller;

@end
