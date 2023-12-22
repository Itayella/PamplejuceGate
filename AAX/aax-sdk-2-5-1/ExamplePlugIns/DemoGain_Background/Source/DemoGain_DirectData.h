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
 *	\file   DemoGain_DirectData.h
 */ 
/*================================================================================================*/
#pragma once
#ifndef _DEMOGAIN_DIRECTDATA_H_
#define _DEMOGAIN_DIRECTDATA_H_


#include "AAX_CEffectDirectData.h"

#include "DemoGain_Alg.h"


class AAX_IPrivateDataAccess;


class DemoGain_DirectData : public AAX_CEffectDirectData
{
public:
	//Constructor
	DemoGain_DirectData (void);
	
	//Overrides from AAX_CEffectDirectData
	AAX_Result			TimerWakeup_PrivateDataAccess(AAX_IPrivateDataAccess* iPrivateDataAccess);
	
	static AAX_CEffectDirectData *AAX_CALLBACK Create();
	
private:
	DelaySamp mCachedDelay;
};

#endif // _DEMOGAIN_DIRECTDATA_H_
