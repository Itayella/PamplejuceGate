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
 * \file  AAX_CStringDataBuffer.h
 */ 
/*================================================================================================*/

#pragma once

#ifndef AAX_CStringDataBuffer_H
#define AAX_CStringDataBuffer_H

#include "AAX_IDataBuffer.h"
#include "AAX.h"

#include <string>
#include <limits>
#include <type_traits>


/**
 * \brief A convenience class for string data buffers
 * 
 * The data payload is a \c char* C string
 */
template <AAX_CTypeID T>
class AAX_CStringDataBufferOfType : public AAX_IDataBuffer
{
public:
	explicit AAX_CStringDataBufferOfType (std::string const & inData) : mData{inData} {}
	explicit AAX_CStringDataBufferOfType (std::string && inData) : mData{inData} {}
	explicit AAX_CStringDataBufferOfType (const char * inData) : mData{inData ? std::string{inData} : std::string{}} {}

	AAX_CStringDataBufferOfType(AAX_CStringDataBufferOfType const &) = default;
	AAX_CStringDataBufferOfType(AAX_CStringDataBufferOfType &&) = default;

	~AAX_CStringDataBufferOfType (void) AAX_OVERRIDE = default;
	
	AAX_CStringDataBufferOfType& operator= (AAX_CStringDataBufferOfType const & other) = default;
	AAX_CStringDataBufferOfType& operator= (AAX_CStringDataBufferOfType && other) = default;

	AAX_Result Type(AAX_CTypeID * oType) const AAX_OVERRIDE {
		if (!oType) { return AAX_ERROR_NULL_ARGUMENT; }
		*oType = T;
		return AAX_SUCCESS;
	}
	AAX_Result Size(int32_t * oSize) const AAX_OVERRIDE {
		if (!oSize) { return AAX_ERROR_NULL_ARGUMENT; }
		auto const size = mData.size() + 1; // null termination
		static_assert(std::numeric_limits<decltype(size)>::max() >= std::numeric_limits<std::remove_pointer<decltype(oSize)>::type>::max());
		if (size > std::numeric_limits<std::remove_pointer<decltype(oSize)>::type>::max()) {
			return AAX_ERROR_SIGNED_INT_OVERFLOW;
		}
		*oSize = size;
		return AAX_SUCCESS;
	}
	AAX_Result Data(void const ** oBuffer) const AAX_OVERRIDE {
		if (!oBuffer) { return AAX_ERROR_NULL_ARGUMENT; }
		*oBuffer = mData.c_str();
		return AAX_SUCCESS;
	}
private:
	std::string mData;
};

/**
 * \copydoc AAX_CStringDataBufferOfType
 */
class AAX_CStringDataBuffer : public AAX_IDataBuffer
{
public:
	AAX_CStringDataBuffer (AAX_CTypeID inType, std::string const & inData) : mType{inType}, mData{inData} {}
	AAX_CStringDataBuffer (AAX_CTypeID inType, std::string && inData) : mType{inType}, mData{inData} {}
	AAX_CStringDataBuffer (AAX_CTypeID inType, const char * inData) : mType{inType}, mData{inData ? std::string{inData} : std::string{}} {}

	AAX_CStringDataBuffer(AAX_CStringDataBuffer const &) = default;
	AAX_CStringDataBuffer(AAX_CStringDataBuffer &&) = default;

	~AAX_CStringDataBuffer (void) AAX_OVERRIDE = default;
	
	AAX_CStringDataBuffer& operator= (AAX_CStringDataBuffer const & other) = default;
	AAX_CStringDataBuffer& operator= (AAX_CStringDataBuffer && other) = default;

	AAX_Result Type(AAX_CTypeID * oType) const AAX_OVERRIDE {
		if (!oType) { return AAX_ERROR_NULL_ARGUMENT; }
		*oType = mType;
		return AAX_SUCCESS;
	}
	AAX_Result Size(int32_t * oSize) const AAX_OVERRIDE {
		if (!oSize) { return AAX_ERROR_NULL_ARGUMENT; }
		auto const size = mData.size() + 1; // null termination
		static_assert(std::numeric_limits<decltype(size)>::max() >= std::numeric_limits<std::remove_pointer<decltype(oSize)>::type>::max());
		if (size > std::numeric_limits<std::remove_pointer<decltype(oSize)>::type>::max()) {
			return AAX_ERROR_SIGNED_INT_OVERFLOW;
		}
		*oSize = size;
		return AAX_SUCCESS;
	}
	AAX_Result Data(void const ** oBuffer) const AAX_OVERRIDE {
		if (!oBuffer) { return AAX_ERROR_NULL_ARGUMENT; }
		*oBuffer = mData.c_str();
		return AAX_SUCCESS;
	}
private:
	AAX_CTypeID const mType;
	std::string mData;
};

#endif
