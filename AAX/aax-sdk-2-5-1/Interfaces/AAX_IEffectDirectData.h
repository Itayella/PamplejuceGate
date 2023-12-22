/*================================================================================================*/
/*
 *
 *	Copyright 2014-2017, 2019-2021, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file  AAX_IEffectDirectData.h
 *
 *	\brief Optional interface for direct access to alg memory
 *
 */ 
/*================================================================================================*/


#ifndef AAX_IEFFECTDIRECTDATA_H
#define AAX_IEFFECTDIRECTDATA_H

#include "AAX_IACFEffectDirectData.h"
#include "AAX.h"
#include "CACFUnknown.h"


/** @brief	The interface for a %AAX Plug-in's direct data interface.
	
	@details
	@pluginimp

	This is the interface for an instance of a plug-in's direct data interface that
	gets exposed to the host application.  A plug-in needs to inherit from this interface
	and override all of the virtual functions to support direct data access functionality.

	Direct data access allows a plug-in to directly manipulate the data in its algorithm's
	private data blocks.  The callback methods in this interface provide a safe context
	from which this kind of access may be attempted.
	
	\note This class always inherits from the latest version of the interface and thus requires any 
	subclass to implement all the methods in the latest version of the interface.
	
	\note See AAX_IACFEffectDirectData for further information.
	
	\ingroup AuxInterface_DirectData
*/
class AAX_IEffectDirectData :  public AAX_IACFEffectDirectData_V2,
							   public CACFUnknown
{	 
public:
	ACF_DECLARE_STANDARD_UNKNOWN()
	
	ACFMETHOD(InternalQueryInterface)(const acfIID & riid, void **ppvObjOut) override;
	
	// CACFUnknown does not support operator=()
	AAX_DELETE(AAX_IEffectDirectData& operator= (const AAX_IEffectDirectData&));
};

#endif //AAX_IEFFECTDIRECTDATA_H
