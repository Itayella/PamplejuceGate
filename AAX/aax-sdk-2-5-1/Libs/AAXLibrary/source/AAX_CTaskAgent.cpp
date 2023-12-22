/*================================================================================================*/
/*
 *
 *	Copyright 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */
/*================================================================================================*/

#include "AAX_CTaskAgent.h"

#include "AAX_IEffectParameters.h"
#include "AAX_VController.h"
#include "AAX_VTask.h"
#include "AAX_UIDs.h"

AAX_CTaskAgent::~AAX_CTaskAgent()
{
	this->ReleaseObjects();
}

AAX_Result AAX_CTaskAgent::Initialize ( IACFUnknown * iController )
{
	if (!iController) {
		return AAX_ERROR_NULL_ARGUMENT;
	}

	mController = new AAX_VController(iController);
	if (!mController) {
		return AAX_ERROR_NOT_INITIALIZED;
	}
		
	iController->QueryInterface(IID_IAAXEffectParametersV1, (void **)&mEffectParameters);
	if (!mEffectParameters) {
		return AAX_ERROR_NOT_INITIALIZED;
	}
	
	return AAX_SUCCESS;
}

AAX_Result AAX_CTaskAgent::Uninitialize (void)
{
	this->ReleaseObjects();
	return AAX_SUCCESS;
}

AAX_Result AAX_CTaskAgent::AddTask(IACFUnknown * iTask)
{
	std::unique_ptr<AAX_ITask> task = std::make_unique<AAX_VTask>(iTask);
	return this->AddTask(std::move(task));
}

AAX_Result AAX_CTaskAgent::CancelAllTasks()
{
	return AAX_SUCCESS;
}

AAX_Result AAX_CTaskAgent::AddTask(std::unique_ptr<AAX_ITask> iTask)
{
	return AAX_SUCCESS;
}

void AAX_CTaskAgent::ReleaseObjects()
{
	if (mEffectParameters)
	{
		mEffectParameters->Release();
		mEffectParameters = nullptr;
	}
	
	if ( mController )
	{
		delete ( mController );
		mController = nullptr;
	}
}


