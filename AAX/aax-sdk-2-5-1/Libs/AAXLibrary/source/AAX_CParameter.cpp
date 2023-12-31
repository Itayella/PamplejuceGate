/*================================================================================================*/
/*
 *	Copyright 2010-2015, 2018, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/** 
 *  \author David Tremblay
 *
 */
/*================================================================================================*/
#include "AAX_CParameter.h"


//----------------------------------------------------------------
// AAX_CParameterValue


template <>
bool		AAX_CParameterValue<bool>::GetValueAsBool(bool* value) const
{
	*value = mValue;
	return true;
}

template<>
bool		AAX_CParameterValue<int32_t>::GetValueAsInt32(int32_t* value) const
{
	*value = mValue;
	return true;
}

template<>
bool		AAX_CParameterValue<float>::GetValueAsFloat(float* value) const
{
	*value = mValue;
	return true;
}

template<>
bool		AAX_CParameterValue<double>::GetValueAsDouble(double* value) const
{
	*value = mValue;
	return true;
}

template<>
bool		AAX_CParameterValue<AAX_CString>::GetValueAsString(AAX_IString* value) const
{
	*value = mValue;
	return true;
}



//----------------------------------------------------------------
// AAX_CParameter

template <>
bool	AAX_CParameter<bool>::GetNormalizedValueFromBool(bool value, double *normalizedValue) const
{
	*normalizedValue = mTaperDelegate->RealToNormalized(value);
	return true;
}

template <>
bool	AAX_CParameter<int32_t>::GetNormalizedValueFromInt32(int32_t value, double *normalizedValue) const
{
	*normalizedValue = mTaperDelegate->RealToNormalized(value);
	return true;
}

template <>
bool	AAX_CParameter<float>::GetNormalizedValueFromFloat(float value, double *normalizedValue) const
{
	*normalizedValue = mTaperDelegate->RealToNormalized(value);
	return true;
}

template <>
bool	AAX_CParameter<double>::GetNormalizedValueFromDouble(double value, double *normalizedValue) const
{
	*normalizedValue = mTaperDelegate->RealToNormalized(value);
	return true;
}

template <>
bool		AAX_CParameter<bool>::GetBoolFromNormalizedValue(double inNormalizedValue, bool* value) const
{
	*value = mTaperDelegate->NormalizedToReal(inNormalizedValue);
	return true;
}

template<>
bool		AAX_CParameter<int32_t>::GetInt32FromNormalizedValue(double inNormalizedValue, int32_t* value) const
{
	*value = mTaperDelegate->NormalizedToReal(inNormalizedValue);
	return true;
}

template<>
bool		AAX_CParameter<float>::GetFloatFromNormalizedValue(double inNormalizedValue, float* value) const
{
	*value = mTaperDelegate->NormalizedToReal(inNormalizedValue);
	return true;
}

template<>
bool		AAX_CParameter<double>::GetDoubleFromNormalizedValue(double inNormalizedValue, double* value) const
{
	*value = mTaperDelegate->NormalizedToReal(inNormalizedValue);
	return true;
}

template<>
bool		AAX_CParameter<AAX_CString>::GetValueAsString(AAX_IString *value) const
{
	return mValue.GetValueAsString(value);
}

template<>
bool		AAX_CParameter<bool>::SetValueWithBool(bool value)
{
	SetValue(value);
	return true;
}

template<>
bool		AAX_CParameter<int32_t>::SetValueWithInt32(int32_t value)
{
	SetValue(value);
	return true;
}

template<>
bool		AAX_CParameter<float>::SetValueWithFloat(float value)
{
	SetValue(value);
	return true;
}

template<>
bool		AAX_CParameter<double>::SetValueWithDouble(double value)
{
	SetValue(value);
	return true;
}

template<>
bool		AAX_CParameter<AAX_CString>::SetValueWithString(const AAX_IString& value)
{
	SetValue(value);
	return true;
}
