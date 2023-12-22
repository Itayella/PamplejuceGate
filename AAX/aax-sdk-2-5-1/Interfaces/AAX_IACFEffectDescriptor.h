/*================================================================================================*/
/*
 *
 *	Copyright 2013-2017, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file  AAX_IACFEffectDescriptor.h
 *
 *	\brief Versioned interface for an AAX_IEffectDescriptor
 *
 */ 
/*================================================================================================*/


#ifndef AAX_IACFEFFECTDESCRIPTOR_H
#define AAX_IACFEFFECTDESCRIPTOR_H

#include "AAX.h"
#include "AAX_Callbacks.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#endif

#include "acfunknown.h"


/**	\brief Versioned interface for an AAX_IEffectDescriptor
 */ 
class AAX_IACFEffectDescriptor : public IACFUnknown
{
public:
	
	virtual AAX_Result							AddComponent ( IACFUnknown* inComponentDescriptor ) = 0;	///< \copydoc AAX_IEffectDescriptor::AddComponent()
	virtual AAX_Result							AddName ( const char *inPlugInName ) = 0;	///< \copydoc AAX_IEffectDescriptor::AddName()
	virtual AAX_Result							AddCategory ( uint32_t inCategory ) = 0;	///< \copydoc AAX_IEffectDescriptor::AddCategory()
	virtual AAX_Result							AddCategoryBypassParameter ( uint32_t inCategory, AAX_CParamID inParamID ) = 0;	///< \copydoc AAX_IEffectDescriptor::AddCategoryBypassParameter()
	virtual AAX_Result							AddProcPtr ( void * inProcPtr, AAX_CProcPtrID inProcID ) = 0;	///< \copydoc AAX_IEffectDescriptor::AddProcPtr()
	virtual AAX_Result							SetProperties ( IACFUnknown * inProperties ) = 0;	///< \copydoc AAX_IEffectDescriptor::SetProperties()
	virtual AAX_Result							AddResourceInfo ( AAX_EResourceType inResourceType, const char * inInfo ) = 0;	///< \copydoc AAX_IEffectDescriptor::AddResourceInfo()
	virtual AAX_Result							AddMeterDescription( AAX_CTypeID inMeterID, const char * inMeterName, IACFUnknown * inProperties ) = 0;	///< \copydoc AAX_IEffectDescriptor::AddMeterDescription()
};

/**
 *	\brief Versioned interface for an AAX_IEffectDescriptor
 *
 */
class AAX_IACFEffectDescriptor_V2 : public AAX_IACFEffectDescriptor
{
public:
	virtual AAX_Result							AddControlMIDINode ( AAX_CTypeID inNodeID, AAX_EMIDINodeType inNodeType, const char inNodeName[], uint32_t inChannelMask ) = 0;	///< \copydoc AAX_IEffectDescriptor::AddControlMIDINode()
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // AAX_IACFEFFECTDESCRIPTOR_H
