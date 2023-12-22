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
 *  \file AAX_JuceCount.h
 *
 */
/*================================================================================================*/

#ifndef AAX_JuceCount_H
#define AAX_JuceCount_H

class AAX_JuceCount
{
public:
	AAX_JuceCount ();
	virtual ~AAX_JuceCount ();
	
protected:
	static bool			IncrementJuceUseCout ();
	static bool			DecrementJuceUseCout ();
	
protected:
	static int32_t			sJuceUseCount;
};

#endif
