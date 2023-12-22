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
 * \file  AAX_IACFTaskAgent.h
 */ 
/*================================================================================================*/

#pragma once

#ifndef AAX_IACFTaskAgent_H
#define AAX_IACFTaskAgent_H

#include "AAX.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#endif

#include "acfunknown.h"

class IACFUnknown;


/** 
 * \brief Versioned interface for a component that accepts task requests
 *
 * \details
 * \pluginimp
 * 
 * The task agent is expected to complete the requested tasks asynchronously
 * and to provide progress and completion details via calls on the
 * \ref AAX_IACFTask interface as the tasks proceed.
 * 
 * \sa AAX_ITask
 * 
 * \ingroup AuxInterface_TaskAgent
 */
class AAX_IACFTaskAgent : public IACFUnknown
{
public:
	/** @name Initialization and uninitialization
	 */
	//@{
	/**
	 * Initialize the object
	 * 
	 * \param[in] iController
	 * Interface allowing access to other objects in the object graph
	 * such as the plug-in's data model.
	 */
	virtual AAX_Result Initialize(IACFUnknown* iController) = 0;
	/**
	 * Uninitialize the object
	 * 
	 * This method should release references to any shared objects
	 */
	virtual AAX_Result Uninitialize() = 0;
	//@} Initialization and uninitialization
	
	/** @name Task management
	 */
	//@{
	/**
	 * Request that the agent perform a task
	 * 
	 * \param[in] iTask
	 * The task to perform. The agent must retain a reference to
	 * this task if it will be used beyond the scope of this method.
	 * This object should support at least \ref AAX_IACFTask .
	 */
	virtual AAX_Result AddTask(IACFUnknown * iTask) = 0;
	/**
	 * Request that the agent cancel all outstanding tasks
	 */
	virtual AAX_Result CancelAllTasks() = 0;
	//@} Task management
};


#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif
