/*================================================================================================*/
/*
 *	Copyright 2014-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/

#include "TI_Alg_Common.h"
#include "RectiFi_Alg.h"
#include "DPA.h"		// For int32_t
#include <stddef.h>		// For offsetof()

// The Description function is a TI-only hack for the time being -- really we'd want all this in the master module.
// The order in which blocks are added to the AlgDescriptionClient must match the plug-in's instance
// block structure.
template<AAX_CStemFormat kStemFormatIn, AAX_CStemFormat kStemFormatOut>
void RectiFi_Algorithm_DescriptionFunction(AlgDescriptionClient* inDescClient )
{
	inDescClient->SetWindowSize(kAAX_TIAudioBufferLength_Default);

	inDescClient->AddBlock(kAAX_FieldTypeAudioIn, 0, eAlgFieldIndex_AudioIn, kStemFormatIn);
	inDescClient->AddBlock(kAAX_FieldTypeAudioOut, 0, eAlgFieldIndex_AudioOut, kStemFormatOut);

	inDescClient->AddBlock(kAAX_FieldTypeDataIn, eAtomic|eReadOnly, eAlgPortID_CoefsPreFiltIn, sizeof(SRectiFiCoefs_PreFilter));
	inDescClient->AddBlock(kAAX_FieldTypeDataIn, eAtomic|eReadOnly, eAlgPortID_RectiTypeIn, sizeof(int32_t));
	inDescClient->AddBlock(kAAX_FieldTypeDataIn, eAtomic|eReadOnly, eAlgPortID_GainIn, sizeof(float));
	inDescClient->AddBlock(kAAX_FieldTypeDataIn, eAtomic|eReadOnly, eAlgPortID_CoefsPostFiltIn, sizeof(SRectiFiCoefs_PostFilter));
	inDescClient->AddBlock(kAAX_FieldTypeDataIn, eAtomic|eReadOnly, eAlgPortID_CoefsEffectMixIn, sizeof(SRectiFiCoefs_EffectMix));

	inDescClient->AddBlock(kAAX_FieldTypePrivateData, eAtomic|eReadOnly, eAlgFieldIndex_State, sizeof(SRectiFiStateBlock));
}
