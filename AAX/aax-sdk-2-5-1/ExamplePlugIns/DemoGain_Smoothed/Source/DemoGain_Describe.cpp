/*================================================================================================*/
/*
 *	Copyright 2014-2015, 2017, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/

// DemoGain Includes
#include "DemoGain_Describe.h"
#include "DemoGain_Defs.h"
#include "DemoGain_Alg.h"
#include "DemoGain_Parameters.h"

// AAX Includes
#include "AAX_ICollection.h"
#include "AAX_IComponentDescriptor.h"
#include "AAX_IEffectDescriptor.h"
#include "AAX_IPropertyMap.h"
#include "AAX_Exception.h"
#include "AAX_Errors.h"
#include "AAX_Assert.h"


// ***************************************************************************
// ROUTINE:	DescribeAlgorithmComponent
// Algorithm component description
// ***************************************************************************
static void DescribeAlgorithmComponent( AAX_IComponentDescriptor* outDesc )
{
	AAX_CheckedResult err;
	
	// Describe algorithm's context structure
	//
	// Subscribe context fields to host-provided services or information
	err = outDesc->AddAudioIn (eAlgFieldID_AudioIn);
	err = outDesc->AddAudioOut (eAlgFieldID_AudioOut);
	err = outDesc->AddAudioBufferLength (eAlgFieldID_BufferSize);
	err = outDesc->AddSampleRate (eAlgFieldID_SampleRate);
	static_assert(eMeterTap_Count == sizeof(cDemoGain_MeterID)/sizeof(AAX_CTypeID), "unexpected meter tap array size");
	err = outDesc->AddMeters ( eAlgFieldID_Meters, cDemoGain_MeterID, eMeterTap_Count );
    //
	// Register context fields as communications destinations (i.e. input)
	err = outDesc->AddDataInPort ( eAlgPortID_BypassIn, sizeof (int32_t) );
	err = outDesc->AddDataInPort ( eAlgPortID_TargetCoefsGainIn, sizeof (SDemoGain_CoefsGain) );
	//
	// Register private data fields
	err = outDesc->AddPrivateData( eAlgPortID_CurCoefsGain, sizeof (SDemoGain_CoefsGain), AAX_ePrivateDataOptions_DefaultOptions);
	
	// Register processing callbacks
	//
	// Create a property map 
	AAX_IPropertyMap* const properties = outDesc->NewPropertyMap();
	if ( !properties )
		err = AAX_ERROR_NULL_OBJECT;
	//
	// Generic properties
	err = properties->AddProperty ( AAX_eProperty_ManufacturerID, cDemoGain_ManufactureID );
	err = properties->AddProperty ( AAX_eProperty_ProductID, cDemoGain_ProductID );
	err = properties->AddProperty ( AAX_eProperty_CanBypass, true );
	err = properties->AddProperty ( AAX_eProperty_UsesClientGUI, true ); // Uses auto-GUI
	//
	// Stem format -specific properties
	err = properties->AddProperty ( AAX_eProperty_InputStemFormat, AAX_eStemFormat_Mono );
	err = properties->AddProperty ( AAX_eProperty_OutputStemFormat, AAX_eStemFormat_Mono );
	//
	// ID properties
	err = properties->AddProperty ( AAX_eProperty_PlugInID_Native, cDemoGain_PlugInID_Native );
	err = properties->AddProperty ( AAX_eProperty_PlugInID_AudioSuite, cDemoGain_PlugInID_AudioSuite );	// for offline processing
	err = properties->AddProperty ( AAX_eProperty_PlugInID_TI, cDemoGain_PlugInID_TI );
	
    // Register Native callback
	err = outDesc->AddProcessProc_Native ( DemoGain_AlgorithmProcessFunction, properties );
	
	// TI-specific properties
#ifndef AAX_TI_BINARY_IN_DEVELOPMENT // Define this macro when using a debug TI DLL to allocate only 1 instance per chip
	err = properties->AddProperty ( AAX_eProperty_TI_InstanceCycleCount, 140 );
	err = properties->AddProperty ( AAX_eProperty_TI_SharedCycleCount, 80 );
#endif
	err = properties->AddProperty ( AAX_eProperty_DSP_AudioBufferLength, AAX_eAudioBufferLengthDSP_Default );
	
	// Register TI callback
	err = outDesc->AddProcessProc_TI ("DemoGain_Smoothed_MM_TI_Example.dll", "AlgEntry", properties );
}

// ***************************************************************************
// ROUTINE:	DescribeEffect
// ***************************************************************************
static AAX_Result DescribeEffect( AAX_IEffectDescriptor* outDescriptor )
{
	AAX_CheckedResult err;
	AAX_IComponentDescriptor* const compDesc = outDescriptor->NewComponentDescriptor ();
	if ( !compDesc )
		err = AAX_ERROR_NULL_OBJECT;
	
	// Effect identifiers
	//
	err = outDescriptor->AddName ( "Demo Gain (Smoothed)" );
	err = outDescriptor->AddName ( "Demo Gain" );
	err = outDescriptor->AddName ( "DemoGain" );
	err = outDescriptor->AddName ( "DmGain" );
	err = outDescriptor->AddName ( "DGpr" );
	err = outDescriptor->AddName ( "Dn" );
	err = outDescriptor->AddCategory ( AAX_ePlugInCategory_Example );
	
	// Effect components
	//
	// Algorithm component
	{
		AAX_AggregateResult agg;
		AAX_CAPTURE_MULT( agg,
			err = compDesc->Clear();
			DescribeAlgorithmComponent( compDesc );
			err = outDescriptor->AddComponent( compDesc );
		);
	}
	//
	// Data model
	err = outDescriptor->AddProcPtr( reinterpret_cast<void*>(DemoGain_Parameters::Create), kAAX_ProcPtrID_Create_EffectParameters );
	err = outDescriptor->AddResourceInfo ( AAX_eResourceType_PageTable, "DemoGainPages.xml" );
	
	// Effect's meter display properties
	//
	// Input meter
	{
		AAX_IPropertyMap* const meterProperties = outDescriptor->NewPropertyMap();
		if ( !meterProperties )
			err = AAX_ERROR_NULL_OBJECT;
		
		err = meterProperties->AddProperty ( AAX_eProperty_Meter_Type, AAX_eMeterType_Input );
		err = meterProperties->AddProperty ( AAX_eProperty_Meter_Orientation, AAX_eMeterOrientation_Default );
		err = outDescriptor->AddMeterDescription( cDemoGain_MeterID[eMeterTap_PreGain], "Input", meterProperties );
	}
	// Output meter
	{
		AAX_IPropertyMap* const meterProperties = outDescriptor->NewPropertyMap();
		if ( !meterProperties )
			err = AAX_ERROR_NULL_OBJECT;
		
		err = meterProperties->AddProperty ( AAX_eProperty_Meter_Type, AAX_eMeterType_Output );
		err = meterProperties->AddProperty ( AAX_eProperty_Meter_Orientation, AAX_eMeterOrientation_Default );
		err = outDescriptor->AddMeterDescription( cDemoGain_MeterID[eMeterTap_PostGain], "Output", meterProperties );
	}
	
	return err;
}

// ***************************************************************************
// ROUTINE:	GetEffectDescriptions
// ***************************************************************************
AAX_Result GetEffectDescriptions( AAX_ICollection* outCollection )
{
	AAX_CheckedResult err;
	AAX_IEffectDescriptor* const plugInDescriptor = outCollection->NewDescriptor();
	if ( plugInDescriptor )
	{
		AAX_SWALLOW_MULT(
			err = DescribeEffect( plugInDescriptor );
			err = outCollection->AddEffect( kEffectID_DemoGain, plugInDescriptor );
		);
	}
	else
		err = AAX_ERROR_NULL_OBJECT;
	
	err = outCollection->SetManufacturerName( "Avid" );
	err = outCollection->AddPackageName( "DemoGain (Smoothed) AAX SDK Example Plug-In" );
	err = outCollection->AddPackageName( "DemoGain (Smoothed)" );
	err = outCollection->AddPackageName( "DemoGain" );
	err = outCollection->AddPackageName( "DmGi" );
	err = outCollection->SetPackageVersion( 1 );
	
	return err;
}
