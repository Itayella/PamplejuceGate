/*================================================================================================*/
/*
 *	Copyright 2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**
 *  \file AAX_MIDILogging.h
 *
 *	\brief	Utilities for logging MIDI data
 */
/*================================================================================================*/

/// @cond ignore
#ifndef AAX_MIDILOGGING_H
#define AAX_MIDILOGGING_H
/// @endcond

// AAX Includes
#include "AAX.h"

namespace AAX
{
	/** @name MIDI logging utilities
	 */
	//@{
	/** Print a MIDI stream as a C-string
		
		@details
		Sets an empty string in release builds
		
		@ingroup OtherExtensions
	*/
	void AsStringMIDIStream_Debug(const AAX_CMidiStream& inStream, char* outBuffer, int32_t inBufferSize);
	//@} MIDI logging utilities
}

/// @cond ignore
#endif // AAX_MIDILOGGING_H
/// @endcond
