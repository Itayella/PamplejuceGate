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

#include "AAX_VTask.h"
#include "AAX_UIDs.h"
#include "acfunknown.h"


AAX_VTask::AAX_VTask( IACFUnknown* pUnknown )
{
	if ( pUnknown )
	{
		pUnknown->QueryInterface(IID_IAAXTaskV1, (void **)&mTaskV1);
	}
}

AAX_VTask::~AAX_VTask() = default;

AAX_Result AAX_VTask::GetType(AAX_CTypeID * oType) const
{
	if (mTaskV1) {
		return mTaskV1->GetType(oType);
	}
	return AAX_ERROR_NULL_OBJECT;
}

AAX_IACFDataBuffer const * AAX_VTask::GetArgumentOfType(AAX_CTypeID iType) const
{
	if (mTaskV1) {
		return mTaskV1->GetArgumentOfType(iType);
	}
	return nullptr;
}

AAX_Result AAX_VTask::SetProgress(float iProgress)
{
	if (mTaskV1) {
		return mTaskV1->SetProgress(iProgress);
	}
	return AAX_ERROR_NULL_OBJECT;
}

float AAX_VTask::GetProgress() const
{
	if (mTaskV1) {
		return mTaskV1->GetProgress();
	}
	return AAX_ERROR_NULL_OBJECT;
}

AAX_Result AAX_VTask::AddResult(AAX_IACFDataBuffer const * iResult)
{
	if (mTaskV1) {
		return mTaskV1->AddResult(iResult);
	}
	return AAX_ERROR_NULL_OBJECT;
}

AAX_ITask * AAX_VTask::SetDone(AAX_TaskCompletionStatus iStatus)
{
	if (mTaskV1) {
		if (AAX_SUCCESS == mTaskV1->SetDone(iStatus)) {
			mTaskV1 = nullptr;
			return nullptr;
		}
	}
	return this;
}
