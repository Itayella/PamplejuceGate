/*================================================================================================*/
/*
 *
 *	Copyright 2014-2017, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**  
 *	\file  AAX_VAutomationDelegate.h
 *
 *	\brief Version-managed concrete AutomationDelegate  class
 *
 */ 
/*================================================================================================*/

#ifndef AAX_VAUTOMATIONDELEGATE_H
#define AAX_VAUTOMATIONDELEGATE_H

#include "AAX_IAutomationDelegate.h"
#include "AAX_IACFAutomationDelegate.h"
#include "ACFPtr.h"

class AAX_IACFAutomationDelegate;
class AAX_IACFController_V2;
class IACFUnknown;

/**
 *	\brief Version-managed concrete \ref AAX_IAutomationDelegate "automation delegate" class
 *
 */
class AAX_VAutomationDelegate : public AAX_IAutomationDelegate
{
public:
	AAX_VAutomationDelegate( IACFUnknown * pUnknown );
	~AAX_VAutomationDelegate() AAX_OVERRIDE;
	
	IACFUnknown*	GetUnknown() const { return mIAutomationDelegate; }
	
	AAX_Result		RegisterParameter ( AAX_CParamID iParameterID ) AAX_OVERRIDE;
	AAX_Result		UnregisterParameter ( AAX_CParamID iParameterID ) AAX_OVERRIDE;
	AAX_Result		PostSetValueRequest ( AAX_CParamID iParameterID, double iNormalizedValue ) const AAX_OVERRIDE;
	AAX_Result		PostCurrentValue ( AAX_CParamID iParameterID, double iNormalizedValue ) const AAX_OVERRIDE;
	AAX_Result		PostTouchRequest ( AAX_CParamID iParameterID ) AAX_OVERRIDE;
	AAX_Result		PostReleaseRequest ( AAX_CParamID iParameterID ) AAX_OVERRIDE;
	AAX_Result		GetTouchState ( AAX_CParamID iParameterID, AAX_CBoolean * outTouched ) AAX_OVERRIDE;
	AAX_Result		ParameterNameChanged ( AAX_CParamID iParameterID ) AAX_OVERRIDE;
	
private:
	ACFPtr<AAX_IACFAutomationDelegate>	mIAutomationDelegate;
	ACFPtr<AAX_IACFController_V2>	mIController;
};



#endif //AAX_IAUTOMATIONDELEGATE_H
