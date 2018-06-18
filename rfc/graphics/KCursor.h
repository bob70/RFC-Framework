
/*
	RFC - KCursor.h
	Copyright (C) 2013-2018 CrownSoft
  
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

#ifndef _RFC_KCURSOR_H_
#define _RFC_KCURSOR_H_

#include "../text/KString.h"
#include <windows.h>

/**
	Can be use to load cursor from file or resource.
*/
class RFC_API KCursor
{
protected:
	HCURSOR hCursor;

public:
	KCursor();

	/**
		Loads cursor from resource
		@param resourceID resource ID of cursor file
		@returns false if cursor load fails
	*/
	bool LoadFromResource(WORD resourceID);

	/**
		Loads cursor from file
		@param filePath path to cursor file
		@returns false if cursor load fails
	*/
	bool LoadFromFile(const KString& filePath);

	/**
		Returns cursor handle
	*/
	HCURSOR GetHandle();

	virtual ~KCursor();
};

#endif