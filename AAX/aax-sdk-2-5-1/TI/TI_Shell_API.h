/*================================================================================================*/
/*
 *	Copyright 2010-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**  
 *	\file   TI_Shell_API.h
 *
 *  \brief  DLL import / export interface defines
 *
 *  \author Paul Vercellotti
 */ 
/*================================================================================================*/
#ifndef TI_SHELL_API_H
#define TI_SHELL_API_H

#ifdef  _TMS320C6X	// TI-only

#include <elf_linkage.h>

#if TISHELL

#define TI_SHELL_API far __declspec(dllexport)

#else

#define TI_SHELL_API far __declspec(dllimport)

#endif // TI_SHELL_BUILD

#endif // _TMS320C6X

#endif

