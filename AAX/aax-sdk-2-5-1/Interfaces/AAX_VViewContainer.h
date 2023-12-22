/*================================================================================================*/
/*
 *
 *	Copyright 2013-2017, 2019, 2021, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file  AAX_VViewContainer.h
 *
 *	\brief Version-managed concrete ViewContainer class
 *
 */ 
/*================================================================================================*/

#ifndef AAX_VVIEWCONTAINER_H
#define AAX_VVIEWCONTAINER_H

#include "AAX_IViewContainer.h"
#include "AAX_IACFViewContainer.h"
#include "ACFPtr.h"


class IACFUnknown;

/**
 *	\brief Version-managed concrete \ref AAX_IViewContainer class
 *
 */
class AAX_VViewContainer : public AAX_IViewContainer
{
public:
	AAX_VViewContainer( IACFUnknown * pUnknown );
	 ~AAX_VViewContainer() AAX_OVERRIDE;
	
    // AAX_IACFViewContainer
    
	// Getters
	int32_t		GetType () AAX_OVERRIDE; ///< \copydoc AAX_IViewContainer::GetType()
    void *		GetPtr () AAX_OVERRIDE; ///< \copydoc AAX_IViewContainer::GetPtr()
	AAX_Result	GetModifiers ( uint32_t * outModifiers ) AAX_OVERRIDE; ///< \copydoc AAX_IViewContainer::GetModifiers()

	// Setters
    AAX_Result	SetViewSize ( AAX_Point & inSize ) AAX_OVERRIDE; ///< \copydoc AAX_IViewContainer::SetViewSize()
	AAX_Result	HandleParameterMouseDown  ( AAX_CParamID inParamID, uint32_t inModifiers ) AAX_OVERRIDE; ///< \copydoc AAX_IViewContainer::HandleParameterMouseDown()
	AAX_Result	HandleParameterMouseDrag  ( AAX_CParamID inParamID, uint32_t inModifiers ) AAX_OVERRIDE; ///< \copydoc AAX_IViewContainer::HandleParameterMouseDrag()
	AAX_Result	HandleParameterMouseUp    ( AAX_CParamID inParamID, uint32_t inModifiers ) AAX_OVERRIDE; ///< \copydoc AAX_IViewContainer::HandleParameterMouseUp()
	AAX_Result	HandleParameterMouseEnter ( AAX_CParamID inParamID, uint32_t inModifiers ) AAX_OVERRIDE; ///< \copydoc AAX_IViewContainer::HandleParameterMouseEnter()
	AAX_Result	HandleParameterMouseExit  ( AAX_CParamID inParamID, uint32_t inModifiers ) AAX_OVERRIDE; ///< \copydoc AAX_IViewContainer::HandleParameterMouseExit()
	AAX_Result	HandleMultipleParametersMouseDown ( const AAX_CParamID* inParamIDs, uint32_t inNumOfParams, uint32_t inModifiers ) AAX_OVERRIDE; ///< \copydoc AAX_IViewContainer::HandleMultipleParametersMouseDown()
	AAX_Result	HandleMultipleParametersMouseDrag ( const AAX_CParamID* inParamIDs, uint32_t inNumOfParams, uint32_t inModifiers ) AAX_OVERRIDE; ///< \copydoc AAX_IViewContainer::HandleMultipleParametersMouseDrag()
	AAX_Result	HandleMultipleParametersMouseUp   ( const AAX_CParamID* inParamIDs, uint32_t inNumOfParams, uint32_t inModifiers ) AAX_OVERRIDE; ///< \copydoc AAX_IViewContainer::HandleMultipleParametersMouseUp()
	
private:
	ACFPtr<AAX_IACFViewContainer>	    mIViewContainer;
	ACFPtr<AAX_IACFViewContainer_V2>	mIViewContainerV2;
	ACFPtr<AAX_IACFViewContainer_V3>    mIViewContainerV3;
};


#endif //AAX_VVIEWCONTAINER_H
