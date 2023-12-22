/*================================================================================================*/
/*
 *	Copyright 2009-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file  AAX_PlatformOptimizationConstants.h
 *
 *	\brief Constants descriptor...
 *
 */ 
/*================================================================================================*/
#pragma once

#ifndef AAX_PLATFORMOPTIMIZATIONCONSTANTS_H
#define AAX_PLATFORMOPTIMIZATIONCONSTANTS_H

// Set up our platform-specific optimization defines
#if USE_PLATFORM_OPTIMIZATION
	#if defined( WINDOWS_VERSION )
			#define USE_INTEL_IPP (1)		// Windows
			#define __SSE__ (1)				// Manually define the __SSE__ flag
	#elif defined( MAC_VERSION )
		#if defined(__ppc__)
			#define USE_ALTIVEC_VDSP (1)	// PPC
		#elif defined(__i386__) or defined(__x86_64__)
			#define USE_INTEL_IPP (1)		// MacTel
		#else
			#error "Unsupported platform for optimizations!"
		#endif // __i386__ or __ppc__
	#else
		#error "Unsupported platform for optimizations!"
	#endif // WINDOWS_VERSION
#endif // USE_PLATFORM_OPTIMIZATION

#endif // AAX_PLATFORMOPTIMIZATIONCONSTANTS_H

