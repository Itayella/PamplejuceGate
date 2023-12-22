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

/**  
 *	\file AAX_CTaskAgent.h
 *
 *	\brief A default implementation of the \ref AAX_ITaskAgent interface.
 *
 */ 
/*================================================================================================*/


#ifndef AAX_CTaskAgent_H
#define AAX_CTaskAgent_H

#include "AAX_ITaskAgent.h"
#include <memory>

class AAX_IController;
class AAX_IEffectParameters;
class AAX_ITask;

/** @brief Default implementation of the \ref AAX_ITaskAgent interface.
	
	@details
	This class provides a default implementation of the \ref AAX_ITaskAgent interface.
	Your plug-in's task agent implementation should inherit from this class and 
	override the remaining interface functions.
		
	\ingroup AuxInterface_TaskAgent
*/
class AAX_CTaskAgent : public AAX_ITaskAgent
{
public: ///////////////////////////////////////////////////////////////////////////// constructor/destructor
	AAX_CTaskAgent (void) = default;
	~AAX_CTaskAgent (void) AAX_OVERRIDE;
	
public: ///////////////////////////////////////////////////////////////////////////// AAX_IACFTaskAgent

	/** @name Initialization and uninitialization
	 */
	//@{
	AAX_Result Initialize (IACFUnknown * iController ) AAX_OVERRIDE; ///< \copydoc AAX_IACFTaskAgent::Initialize()
	AAX_Result Uninitialize (void) AAX_OVERRIDE; ///< \copydoc AAX_IACFTaskAgent::Uninitialize()
	//@}end Initialization and uninitialization
	
	/** @name Task management
	 */
	//@{
	/**
	 * \brief Default implemenation of AddTask()
	 *
	 * \details
	 * Convenience implementation that converts the \ref IACFUnknown
	 * into an \ref AAX_ITask . Implementations should override the
	 * version that provides an \ref AAX_ITask object.
	 */
	AAX_Result AddTask(IACFUnknown * iTask) AAX_OVERRIDE;
	AAX_Result CancelAllTasks() AAX_OVERRIDE;
	//@} Task management
	
protected:
	
	/**
	 * \brief Convenience method for adding versioned tasks
	 */
	virtual AAX_Result AddTask(std::unique_ptr<AAX_ITask> iTask);
	
public: ///////////////////////////////////////////////////////////////////////////// AAX_CTaskAgent

	/** @name Private member accessors
	 */
	//@{
	/*!
	 *  \brief Returns a pointer to the plug-in's controller interface
	 */
	AAX_IController* GetController (void) { return mController; };
	/*!
	 *  \brief Returns a pointer to the plug-in's data model interface
	 */
	AAX_IEffectParameters* GetEffectParameters (void) { return mEffectParameters; }
	//@}end Private member accessors
	
private:
	void ReleaseObjects();

	AAX_IController* mController = nullptr;
	AAX_IEffectParameters* mEffectParameters = nullptr;
};


#endif
