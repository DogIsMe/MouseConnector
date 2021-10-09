#include "KeyCtrl.h"
#include <windows.h>

KeyCtrl::KeyCtrl()
{
}

KeyCtrl::~KeyCtrl()
{
}

void KeyCtrl::KeyDown(const int c)
{
	keybd_event(c, 0, 0, 0);
}

void KeyCtrl::KeyUp(const int c)
{
	keybd_event(c, 0, KEYEVENTF_KEYUP, 0);
}

void KeyCtrl::KeyPress(const int c)
{
	KeyDown(c);
	KeyUp(c);
}

void KeyCtrl::KeyComb(const std::initializer_list<int> l)
{
	if (l.size() == 0)
	{
		return;
	}

	for (auto& one : l)
	{
		KeyDown(one);
	}
	for (auto& one : l)
	{
		KeyUp(one);
	}
}
