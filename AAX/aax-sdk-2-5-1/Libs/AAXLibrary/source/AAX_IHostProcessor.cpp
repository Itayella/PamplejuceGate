/*================================================================================================*/
/*
 *	Copyright 2010-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */
/*================================================================================================*/

#include "AAX_IHostProcessor.h"
#include "AAX_UIDs.h"
#include "acfextras.h"

ACFMETHODIMP AAX_IHostProcessor::InternalQueryInterface(const acfIID & riid, void **ppvObjOut)
{
    if ((riid == IID_IAAXHostProcessorV2) || (riid == IID_IAAXHostProcessorV1))
    { 
		*ppvObjOut = static_cast<IACFUnknown *>(this);
        ( static_cast<IACFUnknown *>(*ppvObjOut))->AddRef();
        return ACF_OK;
    }
    
	return this->CACFUnknown::InternalQueryInterface(riid, ppvObjOut);	
}
