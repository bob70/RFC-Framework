
/*
	RFC - KThread.cpp
	Copyright (C) 2013-2019 CrownSoft
  
	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1. The origin of this software must not be misrepresented; you must not
	   claim that you wrote the original software. If you use this software
	   in a product, an acknowledgment in the product documentation would be
	   appreciated but is not required.
	2. Altered source versions must be plainly marked as such, and must not be
	   misrepresented as being the original software.
	3. This notice may not be removed or altered from any source distribution.
	  
*/

#include "../rfc.h"
#include "KThread.h"


KThread::KThread()
{
	handle = 0; 
	runnable = NULL;
	threadShouldStop = false;
}

void KThread::SetHandle(HANDLE handle)
{
	this->handle = handle;
}

void KThread::SetRunnable(KRunnable *runnable)
{
	this->runnable = runnable;
}

HANDLE KThread::GetHandle()
{
	return handle;
}

KThread::operator HANDLE()const
{
	return handle;
}

bool KThread::ShouldRun()
{
	return !threadShouldStop;
}

void KThread::Run()
{
	if (runnable)
		runnable->Run(this);
}

bool KThread::IsThreadRunning()
{
	if (handle)
	{
		const DWORD result = ::WaitForSingleObject(handle, 0);
		return (result != WAIT_OBJECT_0);
	}

	return false;
}

void KThread::ThreadShouldStop()
{
	threadShouldStop = true;
}

void KThread::WaitUntilThreadFinish()
{
	::WaitForSingleObject(handle, INFINITE);
}

bool KThread::StartThread()
{
	threadShouldStop = false;

	if (handle) // close old handle
	{
		::CloseHandle(handle);
		handle = 0;
	}

	return ::CreateRFCThread(this);
}

void KThread::uSleep(int waitTime)
{
	__int64 time1 = 0, time2 = 0, freq = 0;

	QueryPerformanceCounter((LARGE_INTEGER *)&time1);
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

	do {
		QueryPerformanceCounter((LARGE_INTEGER *)&time2);
	} while ((time2 - time1) < ((waitTime * freq) / 1000000));
}

KThread::~KThread()
{
	if (handle)
		::CloseHandle(handle);
}
