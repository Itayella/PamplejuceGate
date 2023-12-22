/*================================================================================================*/
/*
 *	Copyright 2014-2017, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/
// Host Alg wrapper shim headers
#include "DemoGain_Alg.h"
#include "../TI/CCSv5/elf_linkage_aax_ccsv5.h"

extern "C"
TI_EXPORT
void AlgEntry_1(	SDemoGain_Alg_Context * const		inInstancesBegin [],
				const void *						inInstancesEnd)
{
	DemoGain_AlgorithmProcessFunction<1> (
		inInstancesBegin,
		inInstancesEnd);
}

extern "C"
TI_EXPORT
void AlgEntry_2(	SDemoGain_Alg_Context * const		inInstancesBegin [],
				const void *						inInstancesEnd)
{
	DemoGain_AlgorithmProcessFunction<2> (
		inInstancesBegin,
		inInstancesEnd);
}

extern "C"
TI_EXPORT
void AlgEntry_3(	SDemoGain_Alg_Context * const		inInstancesBegin [],
				const void *						inInstancesEnd)
{
	DemoGain_AlgorithmProcessFunction<3> (
		inInstancesBegin,
		inInstancesEnd);
}

extern "C"
TI_EXPORT
void AlgEntry_4(	SDemoGain_Alg_Context * const		inInstancesBegin [],
				const void *						inInstancesEnd)
{
	DemoGain_AlgorithmProcessFunction<4> (
		inInstancesBegin,
		inInstancesEnd);
}

extern "C"
TI_EXPORT
void AlgEntry_5(	SDemoGain_Alg_Context * const		inInstancesBegin [],
				const void *						inInstancesEnd)
{
	DemoGain_AlgorithmProcessFunction<5> (
		inInstancesBegin,
		inInstancesEnd);
}

extern "C"
TI_EXPORT
void AlgEntry_6(	SDemoGain_Alg_Context * const		inInstancesBegin [],
				const void *						inInstancesEnd)
{
	DemoGain_AlgorithmProcessFunction<6> (
		inInstancesBegin,
		inInstancesEnd);
}

extern "C"
TI_EXPORT
void AlgEntry_7(	SDemoGain_Alg_Context * const		inInstancesBegin [],
				const void *						inInstancesEnd)
{
	DemoGain_AlgorithmProcessFunction<7> (
		inInstancesBegin,
		inInstancesEnd);
}

extern "C"
TI_EXPORT
void AlgEntry_8(	SDemoGain_Alg_Context * const		inInstancesBegin [],
				const void *						inInstancesEnd)
{
	DemoGain_AlgorithmProcessFunction<8> (
		inInstancesBegin,
		inInstancesEnd);
}

extern "C"
TI_EXPORT
void AlgEntry_9(	SDemoGain_Alg_Context * const		inInstancesBegin [],
				const void *						inInstancesEnd)
{
	DemoGain_AlgorithmProcessFunction<9> (
		inInstancesBegin,
		inInstancesEnd);
}

extern "C"
TI_EXPORT
void AlgEntry_10(	SDemoGain_Alg_Context * const		inInstancesBegin [],
				const void *						inInstancesEnd)
{
	DemoGain_AlgorithmProcessFunction<10> (
		inInstancesBegin,
		inInstancesEnd);
}

extern "C"
TI_EXPORT
void AlgEntry_16(   SDemoGain_Alg_Context * const       inInstancesBegin [],
                const void *                        inInstancesEnd)
{
    DemoGain_AlgorithmProcessFunction<16> (
        inInstancesBegin,
        inInstancesEnd);
}
