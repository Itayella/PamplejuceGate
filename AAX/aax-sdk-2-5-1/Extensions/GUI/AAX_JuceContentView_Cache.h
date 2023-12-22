/*================================================================================================*/
/*
 *	Copyright 2011-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**	
 *  \file AAX_JuceContentView_Cache.h
 *
 */
/*================================================================================================*/
#pragma once
#ifndef AAX_JuceContentView_Cache_H
#define AAX_JuceContentView_Cache_H

#include "AAX.h"
#include "juce.h"
#include <map>

class AAX_CEffectGUI;
class AAX_JuceContentView;

//==============================================================================
// CLASS:	AAX_JuceContentView_Cache
//==============================================================================
class AAX_JuceContentView_Cache : public juce::DeletedAtShutdown
{
public:
	virtual ~AAX_JuceContentView_Cache ();
	
	static bool add ( AAX_CEffectGUI * inEffectGUI, AAX_JuceContentView * inContentView );
	static AAX_JuceContentView * get ( AAX_CEffectGUI * inEffectGUI );
	
private:
	void doAdd ( AAX_EStemFormat inInputStemFormat, AAX_EStemFormat inOutputStemFormat, AAX_JuceContentView * inContentView );
	AAX_JuceContentView * doGet ( AAX_EStemFormat inInputStemFormat, AAX_EStemFormat inOutputStemFormat );
	bool getStemFormats ( AAX_CEffectGUI * inEffectGUI, AAX_EStemFormat * outInputStemFormat, AAX_EStemFormat * outOutputStemFormat );
	
private:
	typedef std::pair<AAX_EStemFormat,AAX_EStemFormat>		TStemPair;
	typedef std::multimap<TStemPair,AAX_JuceContentView *>	TContentMap;
	TContentMap												mContentViews;
};

#endif
