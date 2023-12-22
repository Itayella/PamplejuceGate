/*================================================================================================*/
/*
 *
 *	Copyright 2013-2017, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file  AAX_VEffectDescriptor.h
 *
 *	\brief Version-managed concrete EffectDescriptor class
 *
 */ 
/*================================================================================================*/

#ifndef AAX_VEFFECTDESCRIPTOR_H
#define AAX_VEFFECTDESCRIPTOR_H

#include "AAX.h"
#include "AAX_IEffectDescriptor.h"
#include "AAX_IACFEffectDescriptor.h"
#include "acfunknown.h"
#include "ACFPtr.h"

#include <set>
#include <map>

class AAX_IComponentDescriptor;
class AAX_IPropertyMap;
class AAX_IACFEffectDescriptor;
class IACFUnknown;

/**
 *	\brief Version-managed concrete \ref AAX_IEffectDescriptor class
 *
 */
class AAX_VEffectDescriptor : public AAX_IEffectDescriptor
{
public:	
	AAX_VEffectDescriptor ( IACFUnknown * pUnkHost );
	~AAX_VEffectDescriptor () AAX_OVERRIDE;

	/** \copydoc AAX_IEffectDescriptor::NewComponentDescriptor()
	 *	
	 *	This implementation retains each generated \ref AAX_IComponentDescriptor and destroys the property map upon AAX_VEffectDescriptor destruction
	 */
	AAX_IComponentDescriptor *		NewComponentDescriptor () AAX_OVERRIDE;
	AAX_Result						AddComponent ( AAX_IComponentDescriptor * inComponentDescriptor ) AAX_OVERRIDE; ///< \copydoc AAX_IEffectDescriptor::AddComponent()
	AAX_Result						AddName ( const char * inPlugInName ) AAX_OVERRIDE; ///< \copydoc AAX_IEffectDescriptor::AddName()
	AAX_Result						AddCategory ( uint32_t inCategory ) AAX_OVERRIDE; ///< \copydoc AAX_IEffectDescriptor::AddCategory()
	AAX_Result						AddCategoryBypassParameter ( uint32_t inCategory, AAX_CParamID inParamID ) AAX_OVERRIDE; ///< \copydoc AAX_IEffectDescriptor::AddCategoryBypassParameter()
	AAX_Result						AddProcPtr ( void * inProcPtr, AAX_CProcPtrID inProcID ) AAX_OVERRIDE; ///< \copydoc AAX_IEffectDescriptor::AddProcPtr()
	/** \copydoc AAX_IEffectDescriptor::NewPropertyMap()
	 *	
	 *	This implementation retains each generated \ref AAX_IPropertyMap and destroys the property map upon AAX_VEffectDescriptor destruction
	 */
	AAX_IPropertyMap *				NewPropertyMap () AAX_OVERRIDE;
	AAX_Result						SetProperties ( AAX_IPropertyMap * inProperties ) AAX_OVERRIDE; ///< \copydoc AAX_IEffectDescriptor::SetProperties()
	AAX_Result						AddResourceInfo ( AAX_EResourceType inResourceType, const char * inInfo ) AAX_OVERRIDE; ///< \copydoc AAX_IEffectDescriptor::AddResourceInfo()
	AAX_Result						AddMeterDescription( AAX_CTypeID inMeterID, const char * inMeterName, AAX_IPropertyMap * inProperties ) AAX_OVERRIDE; ///< \copydoc AAX_IEffectDescriptor::AddMeterDescription()
	AAX_Result						AddControlMIDINode ( AAX_CTypeID inNodeID, AAX_EMIDINodeType inNodeType, const char inNodeName[], uint32_t inChannelMask ) AAX_OVERRIDE; ///< \copydoc AAX_IEffectDescriptor::AddControlMIDINode()

	IACFUnknown*							GetIUnknown(void) const;

private:
	ACFPtr<IACFUnknown>						mUnkHost;
	ACFPtr<AAX_IACFEffectDescriptor>		mIACFEffectDescriptor;
	ACFPtr<AAX_IACFEffectDescriptor_V2>		mIACFEffectDescriptorV2;
	std::set<AAX_IComponentDescriptor *>	mComponentDescriptors;
	std::set<AAX_IPropertyMap *>			mPropertyMaps;

};

#endif // AAX_VEFFECTDESCRIPTOR_H
