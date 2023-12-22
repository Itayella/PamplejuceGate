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

// DemoDelay Includes
#include "DemoDelay_Describe.h"
#include "HostProcessor/HostProcessor_Describe.h"
#include "HostProcessor_Comp/HostProcessor_Comp_Describe.h"

// AAX Includes
#include "AAX_ICollection.h"
#include "AAX_Exception.h"

// ***************************************************************************
// ROUTINE:	GetEffectDescriptions
// ***************************************************************************
AAX_Result GetEffectDescriptions( AAX_ICollection * outCollection )
{
    AAX_CheckedResult err;
	
	// This plug-in includes two separate Effects
	//	Delay: This effect implements a standard delay algorithm using the Host Processor interface. The
	//		behavior of this Effect is identical to that of the standard DemoDelay AudioSuite plug-in.
	//	Delay Comp: This effect demonstrates the Host Processor interface's random-access functionality
	//		by "compensating" for its algorithm's delay and place input samples back into their original
	//		location on the timeline.
	err = HostProcessor_GetEffectDescriptions( outCollection );
	err = HostProcessor_Comp_GetEffectDescriptions( outCollection );
	
	err = outCollection->SetManufacturerName( "Avid" );
	err = outCollection->AddPackageName( "DemoDelay (HostProcessor) AAX SDK Example Plug-In" );
	err = outCollection->AddPackageName( "DemoDelay (HostProcessor)" );
	err = outCollection->AddPackageName( "DemoDelay HostProcessor" );
	err = outCollection->AddPackageName( "DemoDelay HP" );
	err = outCollection->AddPackageName( "DemoDelay" );
	err = outCollection->AddPackageName( "DmDly" );
	err = outCollection->SetPackageVersion( 1 );		
	
	return err;
}
