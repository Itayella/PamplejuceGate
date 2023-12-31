/*================================================================================================*/
/*
 *	Copyright 2016-2017, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

#ifndef AAXLibrary_AAX_VDescriptionHost_h
#define AAXLibrary_AAX_VDescriptionHost_h


#include "AAX_IDescriptionHost.h"
#include "ACFPtr.h"


class AAX_IACFDescriptionHost;
class IACFDefinition;


/** Versioned wrapper for access to host service interfaces provided during plug-in description
 
 This object aggregates access to \ref AAX_IACFDescriptionHost and \ref IACFDefinition, with
 support depending on the interface support level of the \ref IACFUnknown which is passed to
 this object upon creation.
 */
class AAX_VDescriptionHost : public AAX_IDescriptionHost
{
public:
	explicit AAX_VDescriptionHost( IACFUnknown* pUnknown );
	~AAX_VDescriptionHost() AAX_OVERRIDE;
	
public: // AAX_IDescriptionHost
	const AAX_IFeatureInfo* AcquireFeatureProperties(const AAX_Feature_UID& inFeatureID) const AAX_OVERRIDE; ///< \copydoc AAX_IDescriptionHost::AcquireFeatureProperties()
	
public: // AAX_VDescriptionHost
	bool Supported() const { return !mDescriptionHost.isNull(); }
	AAX_IACFDescriptionHost* DescriptionHost() { return mDescriptionHost.inArg(); } // does not addref
	const AAX_IACFDescriptionHost* DescriptionHost() const { return mDescriptionHost.inArg(); } // does not addref
	IACFDefinition* HostDefinition() const { return mHostInformation.inArg(); } // does not addref
	
private:
	ACFPtr<AAX_IACFDescriptionHost> mDescriptionHost;
	ACFPtr<IACFDefinition> mHostInformation;
};




#endif // AAXLibrary_AAX_VDescriptionHost_h
