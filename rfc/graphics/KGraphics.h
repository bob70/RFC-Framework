
/*
	RFC -KGraphics.h
	Copyright (C) 2013-2017 CrownSoft
  
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

#ifndef _RFC_KGRAPHICS_H_
#define _RFC_KGRAPHICS_H_

#include <windows.h>
#include "../config.h"

class RFC_API KGraphics
{
public:
	KGraphics();

	virtual ~KGraphics();

	static void Draw3dVLine(HDC hdc, int startX, int startY, int height);

	static void Draw3dHLine(HDC hdc, int startX, int startY, int width);

	static void Draw3dRect(HDC hdc, LPCRECT lpRect, COLORREF clrTopLeft, COLORREF clrBottomRight);

	static void Draw3dRect(HDC hdc, int x, int y, int cx, int cy, COLORREF clrTopLeft, COLORREF clrBottomRight);

	static void FillSolidRect(HDC hdc, int x, int y, int cx, int cy, COLORREF color);

	static void FillSolidRect(HDC hdc, LPCRECT lpRect, COLORREF color);

	static RECT CalculateTextSize(wchar_t *text, HFONT hFont);
};

#endif