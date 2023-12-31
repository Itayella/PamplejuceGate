/*================================================================================================*/
/*
 *	Copyright 2009-2015, 2018-2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   DemoDist_Parameters.h
 *
 *	\brief  DemoDist_Parameters class declaration.
 */ 
/*================================================================================================*/ 

#pragma once
#ifndef DEMODIST_PARAMETERS_H
#define DEMODIST_PARAMETERS_H

#include "AAX_CEffectParameters.h"


//==============================================================================
class DemoDist_Parameters : public AAX_CEffectParameters
{
public:
	DemoDist_Parameters ();
	AAX_DEFAULT_DTOR_OVERRIDE (DemoDist_Parameters);
	
	// Create callback
	static AAX_CEffectParameters * AAX_CALLBACK Create();
	
public:
	//Overrides from AAX_CEffectParameters
	AAX_Result EffectInit() AAX_OVERRIDE;
	AAX_Result ResetFieldData (AAX_CFieldIndex inFieldIndex, void * oData, uint32_t iDataSize) const AAX_OVERRIDE;
	AAX_Result UpdateParameterNormalizedValue(AAX_CParamID iParameterID, double aValue, AAX_EUpdateSource inSource) AAX_OVERRIDE;
	AAX_Result GenerateCoefficients() AAX_OVERRIDE;
	
private:
	//Control flags
	bool	mDirtyBypassFlag;
	bool	mDirtyMixFlag;
	bool	mDirtyFiltFlag;
	bool	mDirtyDistFlag;
	bool	mDirtyInpGainFlag;
	bool	mDirtyOutGainFlag;
};


#endif
