#include "MouseCtrl.h"

#include <conio.h>
#include <cstdlib>

MouseCtrl::MouseCtrl()
{

}

MouseCtrl::~MouseCtrl()
{
}

void MouseCtrl::LeftMouseButtonDown()
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//按下左键
}

void MouseCtrl::LeftMouseButtonUp()
{
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//松开左键
}

void MouseCtrl::LeftMouseButtonPress()
{
	LeftMouseButtonDown();
	Sleep(10);
	LeftMouseButtonUp();
}

void MouseCtrl::RightMouseButtonDown()
{
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);//按下右键
}

void MouseCtrl::RightMouseButtonUp()
{
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);//松开右键
}

void MouseCtrl::RightMouseButtonPress()
{
	RightMouseButtonDown();
	Sleep(50);
	RightMouseButtonUp();
}

void MouseCtrl::MidMouseButtonDown()
{
	mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0);//按下中键
}

void MouseCtrl::MidMouseButtonUp()
{
	mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);//松开中键
}

void MouseCtrl::MidMouseButtonPress()
{
	MidMouseButtonDown();
	Sleep(50);
	MidMouseButtonUp();
}

void MouseCtrl::MouseMoveTo(int x, int y)
{
	SetCursorPos(x, y);//移动到指定位置
}

POINT MouseCtrl::MouseLocation()
{
	POINT p;
	GetCursorPos(&p);
	return p;
}
