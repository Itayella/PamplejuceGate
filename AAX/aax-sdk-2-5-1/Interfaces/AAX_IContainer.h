/*================================================================================================*/
/*
 *
 *	Copyright 2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

/**	
 *  \file AAX_IContainer.h
 *
 *	\brief Abstract container interface
 *
 */
/*================================================================================================*/
/// @cond ignore
#ifndef AAX_ICONTAINER_H
#define AAX_ICONTAINER_H
/// @endcond


/** Abstract container interface
 */
class AAX_IContainer
{
public:
	virtual ~AAX_IContainer() {}
	
public:
	enum EStatus
	{
		eStatus_Success = 0          ///< Operation succeeded
		,eStatus_Overflow = 1        ///< Internal buffer overflow
		,eStatus_NotInitialized = 2  ///< Uninitialized container
		,eStatus_Unavailable = 3     ///< An internal resource was not available
		,eStatus_Unsupported = 4     ///< Operation is unsupported
	};
	
public:
	/** Clear the container
	 */
	virtual void Clear() = 0;
};

/// @cond ignore
#endif /* defined(AAX_ICONTAINER_H) */
/// @endcond
