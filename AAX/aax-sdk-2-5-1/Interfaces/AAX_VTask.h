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
 * \file  AAX_VTask.h
 */ 
/*================================================================================================*/

#pragma once

#ifndef AAX_VTask_H
#define AAX_VTask_H

#include "AAX_ITask.h"
#include "AAX.h"

#include "ACFPtr.h"

class IACFUnknown;

/*!
 \brief Version-managed concrete \ref AAX_ITask
 */
class AAX_VTask : public AAX_ITask
{
public:
	explicit AAX_VTask( IACFUnknown* pUnknown );
	~AAX_VTask() AAX_OVERRIDE;

	AAX_Result GetType(AAX_CTypeID * oType) const AAX_OVERRIDE; ///< \copydoc AAX_ITask::GetType()
	AAX_IACFDataBuffer const * GetArgumentOfType(AAX_CTypeID iType) const AAX_OVERRIDE; ///< \copydoc AAX_ITask::GetArgumentOfType()

	AAX_Result SetProgress(float iProgress)  AAX_OVERRIDE; ///< \copydoc AAX_ITask::SetProgress()
	float GetProgress() const AAX_OVERRIDE; ///< \copydoc AAX_ITask::GetProgress()
	AAX_Result AddResult(AAX_IACFDataBuffer const * iResult) AAX_OVERRIDE; ///< \copydoc AAX_ITask::AddResult()
	AAX_ITask * SetDone(AAX_TaskCompletionStatus iStatus) AAX_OVERRIDE; ///< \copydoc AAX_ITask::SetDone()
private:
	ACFPtr<AAX_IACFTask> mTaskV1;
};

#endif
