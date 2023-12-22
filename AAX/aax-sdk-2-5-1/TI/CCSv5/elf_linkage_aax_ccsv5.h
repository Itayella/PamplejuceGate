//
//
// Copyright 2014, 2023 Avid Technology, Inc. All rights reserved.
// 
// CONFIDENTIAL: this document contains confidential information of Avid. Do
// not disclose to any third party. Use of the information contained in this
// document is subject to an Avid SDK license.
//
//

/*
The __binit__ section stores data that that needs to be copied at load-time. Plug-ins don't use it, but since our plug-ins are actually dynamic executables rather than dynamic libraries, we need to have the initialization functions just like a static executable � this is why we link to the RTS library and export the auto_init_elf function. But because we link to RTS, we need to handle __binit__.
*/
#pragma once
#ifndef _ELF_LINKAGE_AAX_CCSV5_H_
#define _ELF_LINKAGE_AAX_CCSV5_H_

#include <elf_linkage.h>

// #include <cpy_tbl.h>
// far const COPY_TABLE *__binit__;

far const int* __binit__;

#endif
