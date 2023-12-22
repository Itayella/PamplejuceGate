/*================================================================================================*/
/*
 *
 *	Copyright 2014-2017, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file  AAX_VPrivateDataAccess.h
 *
 *	\brief Version-managed concrete PrivateDataAccess class
 *
 */ 
/*================================================================================================*/
#ifndef AAX_VPRIVATEDATAACCESS_H
#define AAX_VPRIVATEDATAACCESS_H

#include "AAX_IPrivateDataAccess.h"
#include "AAX_IACFPrivateDataAccess.h"
#include "ACFPtr.h"


class IACFUnknown;

/**
 *	\brief Version-managed concrete \ref AAX_IPrivateDataAccess class
 *
 */
class AAX_VPrivateDataAccess : public AAX_IPrivateDataAccess
{
public:
	AAX_VPrivateDataAccess( IACFUnknown* pUnknown );
	~AAX_VPrivateDataAccess() AAX_OVERRIDE;

	// Direct access methods
	AAX_Result	ReadPortDirect( AAX_CFieldIndex inFieldIndex, const uint32_t inOffset, const uint32_t inSize, void* outBuffer ) AAX_OVERRIDE; ///< \copydoc AAX_IPrivateDataAccess::ReadPortDirect()
	AAX_Result	WritePortDirect( AAX_CFieldIndex inFieldIndex, const uint32_t inOffset, const uint32_t inSize, const void* inBuffer ) AAX_OVERRIDE; ///< \copydoc AAX_IPrivateDataAccess::WritePortDirect()


private:
	AAX_IACFPrivateDataAccess*	mIPrivateDataAccess;
};


#endif //AAX_VPRIVATEDATAACCESS_H

