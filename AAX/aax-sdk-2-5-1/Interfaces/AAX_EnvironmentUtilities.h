/*================================================================================================*/
/*

	AAX_EnvironmentUtilities.h

	Copyright 2018-2019, 2023 Avid Technology, Inc.
	All rights reserved.
	
	CONFIDENTIAL: this document contains confidential information of Avid. Do
	not disclose to any third party. Use of the information contained in this
	document is subject to an Avid SDK license.
*/

/**
 *	\file AAX_EnvironmentUtilities.h
 *
 *	\brief Useful environment definitions for %AAX
 *
 */
/*================================================================================================*/

#ifndef _AAX_ENVIRONMENTUTILITIES_H_
#define _AAX_ENVIRONMENTUTILITIES_H_

#include <cstdlib>

#if (!defined (WINDOWS_VERSION))
#  if (defined (_WIN32))
#    define WINDOWS_VERSION 1
#  endif
#elif (defined (MAC_VERSION) || defined (LINUX_VERSION))
#  error "AAX SDK: Cannot declare more than one OS environment"
#endif

#if (!defined (MAC_VERSION))
#  if (defined (__APPLE__) && defined (__MACH__))
#    include "TargetConditionals.h"
#    if (TARGET_OS_MAC)
#      define MAC_VERSION 1
#    endif
#  endif
#elif (defined (WINDOWS_VERSION) || defined (LINUX_VERSION))
#  error "AAX SDK: Cannot declare more than one OS environment"
#endif

#if (!defined (LINUX_VERSION))
#  if (defined (__linux__))
#    define LINUX_VERSION 1
#  endif
#elif (defined (WINDOWS_VERSION) || defined (MAC_VERSION))
#  error "AAX SDK: Cannot declare more than one OS environment"
#endif

#if (!defined (WINDOWS_VERSION) && !defined (MAC_VERSION) && !defined (LINUX_VERSION))
#  warning "AAX SDK: Unknown OS environment"
#endif

namespace AAX
{
    static bool IsVenueSystem(void)
    {
#if WINDOWS_VERSION
    	static const char * const environmentVariableName = "JEX_HOST_TYPE";
    	static const char * const venueEnvironment = "venue";
    	static const char * const environment = std::getenv ( environmentVariableName );
    	static const bool isVenue = ( NULL != environment) && (0 == strcmp ( environment, venueEnvironment ) );
    	return isVenue;
#else
        return false;
#endif
    }
}

#endif // _AAX_ENVIRONMENTUTILITIES_H_
