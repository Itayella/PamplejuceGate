/*================================================================================================*/
/*
 *	Copyright 2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**	
 *      \file   AAX_PlugInBundleLocation.mm
 *
 *	\brief	Utilities for interacting with the host OS
 */
/*================================================================================================*/
#include "AAX_PlugInBundleLocation.h"

#import <Foundation/Foundation.h>

bool AAX::GetPathToPlugInBundle (const char* iBundleName, int iMaxLength, char* oModuleName)
{
    if (!oModuleName || !iBundleName)
        return false;
    
    @autoreleasepool
    {
        NSString * bundleIdentifier = [NSString stringWithFormat:@"%s", iBundleName];;
        NSBundle * bundle = [ NSBundle bundleWithIdentifier: bundleIdentifier ];
        NSString * bundlePath = [bundle bundlePath];
        strncpy(oModuleName, bundlePath.UTF8String, iMaxLength);
    }
    
    if (!strlen(oModuleName))
        return false;
    
    return true;
}
