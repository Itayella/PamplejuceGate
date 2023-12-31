/*================================================================================================*/
/*
 *	Copyright 2016-2017, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

#ifndef AAXLibrary_AAX_IACFFeatureInfo_h
#define AAXLibrary_AAX_IACFFeatureInfo_h

#include "AAX.h"

class AAX_IACFPropertyMap;

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#endif

#include "acfunknown.h"

/** Information about host support for a particular feature
 
 Acquired using \ref AAX_IACFDescriptionHost::AcquireFeatureProperties()
 
 This interface is shared between multiple features. The specific feature which this object
 represents is the feature whose ID was used in the call to acquire this interface.
 
 See the feature UID documentation for which properties support additional property map data
 
 IID: \ref IID_IAAXFeatureInfoV1
 
 \note Do not \c QueryInterface() for \ref IID_IAAXFeatureInfoV1 since this does not
 indicate which specific feature is being requested. Instead, use
 \ref AAX_IDescriptionHost::AcquireFeatureProperties()
 */
class AAX_IACFFeatureInfo : public IACFUnknown
{
public:
	// NOTE: Documentation is copied directly from AAX_IFeatureInfo despite an adaptation of parameter types (AAX_ESupportLevel* to AAX_ESupportLevel&)
	/**
	 *	\copydoc AAX_IFeatureInfo::SupportLevel()
	 *
	 *	\sa AAX_IFeatureInfo::SupportLevel()
	 */
	virtual AAX_Result SupportLevel(AAX_ESupportLevel* oSupportLevel) const = 0; ///< \copydoc AAX_IFeatureInfo::SupportLevel()
	
	// NOTE: Documentation is not copied directly from AAX_IFeatureInfo due to an adaptation of parameter types (IACFUnknown to AAX_IPropertyMap)
	/**
	 *	\copybrief AAX_IFeatureInfo::AcquireProperties()
	 *
	 *	\p outProperties must support \ref AAX_IACFPropertyMap const methods
	 *
	 *	\sa AAX_IFeatureInfo::AcquireProperties()
	 */
	virtual AAX_Result AcquireProperties(IACFUnknown** outProperties) = 0;
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif


#endif
