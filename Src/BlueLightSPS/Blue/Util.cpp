#include "stdafx.h"
#include "Util.h"


Util::Util()
{
}


Util::~Util()
{
}

void Util::SetWindowSize(HWND hWnd, int iWheight, int iHeight)
{
	CRect WindowRect;
	CRect ClientRect;
	GetWindowRect(hWnd, &WindowRect);
	GetClientRect(hWnd, &ClientRect);
	int deltaW = WindowRect.Width() - ClientRect.Width();
	int deltaH = WindowRect.Height() - ClientRect.Height();
	MoveWindow(hWnd, WindowRect.left, WindowRect.top, iWheight + deltaW, iHeight + deltaH, true);
}
