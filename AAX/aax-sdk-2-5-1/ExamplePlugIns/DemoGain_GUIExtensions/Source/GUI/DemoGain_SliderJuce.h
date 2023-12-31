/*================================================================================================*/
/*
 *	Copyright 2011-2015, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoGain_SliderJuce.h
 *
 *	\author Rob Majors
 */ 
/*================================================================================================*/
#pragma once
#ifndef DEMOGAIN_SLIDERJUCE_H
#define DEMOGAIN_SLIDERJUCE_H

#include "DemoGain_Defs.h"
#include "AAX_IViewContainer.h"
#include "juce.h"

class DemoGain_SliderJuce : public juce::Slider
{
public: ///////////////////////////////////////// constructor/destructor
	explicit DemoGain_SliderJuce (const juce::String& componentName = juce::String::empty);
	~DemoGain_SliderJuce() override;
	
protected: ////////////////////////////////////// juce::Slider
	void mouseDown (const juce::MouseEvent& e) override; // HACK: Non-virtual in juce::Slider
    void mouseUp (const juce::MouseEvent& e) override;   // HACK: Non-virtual in juce::Slider
    void mouseDrag (const juce::MouseEvent& e) override; // HACK: Non-virtual in juce::Slider

public: ///////////////////////////////////////// DemoGain_SliderJuce
	void SetViewContainer (AAX_IViewContainer* viewContainer);
	void SetParamID (AAX_CParamID paramID);
	void SetDefaultValue (double value);
	
private: //////////////////////////////////////// DemoGain_SliderJuce
	uint32_t GetAAXModifiersFromJuceMouseEvent (const juce::MouseEvent& e);
	
private: //////////////////////////////////////// DemoGain_SliderJuce
	AAX_IViewContainer* mViewContainer;
	AAX_CParamID mParamID;
	juce::Value mDefaultValue;
};

#endif // DEMOGAIN_SLIDERJUCE_H
