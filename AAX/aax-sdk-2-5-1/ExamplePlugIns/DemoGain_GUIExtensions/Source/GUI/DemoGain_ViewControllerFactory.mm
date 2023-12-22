/*================================================================================================*/
/*
 *	Copyright 2011-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/

#import "DemoGain_ViewControllerFactory.h"

#import "DemoGain_ViewController.h"

#import "AAX_IEffectParameters.h"
#import "AAX_IController.h"
#import "AAX_IViewContainer.h"

@implementation DemoGain_ViewControllerFactory

// will need PT controller and PT parameters as opaque arguments
- (NSViewController*)viewControllerFromBundle:(NSBundle*)bundle
							effectParameters:(AAX_IEffectParameters*)effectParameters
							controller:(AAX_IController*)controller
{
    DemoGain_ViewController* viewController = [[DemoGain_ViewController alloc] initWithNibName:@"DemoGain_View" bundle:bundle];
    assert(viewController != nil);
        
	[viewController SetParameters:effectParameters ];
	[viewController SetController:controller ];

    return viewController;
}

@end
