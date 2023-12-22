/*================================================================================================*/
/*
 *
 *	Copyright 2014-2015, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 *
 */

#ifndef AAX_CMUTEX_H
#define AAX_CMUTEX_H

/**  
 *	\file  AAX_CMutex.h
 *
 *	\brief Mutex
 *
 */ 
/*================================================================================================*/

/**	\brief Mutex with try lock functionality
 */
class AAX_CMutex
{
public:
	AAX_CMutex();
	~AAX_CMutex();
	
    bool Lock();
    void Unlock();
    bool Try_Lock();
	
private:
    AAX_CMutex(const AAX_CMutex&);
    AAX_CMutex& operator=(const AAX_CMutex&);

	typedef struct opaque_aax_mutex_t * aax_mutex_t;	
	aax_mutex_t		mMutex;	
};

/** \brief Helper class for working with mutex
 */
class AAX_StLock_Guard
{
public:
    explicit AAX_StLock_Guard(AAX_CMutex& iMutex) : mMutex(iMutex) { mNeedsUnlock = mMutex.Lock(); }
    ~AAX_StLock_Guard() { if (mNeedsUnlock) mMutex.Unlock(); }
	
private:	
    AAX_StLock_Guard(AAX_StLock_Guard const&);
    AAX_StLock_Guard& operator=(AAX_StLock_Guard const&);

	AAX_CMutex &	mMutex;
	bool			mNeedsUnlock;
};

#endif // AAX_CMUTEX_H

