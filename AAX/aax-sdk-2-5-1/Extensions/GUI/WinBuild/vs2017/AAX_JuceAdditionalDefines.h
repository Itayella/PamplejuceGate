/*===================================================================================================
AAX_JuceAdditionalDefines.h

Copyright 2015, 2017, 2023 Avid Technology, Inc.
All rights reserved.

CONFIDENTIAL: this document contains confidential information of Avid. Do
not disclose to any third party. Use of the information contained in this
document is subject to an Avid SDK license.
===================================================================================================*/

#if defined _MSC_VER
#if _MSC_VER <= 1900
#define fseeko fseek
#define ftello ftell
#endif
#endif
