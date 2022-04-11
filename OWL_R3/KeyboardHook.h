#pragma once
#include "WinHook.h"
#include <iostream>

class KeyboardHook :
	public WinHook
{
public:
	KeyboardHook();

	~KeyboardHook() {}
private:
	void ParseKeyPress(int, LPARAM, WPARAM);
};

