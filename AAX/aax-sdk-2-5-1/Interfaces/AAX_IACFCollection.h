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
 *	\file  AAX_IACFCollection.h
 *
 *	\brief Versioned interface to represent a plug-in binary's static description
 *
 */ 
/*================================================================================================*/


#ifndef AAX_IACFCOLLECTION_H
#define AAX_IACFCOLLECTION_H

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#endif

#include "acfbaseapi.h"

class AAX_IEffectDescriptor;

/**	\brief Versioned interface to represent a plug-in binary's static description
 */
class AAX_IACFCollection : public IACFPluginDefinition
{
public:
	
	virtual	AAX_Result				AddEffect ( const char * inEffectID, IACFUnknown * inEffectDescriptor ) = 0;	///< \copydoc AAX_ICollection::AddEffect
	virtual	AAX_Result				SetManufacturerName( const char* inPackageName ) = 0;	///< \copydoc AAX_ICollection::SetManufacturerName()
	virtual	AAX_Result				AddPackageName( const char *inPackageName ) = 0;	///< \copydoc AAX_ICollection::AddPackageName()
	virtual	AAX_Result				SetPackageVersion( uint32_t inVersion ) = 0;	///< \copydoc AAX_ICollection::SetPackageVersion()
	virtual AAX_Result				SetProperties ( IACFUnknown * inProperties ) = 0; ///< \copydoc AAX_ICollection::SetProperties()
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif
