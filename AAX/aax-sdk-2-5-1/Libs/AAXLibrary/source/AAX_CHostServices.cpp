/*================================================================================================*/
/*
 *	Copyright 2013-2015, 2018, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */
/*================================================================================================*/


#include "AAX.h"
#include "AAX_CHostServices.h"
#include "AAX_VHostServices.h"
#include <cstdarg>
#include <cstdio>

static AAX_VHostServices* sHostServices = NULL;

// ***************************************************************************
// METHOD:	Set
// ***************************************************************************
void AAX_CHostServices::Set ( IACFUnknown * pUnkHost )
{
	if ( !sHostServices && pUnkHost )
	{
		sHostServices = new AAX_VHostServices(pUnkHost);
	}
	else if ( sHostServices && !pUnkHost )
	{
		delete sHostServices;
		sHostServices = NULL;
	}
}

// ***************************************************************************
// METHOD:	HandleAssertFailure
// ***************************************************************************
/* static */
AAX_Result AAX_CHostServices::HandleAssertFailure ( const char * inFile, int32_t inLine, const char * inNote, int32_t /* AAX_EAssertFlags */ inFlags )
{
	//Bail if the host does not support host services (e.g. unit tests)
	if (sHostServices == 0)
		return AAX_SUCCESS;

	return sHostServices->HandleAssertFailure ( inFile, inLine, inNote, inFlags );
}

// ***************************************************************************
// METHOD:	Trace
// ***************************************************************************
/* static */
AAX_Result AAX_CHostServices::Trace ( AAX_ETracePriorityHost inPriority, const char * inFormat, ... )
{
	//Bail if the host does not support host services (e.g. unit tests)
	if (sHostServices == 0)
		return AAX_SUCCESS;

	va_list	vargs;
	AAX_CONSTEXPR static const std::size_t bufferSize{512};
	char	message [ bufferSize ];
	
	va_start ( vargs, inFormat );
	auto const printReturn = vsnprintf( message, bufferSize, inFormat, vargs );
	va_end ( vargs );

	return 0 <= printReturn ? sHostServices->Trace ( (int32_t)inPriority, message ) : AAX_ERROR_PRINT_FAILURE;
}

// ***************************************************************************
// METHOD:	StackTrace
// ***************************************************************************
/* static */
AAX_Result AAX_CHostServices::StackTrace ( AAX_ETracePriorityHost inTracePriority, AAX_ETracePriorityHost inStackTracePriority, const char * inFormat, ... )
{
	//Bail if the host does not support host services (e.g. unit tests)
	if (sHostServices == 0)
		return AAX_SUCCESS;
	
	va_list	vargs;
	AAX_CONSTEXPR static const std::size_t bufferSize{512};
	char	message [ bufferSize ];
	
	va_start ( vargs, inFormat );
	auto const printReturn = vsnprintf( message, bufferSize, inFormat, vargs );
	va_end ( vargs );
	
	return 0 <= printReturn ? sHostServices->StackTrace ( (int32_t)inTracePriority, (int32_t)inStackTracePriority, message ) : AAX_ERROR_PRINT_FAILURE;
}
