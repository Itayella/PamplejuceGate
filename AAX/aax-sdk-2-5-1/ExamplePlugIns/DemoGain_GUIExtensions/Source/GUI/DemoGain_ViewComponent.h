/*================================================================================================*/
/*
 *	Copyright 2010-2015, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoGain_ViewComponent.h
 *
 *	\brief  DemoGain_ViewComponent class definition.
 */ 
/*================================================================================================*/
#pragma once
#ifndef DEMOGAIN_VIEWCOMPONENT_H
#define DEMOGAIN_VIEWCOMPONENT_H

#include "AAX_CEffectGUI_Juce.h"

class DemoGain_SliderJuce;

//==============================================================================
class DemoGain_ViewComponent	: public AAX_JuceContentView
								, public juce::SliderListener
								, public juce::LabelListener
								, public juce::ButtonListener
{
public:	
	DemoGain_ViewComponent ( AAX_CEffectGUI * inEffectGUI );
	~DemoGain_ViewComponent() override;
	
public: ///////////////////////////////////////////// DemoGain_ViewComponent
	virtual void UpdateGainParameter();
	virtual void UpdateGainDefaultValue();

public: ///////////////////////////////////////////// AAX_JuceContentView
	AAX_Result	setControlHighlightInfo (AAX_CParamID iParameterID, AAX_CBoolean iIsHighlighted, AAX_EHighlightColor iColor) AAX_OVERRIDE;
	AAX_Result	TimerWakeup() AAX_OVERRIDE;
	
	void SetViewContainer ( AAX_IViewContainer * inViewContainer ) AAX_OVERRIDE; //TODO: notification hook would be better
	
protected:
	void sliderDragStarted (juce::Slider* inSlider) override;
	void sliderValueChanged (juce::Slider * inSlider) override;
	void sliderDragEnded (juce::Slider* inSlider) override;
	void labelTextChanged (juce::Label * labelThatHasChanged) override;
	void buttonClicked (juce::Button* button) override;
	
private:
	DemoGain_SliderJuce		* mGainSlider;
	juce::Label		* mGainText;
	juce::Label		* mMonoText;
	juce::TextButton	* mResizeButton;
	juce::Label		* mInputMeterText;
	juce::Label		* mOutputMeterText;
	juce::Slider		* mInputMeter;
	juce::Slider 	* mOutputMeter;
};	

#endif
