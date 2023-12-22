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

#include "AAX_VHostServices.h"
#include "AAX_UIDs.h"
#include "acfbaseapi.h"
#include "ACFPtr.h"

// ******************************************************************************************
// METHOD:	AAX_VHostServices
// ******************************************************************************************
AAX_VHostServices::AAX_VHostServices( IACFUnknown * pUnkHost ) :
	mIACFHostServices( NULL ),
	mIACFHostServices2( NULL )
{
	if ( pUnkHost )
	{
		// Get the component factory service from the host so we can create the 
		// built-in plug-in definition.
		ACFPtr<IACFComponentFactory> pFactory;
		if ( pUnkHost->QueryInterface(IID_IACFComponentFactory, (void **)&pFactory) == ACF_OK )
		{
			// Create the object and get the base interface for it.
			pFactory->CreateComponent(AAXCompID_HostServices, 0, IID_IAAXHostServicesV1, (void **)&mIACFHostServices);
			pFactory->CreateComponent(AAXCompID_HostServices, 0, IID_IAAXHostServicesV2, (void **)&mIACFHostServices2);
			pFactory->CreateComponent(AAXCompID_HostServices, 0, IID_IAAXHostServicesV3, (void **)&mIACFHostServices3);
		}
	}
}

// ******************************************************************************************
// METHOD:	~AAX_VHostServices
// ******************************************************************************************
AAX_VHostServices::~AAX_VHostServices( )
{
}

// ******************************************************************************************
// METHOD:	HandleAssertFailure
// ******************************************************************************************
AAX_Result AAX_VHostServices::HandleAssertFailure ( const char * iFile, int32_t iLine, const char * iNote, int32_t iFlags ) const
{
	if (mIACFHostServices3) {
		return mIACFHostServices3->HandleAssertFailure( iFile, iLine, iNote, iFlags );
	}
// See comment at AAX_IACFHostServices::Assert()
#if defined _DEBUG
	else if (mIACFHostServices) {
		return const_cast<AAX_VHostServices*>(this)->mIACFHostServices->Assert( iFile, iLine, iNote );
	}
#endif
	
	return AAX_ERROR_NULL_OBJECT;
}

// ******************************************************************************************
// METHOD:	Trace
// ******************************************************************************************
AAX_Result AAX_VHostServices::Trace ( int32_t iPriority, const char * iMessage ) const
{
	if ( mIACFHostServices )
		return const_cast<AAX_VHostServices*>(this)->mIACFHostServices->Trace( iPriority, iMessage );
	
	return AAX_ERROR_NULL_OBJECT;
}

// ******************************************************************************************
// METHOD:	StackTrace
// ******************************************************************************************
AAX_Result AAX_VHostServices::StackTrace ( int32_t iTracePriority, int32_t iStackTracePriority, const char * iMessage ) const
{
	if ( mIACFHostServices2 )
		return const_cast<AAX_VHostServices*>(this)->mIACFHostServices2->StackTrace( iTracePriority, iStackTracePriority, iMessage );
	
	return AAX_ERROR_UNIMPLEMENTED;
}
