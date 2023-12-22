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
 *	\file  AAX_IACFPrivateDataAccess.h
 *
 *	\brief Interface for the %AAX host's data access functionality.
 *
 */ 
/*================================================================================================*/


#ifndef _AAX_IACFPrivateDATAACCESS_H_
#define _AAX_IACFPrivateDATAACCESS_H_

#include "AAX.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#endif

#include "acfunknown.h"

/** \brief Interface for the %AAX host's data access functionality.
 	
 	\details
	\ingroup AuxInterface_DirectData
 */
class AAX_IACFPrivateDataAccess : public IACFUnknown
{
public:	
			
	virtual AAX_Result	ReadPortDirect( AAX_CFieldIndex inFieldIndex, const uint32_t inOffset, const uint32_t inSize, void* outBuffer ) = 0;	///< \copydoc AAX_IPrivateDataAccess::ReadPortDirect()
	virtual AAX_Result	WritePortDirect( AAX_CFieldIndex inFieldIndex, const uint32_t inOffset, const uint32_t inSize, const void* inBuffer ) = 0;	///< \copydoc AAX_IPrivateDataAccess::WritePortDirect()
	
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // #ifndef _AAX_IACFPrivateDATAACCESS_H_
