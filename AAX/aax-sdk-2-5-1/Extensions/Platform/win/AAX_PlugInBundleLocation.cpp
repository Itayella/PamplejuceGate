/*================================================================================================*/
/*
 *	Copyright 2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */
/*================================================================================================*/

#include "AAX_PlugInBundleLocation.h"
#include <intrin.h>
#include <windows.h>
#pragma intrinsic(_ReturnAddress)

bool AAX::GetPathToPlugInBundle (const char* iBundleName, int iMaxLength, char* oModuleName)
{
	if (!oModuleName)
		return false;

	HMODULE module = NULL;
	int success = GetModuleHandleEx( GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS|GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)_ReturnAddress(), &module);

	if (success)
	{
		if ((0 == GetModuleFileName(module,oModuleName,iMaxLength)) ||
			(ERROR_SUCCESS != GetLastError()))
			return false;
	}
	else
		return false;

	int len = strlen(oModuleName);
	int goUpLevels = 3;
	for (int i = len-1; goUpLevels && i >= 0; --i)
	{
		if (oModuleName[i] == '\\' || oModuleName[i] == '/')
			--goUpLevels;

		oModuleName[i] = '\0';
	}

	if (goUpLevels) // something went wrong
		return false;

	return true;
}
