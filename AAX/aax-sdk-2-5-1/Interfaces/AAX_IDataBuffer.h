/*================================================================================================*/
/*
 *
 * Copyright 2023 Avid Technology, Inc.
 * All rights reserved.
 * 
 * CONFIDENTIAL: this document contains confidential information of Avid. Do
 * not disclose to any third party. Use of the information contained in this
 * document is subject to an Avid SDK license.
 *
 */

/**  
 * \file  AAX_IDataBuffer.h
 */ 
/*================================================================================================*/

#pragma once

#ifndef AAX_IDataBuffer_H
#define AAX_IDataBuffer_H

#include "AAX_IACFDataBuffer.h"
#include "AAX.h"
#include "CACFUnknown.h"
#include "AAX_UIDs.h"
#include "acfextras.h"


/** 
 * \brief Interface for reference counted data buffers
 *
 * \copydetails AAX_IACFDataBuffer
 */ 
class AAX_IDataBuffer : public AAX_IACFDataBuffer
					  , public CACFUnknown
{
public:
	ACF_DECLARE_STANDARD_UNKNOWN()
	
	ACFMETHOD(InternalQueryInterface)(const acfIID & riid, void **ppvObjOut) AAX_OVERRIDE
	{
		if (riid == IID_IAAXDataBufferV1)
		{
			*ppvObjOut = static_cast<IACFUnknown *>(this);
			( static_cast<IACFUnknown *>(*ppvObjOut))->AddRef();
			return ACF_OK;
		}
		
		return this->CACFUnknown::InternalQueryInterface(riid, ppvObjOut);
	}
	
	// CACFUnknown does not support operator=()
	AAX_DELETE(AAX_IDataBuffer& operator= (const AAX_IDataBuffer&));
};

#endif
