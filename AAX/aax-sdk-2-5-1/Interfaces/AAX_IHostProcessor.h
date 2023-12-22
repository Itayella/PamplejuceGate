/*================================================================================================*/
/*
 *
 *	Copyright 2013-2017, 2019-2021, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file  AAX_IHostProcessor.h
 *
 *	\brief Base class for the host processor interface which is extended by plugin code
 *
 */ 
/*================================================================================================*/


#ifndef AAX_IHOSTPROCESSOR_H
#define AAX_IHOSTPROCESSOR_H

#include "AAX_IACFHostProcessor.h"
#include "AAX.h"
#include "CACFUnknown.h"

/*! \brief	Base class for the host processor interface
	
	\details
	\pluginimp

	\note	This class always inherits from the latest version of the interface and thus requires any 
			subclass to implement all the methods in the latest version of the interface. Most plug-ins
			will inherit from the AAX_CHostProcessor convenience class.
 
	\ingroup AuxInterface_HostProcessor
*/
class AAX_IHostProcessor :	public AAX_IACFHostProcessor_V2,
							public CACFUnknown
{
public:
	ACF_DECLARE_STANDARD_UNKNOWN()
	
	ACFMETHOD(InternalQueryInterface)(const acfIID & riid, void **ppvObjOut) override;
	
	// CACFUnknown does not support operator=()
	AAX_DELETE(AAX_IHostProcessor& operator= (const AAX_IHostProcessor&));
};

#endif //AAX_IHOSTPROCESSOR_H
