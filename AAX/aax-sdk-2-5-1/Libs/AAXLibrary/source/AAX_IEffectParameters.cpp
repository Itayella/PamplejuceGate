/*================================================================================================*/
/*
 *	Copyright 2014-2017, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */
/*================================================================================================*/

#include "AAX_IEffectParameters.h"
#include "AAX_UIDs.h"
#include "acfextras.h"

ACFMETHODIMP AAX_IEffectParameters::InternalQueryInterface(const acfIID & riid, void **ppvObjOut)
{
    if (riid == IID_IAAXEffectParametersV1 ||
		riid == IID_IAAXEffectParametersV2 ||
		riid == IID_IAAXEffectParametersV3 ||
		riid == IID_IAAXEffectParametersV4)
    { 
		*ppvObjOut = static_cast<IACFUnknown *>(this);
        ( static_cast<IACFUnknown *>(*ppvObjOut))->AddRef();
        return ACF_OK;
    }
	
	return this->CACFUnknown::InternalQueryInterface(riid, ppvObjOut);	
}
