#include <iostream>

#include "WinHook.h"
#include "KeyboardHook.h"

int main()
{

	KeyboardHook kb_hook;

	//WinHook kb_hook(HookType::KeyboardLowLevel, [](int code, LPARAM l, WPARAM w) {
	//	std::cout << "[EVENT] KeyPress: " << code << " - " << l << " - " << w << std::endl;
	//	});

	while (true) {
		Sleep(10);
	}

}