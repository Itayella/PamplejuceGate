/*================================================================================================*/
/*
 *
 *	Copyright 2014-2017, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file  AAX_IPrivateDataAccess.h
 *
 *	\brief Interface to data access provided by host to plug-in
 *
 */ 
/*================================================================================================*/


#ifndef AAX_IPRIVATEDATAACCESS_H
#define AAX_IPRIVATEDATAACCESS_H

#include "AAX.h"			


/** @brief Interface to data access provided by host to plug-in.
	
	@details
	@hostimp
	
	WARNING: AAX_IPrivateDataAccess objects are not reference counted and
			 are not guaranteed to exist beyond the scope of the method(s)
			 they are passed into.
	
	\sa AAX_IACFEffectDirectData::TimerWakeup
	
	\ingroup AuxInterface_DirectData
	
*/
class AAX_IPrivateDataAccess
{
public:	
	virtual ~AAX_IPrivateDataAccess() {}

	/** @brief	Read data directly from DSP at the given port.
	
	\note Blocking

	@param[in]	inFieldIndex
		The port to read from.
	@param[in]	inOffset
		Offset into data to start reading.
	@param[in]	inSize
		Amount of data to read (in bytes).
	@param[out]	outBuffer
		Pointer to storage for data to be read into.

	*/
	virtual	AAX_Result				ReadPortDirect( AAX_CFieldIndex inFieldIndex, const uint32_t inOffset, const uint32_t inSize, void* outBuffer ) = 0;

	/** @brief	Write data directly to DSP at the given port.

	\note Blocking

	@param[in]	inFieldIndex
		The port to write to.
	@param[in]	inOffset
		Offset into data to begin writing.
	@param[in]	inSize
		Amount of data to write (in bytes).
	@param[in]	inBuffer
		Pointer to data being written.
	*/
	virtual	AAX_Result				WritePortDirect( AAX_CFieldIndex inFieldIndex, const uint32_t inOffset, const uint32_t inSize, const void* inBuffer ) = 0;
};

#endif //AAX_IPRIVATEDATAACCESS_H
