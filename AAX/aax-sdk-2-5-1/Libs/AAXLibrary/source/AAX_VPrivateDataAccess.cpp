/*================================================================================================*/
/*
 *	Copyright 2013-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */
/*================================================================================================*/

#include "AAX_VPrivateDataAccess.h"
#include "AAX_UIDs.h"

// ******************************************************************************************
// METHOD:	AAX_VPrivateDataAccess
// ******************************************************************************************
AAX_VPrivateDataAccess::AAX_VPrivateDataAccess( IACFUnknown* pUnknown )
:	mIPrivateDataAccess(NULL)
{
	if ( pUnknown )
	{
		pUnknown->QueryInterface(IID_IAAXPrivateDataAccessV1, (void **)&mIPrivateDataAccess);
	}	
}

// ******************************************************************************************
// METHOD:	~AAX_VPrivateDataAccess
// ******************************************************************************************
AAX_VPrivateDataAccess::~AAX_VPrivateDataAccess()
{
}

// ******************************************************************************************
// METHOD:	ReadPortDirect
// ******************************************************************************************
AAX_Result AAX_VPrivateDataAccess::ReadPortDirect( AAX_CFieldIndex inFieldIndex, const uint32_t inOffset, const uint32_t inSize, void* outBuffer )
{
	if ( mIPrivateDataAccess )
		return mIPrivateDataAccess->ReadPortDirect ( inFieldIndex, inOffset, inSize, outBuffer );

	return AAX_ERROR_NULL_OBJECT;
}

// ******************************************************************************************
// METHOD:	WritePortDirect
// ******************************************************************************************
AAX_Result AAX_VPrivateDataAccess::WritePortDirect( AAX_CFieldIndex inFieldIndex, const uint32_t inOffset, const uint32_t inSize, const void* inBuffer )
{
	if ( mIPrivateDataAccess )
		return mIPrivateDataAccess->WritePortDirect ( inFieldIndex, inOffset, inSize, inBuffer );

	return AAX_ERROR_NULL_OBJECT;
}







