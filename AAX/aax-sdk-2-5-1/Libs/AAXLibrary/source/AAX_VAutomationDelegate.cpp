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

#include "AAX_VAutomationDelegate.h"
#include "AAX_IACFController.h"
#include "AAX_UIDs.h"
#include <algorithm>
#include <iterator>

// ******************************************************************************************
// METHOD:	AAX_VAutomationDelegate
// ******************************************************************************************
AAX_VAutomationDelegate::AAX_VAutomationDelegate( IACFUnknown * pUnknown )
{
	if ( pUnknown )
	{
		pUnknown->QueryInterface(IID_IAAXAutomationDelegateV1, (void **)&mIAutomationDelegate);
		pUnknown->QueryInterface(IID_IAAXControllerV2, (void**)&mIController);
	}
}

// ******************************************************************************************
// METHOD:	~AAX_VAutomationDelegate
// ******************************************************************************************
AAX_VAutomationDelegate::~AAX_VAutomationDelegate()
{
}

// ******************************************************************************************
// METHOD:	RegisterControl
// ******************************************************************************************
AAX_Result AAX_VAutomationDelegate::RegisterParameter ( AAX_CParamID iParameterID )
{
	if ( mIAutomationDelegate )
		return mIAutomationDelegate->RegisterParameter ( iParameterID );
	
	return AAX_ERROR_NULL_OBJECT;
}

// ******************************************************************************************
// METHOD:	UnregisterControl
// ******************************************************************************************
AAX_Result AAX_VAutomationDelegate::UnregisterParameter ( AAX_CParamID iParameterID )
{
	if ( mIAutomationDelegate )
		return mIAutomationDelegate->UnregisterParameter ( iParameterID );
	
	return AAX_ERROR_NULL_OBJECT;
}

// ******************************************************************************************
// METHOD:	PostSetValueRequest
// ******************************************************************************************
AAX_Result AAX_VAutomationDelegate::PostSetValueRequest ( AAX_CParamID iParameterID, double iNormalizedValue ) const
{
	if ( mIAutomationDelegate )
		return mIAutomationDelegate->PostSetValueRequest ( iParameterID, iNormalizedValue );
	
	return AAX_ERROR_NULL_OBJECT;
}

// ******************************************************************************************
// METHOD:	PostCurrentValue
// ******************************************************************************************
AAX_Result AAX_VAutomationDelegate::PostCurrentValue ( AAX_CParamID iParameterID, double iNormalizedValue ) const
{
	if ( mIAutomationDelegate )
		return mIAutomationDelegate->PostCurrentValue ( iParameterID, iNormalizedValue );
	
	return AAX_ERROR_NULL_OBJECT;
}

// ******************************************************************************************
// METHOD:	PostTouchRequest
// ******************************************************************************************
AAX_Result AAX_VAutomationDelegate::PostTouchRequest ( AAX_CParamID iParameterID )
{
	if ( mIAutomationDelegate )
		return mIAutomationDelegate->PostTouchRequest ( iParameterID );
	
	return AAX_ERROR_NULL_OBJECT;
}

// ******************************************************************************************
// METHOD:	PostReleaseRequest
// ******************************************************************************************
AAX_Result AAX_VAutomationDelegate::PostReleaseRequest ( AAX_CParamID iParameterID )
{
	if ( mIAutomationDelegate )
		return mIAutomationDelegate->PostReleaseRequest ( iParameterID );
	
	return AAX_ERROR_NULL_OBJECT;
}

// ******************************************************************************************
// METHOD:	GetTouchState
// ******************************************************************************************
AAX_Result AAX_VAutomationDelegate::GetTouchState ( AAX_CParamID iParameterID, AAX_CBoolean * outTouched )
{
	if ( mIAutomationDelegate )
		return mIAutomationDelegate->GetTouchState ( iParameterID, outTouched );
	
	return AAX_ERROR_NULL_OBJECT;
}

// ******************************************************************************************
// METHOD:	ParameterNameChanged
// ******************************************************************************************
AAX_Result AAX_VAutomationDelegate::ParameterNameChanged ( AAX_CParamID iParameterID )
{
	if ( mIController ) {
		auto const end = iParameterID + kAAX_ParameterIdentifierMaxSize;
		auto const found = std::find(iParameterID, end, '\0');
		if (end != found) {
			auto const len = std::distance(iParameterID, found);
			if (len > 0) {
				return mIController->SendNotification (AAX_eNotificationEvent_ParameterNameChanged, iParameterID, sizeof(char) * (static_cast<unsigned int>(len)+1));
			}
		}
		return AAX_ERROR_INVALID_PARAMETER_ID;
	}
	
	return AAX_ERROR_UNIMPLEMENTED;
}
