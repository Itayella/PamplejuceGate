/*================================================================================================*/
/*
 *
 *	Copyright 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file  AAX_ITaskAgent.h
 */ 
/*================================================================================================*/


#ifndef AAX_ITaskAgent_H
#define AAX_ITaskAgent_H

#include "AAX_IACFTaskAgent.h"
#include "AAX.h"
#include "CACFUnknown.h"


/** 
 * \brief Interface for a component that accepts task requests
 *
 * \copydetails AAX_IACFTaskAgent
 * 
 * \ingroup AuxInterface_TaskAgent
 */ 
class AAX_ITaskAgent : public AAX_IACFTaskAgent
					 , public CACFUnknown
{
public:
	ACF_DECLARE_STANDARD_UNKNOWN()
	
	ACFMETHOD(InternalQueryInterface)(const acfIID & riid, void **ppvObjOut) AAX_OVERRIDE;
	
	// CACFUnknown does not support operator=()
	AAX_DELETE(AAX_ITaskAgent& operator= (const AAX_ITaskAgent&));
};

#endif //AAX_IEFFECTDIRECTDATA_H
