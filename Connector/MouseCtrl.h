#pragma once
#include <Windows.h>
#include <tuple>
class MouseCtrl
{
public:
	explicit MouseCtrl();
	virtual ~MouseCtrl();

	void LeftMouseButtonDown();
	void LeftMouseButtonUp();
	void LeftMouseButtonPress();

	void RightMouseButtonDown();
	void RightMouseButtonUp();
	void RightMouseButtonPress();

	void MidMouseButtonDown();
	void MidMouseButtonUp();
	void MidMouseButtonPress();

	void MouseMoveTo(int,int);
	POINT MouseLocation();
};

