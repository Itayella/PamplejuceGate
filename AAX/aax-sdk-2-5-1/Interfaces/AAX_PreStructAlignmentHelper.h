/*================================================================================================*/
/*
 *
 *	Copyright 2018, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file   AAX_PreStructAlignmentHelper.h
 *
 *	\brief Helper file for data alignment macros
 */ 
/*================================================================================================*/

#if defined (AAX_SDK__PRE_STRUCT_ALIGNMENT_HELPER_DID_PUSH_A_CHANGE)
	#warning nested struct alignment directives are not tested
#endif

#if defined (__clang__)
	#if __has_warning ("-Wpragma-pack")
		#define AAX_SDK__PRE_STRUCT_ALIGNMENT_HELPER_DID_PUSH_A_CHANGE 1
		#pragma clang diagnostic push
		#pragma clang diagnostic ignored "-Wpragma-pack"
	#endif
#endif
