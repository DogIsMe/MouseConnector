#pragma once
#include <initializer_list>

class KeyCtrl
{
public:
	explicit KeyCtrl();
	virtual ~KeyCtrl();

	void KeyDown(const int);
	void KeyUp(const int);
	void KeyPress(const int);
	void KeyComb(const std::initializer_list<int>);

};

