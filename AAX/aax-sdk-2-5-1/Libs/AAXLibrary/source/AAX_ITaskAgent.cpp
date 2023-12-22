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
/*================================================================================================*/

#include "AAX_ITaskAgent.h"
#include "AAX_UIDs.h"
#include "acfextras.h"

ACFMETHODIMP AAX_ITaskAgent::InternalQueryInterface(const acfIID & riid, void **ppvObjOut)
{
	if (riid == IID_IAAXTaskAgentV1)
	{
		*ppvObjOut = static_cast<IACFUnknown *>(this);
		( static_cast<IACFUnknown *>(*ppvObjOut))->AddRef();
		return ACF_OK;
	}
	
	return this->CACFUnknown::InternalQueryInterface(riid, ppvObjOut);	
}
