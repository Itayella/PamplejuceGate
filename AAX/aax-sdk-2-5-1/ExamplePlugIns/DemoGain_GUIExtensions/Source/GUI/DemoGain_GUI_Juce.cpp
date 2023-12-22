/*================================================================================================*/
/*
 *	Copyright 2010-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/
#include "DemoGain_GUI_Juce.h"
#include "DemoGain_ViewComponent.h"
#include "DemoGain_Defs.h"

// *******************************************************************************
// ROUTINE:	Create
// *******************************************************************************
AAX_IEffectGUI * AAX_CALLBACK DemoGain_GUI::Create ()
{
	return new DemoGain_GUI;
}

// *******************************************************************************
// METHOD:	CreateViewContents
// *******************************************************************************
void DemoGain_GUI::CreateViewContents ()
{
	mViewComponent = new DemoGain_ViewComponent ( this );
}

// *******************************************************************************
// METHOD:	ParameterUpdated
// *******************************************************************************
AAX_Result DemoGain_GUI::ParameterUpdated ( AAX_CParamID iParameterID )
{
	DemoGain_ViewComponent* viewComponent = dynamic_cast<DemoGain_ViewComponent *>(mViewComponent);
	if (viewComponent && ! strcmp( iParameterID, DemoGain_GainID ) )
	{
		viewComponent->UpdateGainParameter();
	}
	return AAX_SUCCESS;
}

// *******************************************************************************
// METHOD:	setControlHighlightInfo
// *******************************************************************************
AAX_Result DemoGain_GUI::SetControlHighlightInfo (AAX_CParamID iParameterID, AAX_CBoolean iIsHighlighted, AAX_EHighlightColor iColor)
{
	DemoGain_ViewComponent* viewComponent = dynamic_cast<DemoGain_ViewComponent *>(mViewComponent);
	if ( viewComponent )
		return viewComponent->setControlHighlightInfo ( iParameterID, iIsHighlighted != 0, (AAX_EHighlightColor) iColor );
	
	return AAX_SUCCESS;
}
