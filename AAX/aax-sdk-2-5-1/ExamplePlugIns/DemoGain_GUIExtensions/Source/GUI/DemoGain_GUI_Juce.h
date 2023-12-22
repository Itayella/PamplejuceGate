/*================================================================================================*/
/*
 *	Copyright 2013-2015, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoGain_GUI_Juce.h
 *
 *	\brief	DemoGain_GUI class definition.
 */ 
/*================================================================================================*/
#pragma once
#ifndef DEMOGAIN_GUI_JUCE_H
#define DEMOGAIN_GUI_JUCE_H

#include "AAX_CEffectGUI_Juce.h"

class DemoGain_ViewComponent;

//==============================================================================
class DemoGain_GUI : public AAX_CEffectGUI_Juce
{
public:
	static AAX_IEffectGUI *		AAX_CALLBACK Create (void);

	DemoGain_GUI() : AAX_CEffectGUI_Juce() {};
	AAX_DEFAULT_DTOR_OVERRIDE(DemoGain_GUI);

	void				CreateViewContents () AAX_OVERRIDE;
	AAX_Result			ParameterUpdated ( AAX_CParamID iParameterID ) AAX_OVERRIDE;
	AAX_Result			SetControlHighlightInfo (AAX_CParamID iParameterID, AAX_CBoolean iIsHighlighted, AAX_EHighlightColor iColor) AAX_OVERRIDE;
};

#endif // DEMOGAIN_GUI_JUCE_H
