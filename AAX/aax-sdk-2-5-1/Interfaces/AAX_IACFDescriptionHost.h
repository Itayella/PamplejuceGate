/*================================================================================================*/
/*
 *	Copyright 2016-2017, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

#ifndef AAXLibrary_AAX_IACFDescriptionHost_h
#define AAXLibrary_AAX_IACFDescriptionHost_h


#include "AAX.h"

class AAX_IACFFeatureInfo;

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#endif

#include "acfbaseapi.h"
#include "acfunknown.h"

/** Interface to host services provided during plug-in description
 */
class AAX_IACFDescriptionHost : public IACFUnknown
{
public:
	// NOTE: Documentation is not copied directly from AAX_IDescriptionHost due to an adaptation of parameter types (IACFUnknown to AAX_IFeatureInfo)
	/**
	 *	\copybrief AAX_IDescriptionHost::AcquireFeatureProperties()
	 *
	 *	\p outFeatureProperties must support \ref AAX_IACFFeatureInfo const methods
	 *
	 *	\sa AAX_IDescriptionHost::AcquireFeatureProperties()
	 */
	virtual AAX_Result AcquireFeatureProperties(const AAX_Feature_UID& inFeatureID, IACFUnknown** outFeatureProperties) = 0;
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif
