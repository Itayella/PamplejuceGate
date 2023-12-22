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
 *  \file AAX_PlugInBundleLocation.h
 *
 *	\brief	Utilities for interacting with the host OS
 */
/*================================================================================================*/
/// @cond ignore
#ifndef AAX_PLUGINBUNDLELOCATION_H
#define AAX_PLUGINBUNDLELOCATION_H
/// @endcond

namespace AAX
{
	/** @name Filesystem utilities
	 */
	//@{
    /** @brief Retrieve the file path of the .aaxplugin bundle
     
     @details
     @param[in] iBundleName
     - OS X: The @c CFBundleIdentifier value set in the plug-in's .plist file
     - Other: This parameter is ignored
     @param[in] iMaxLength
     @param[out] oModuleName
     A preallocated buffer of size @c iMaxLength
     
     @ingroup OtherExtensions
     */
    bool GetPathToPlugInBundle (const char* iBundleName, int iMaxLength, char* oModuleName);
    //@} Filesystem utilities
}

/// @cond ignore
#endif
/// @endcond
