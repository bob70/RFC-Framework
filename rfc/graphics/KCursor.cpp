
/*
	RFC - KCursor.cpp
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

#include "../graphics/KCursor.h"
#include "../rfc.h"

KCursor::KCursor()
{
	RFC_INIT_VERIFIER;
	hCursor = 0;
}

bool KCursor::LoadFromResource(WORD resourceID)
{
	hCursor = (HCURSOR)::LoadImageW(KApplication::hInstance, MAKEINTRESOURCEW(resourceID), IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_DEFAULTCOLOR);
	if(hCursor)
		return true;	
	return false;
}

bool KCursor::LoadFromFile(const KString& filePath)
{
	hCursor = (HCURSOR)::LoadImageW(KApplication::hInstance, filePath, IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_DEFAULTCOLOR);
	if(hCursor)
		return true;	
	return false;
}

HCURSOR KCursor::GetHandle()
{
	return hCursor;
}

KCursor::~KCursor()
{
	if(hCursor)
		::DestroyCursor(hCursor);
}