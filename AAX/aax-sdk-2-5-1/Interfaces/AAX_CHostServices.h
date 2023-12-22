/*================================================================================================*/
/*
 *
 *	Copyright 2014-2015, 2018, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file  AAX_CHostServices.h
 *
 *	\brief Concrete implementation of the AAX_IHostServices interface.
 *
 */ 
/*================================================================================================*/


#ifndef AAX_CHOSTSERVICES_H
#define AAX_CHOSTSERVICES_H

#include "AAX.h"
#include "AAX_Enums.h"


class IACFUnknown;

/**	@brief Method access to a singleton implementation of the \ref AAX_IHostServices interface
 */
class AAX_CHostServices
{
public:
	static void Set ( IACFUnknown * pUnkHost );
	
	static AAX_Result HandleAssertFailure ( const char * iFile, int32_t iLine, const char * iNote, /* AAX_EAssertFlags */ int32_t iFlags = AAX_eAssertFlags_Default ); ///< \copydoc AAX_IHostServices::HandleAssertFailure()
	static AAX_Result Trace ( AAX_ETracePriorityHost iPriority, const char * iMessage, ... ); ///< \copydoc AAX_IHostServices::Trace()
	static AAX_Result StackTrace ( AAX_ETracePriorityHost iTracePriority, AAX_ETracePriorityHost iStackTracePriority, const char * iMessage, ... ); ///< \copydoc AAX_IHostServices::StackTrace()
};


#endif
