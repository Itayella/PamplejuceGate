/*================================================================================================*/
/*
 *	Copyright 2016-2017, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

// Self include
#include "AAX_VFeatureInfo.h"

// AAX includes
#include "AAX_IACFFeatureInfo.h"
#include "AAX_VPropertyMap.h"
#include "AAX_UIDs.h"

// Standard includes
#include <memory>


AAX_VFeatureInfo::AAX_VFeatureInfo( IACFUnknown* pUnknown, const acfUID& inFeatureID )
{
	mFeatureID = inFeatureID;
	
	if ( pUnknown )
	{
		pUnknown->QueryInterface(IID_IAAXFeatureInfoV1, (void **)&mIFeature);
	}
}

AAX_VFeatureInfo::~AAX_VFeatureInfo()
{
}

AAX_Result AAX_VFeatureInfo::SupportLevel(AAX_ESupportLevel& oSupportLevel) const
{
	if ( mIFeature )
		return mIFeature->SupportLevel(&oSupportLevel);
	
	return AAX_ERROR_NULL_OBJECT;
}

const AAX_IPropertyMap* AAX_VFeatureInfo::AcquireProperties() const
{
	AAX_UNIQUE_PTR(const AAX_IPropertyMap) acquiredMap;
	
	if ( mIFeature )
	{
		IACFUnknown* properties = NULL;
		
		// const cast is OK here because we are ultimately storing the result of the non-const acquire call in a const object
		AAX_IACFFeatureInfo* feature = const_cast<AAX_IACFFeatureInfo*>(mIFeature.inArg());
		if (AAX_SUCCESS == feature->AcquireProperties(&properties) && (NULL != properties))
		{
			// Move the ACF interface reference to an AAX_VPropertyMap object owned by the plug-in
			acquiredMap.reset(AAX_VPropertyMap::Acquire(properties));
		}
	}
	
	return acquiredMap.release();
}

const acfUID& AAX_VFeatureInfo::ID() const
{
	return mFeatureID;
}
