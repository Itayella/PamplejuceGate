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
 * \file  AAX_IACFDataBuffer.h
 */ 
/*================================================================================================*/

#pragma once

#ifndef AAX_IACFDataBuffer_H
#define AAX_IACFDataBuffer_H

#include "AAX.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#endif

#include "acfunknown.h"

/** 
 * \brief Versioned interface for reference counted data buffers
 *
 * \details
 * This interface is intended to be used for passing arbitrary blocks
 * of data across the binary boundary and allowing the receiver to
 * take ownership of the allocated memory.
 */ 
class AAX_IACFDataBuffer : public IACFUnknown
{
public:
	/**
	 * The type of data contained in this buffer
	 * 
	 * This identifier must be sufficient for a client that
	 * knows the type to correctly interpret and use the data.
	 */
	virtual AAX_Result Type(AAX_CTypeID * oType) const = 0;
	/**
	 * The number of bytes of data in this buffer
	 */
	virtual AAX_Result Size(int32_t * oSize) const = 0;
	/**
	 * The buffer of data
	 */
	virtual AAX_Result Data(void const ** oBuffer) const = 0;
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif
