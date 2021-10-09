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
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//�������
}

void MouseCtrl::LeftMouseButtonUp()
{
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//�ɿ����
}

void MouseCtrl::LeftMouseButtonPress()
{
	LeftMouseButtonDown();
	Sleep(10);
	LeftMouseButtonUp();
}

void MouseCtrl::RightMouseButtonDown()
{
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);//�����Ҽ�
}

void MouseCtrl::RightMouseButtonUp()
{
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);//�ɿ��Ҽ�
}

void MouseCtrl::RightMouseButtonPress()
{
	RightMouseButtonDown();
	Sleep(50);
	RightMouseButtonUp();
}

void MouseCtrl::MidMouseButtonDown()
{
	mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0);//�����м�
}

void MouseCtrl::MidMouseButtonUp()
{
	mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);//�ɿ��м�
}

void MouseCtrl::MidMouseButtonPress()
{
	MidMouseButtonDown();
	Sleep(50);
	MidMouseButtonUp();
}

void MouseCtrl::MouseMoveTo(int x, int y)
{
	SetCursorPos(x, y);//�ƶ���ָ��λ��
}

POINT MouseCtrl::MouseLocation()
{
	POINT p;
	GetCursorPos(&p);
	return p;
}
