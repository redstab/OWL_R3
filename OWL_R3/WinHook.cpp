#include "WinHook.h"
#include <iostream>

std::unordered_map<HookType, std::function<void(int, LPARAM, WPARAM)>> WinHook::_callback_store;

WinHook::WinHook(HookType hook_type, HookFunc callback)
{
	_hook_type = hook_type;
	_callback = callback;

	if (_callback_store.contains(_hook_type)) {
		throw std::invalid_argument("a hook of this type is already installed");
	}

	_callback_store[_hook_type] = _callback;

	_thread_running = true;
	_message_loop_thread = std::thread(&WinHook::HookLoop, this);
}

WinHook::~WinHook()
{
	_thread_running = false;
	_message_loop_thread.join();
	UnhookWindowsHookEx(_hook_handle);
}

template<HookType hook_type>
static LRESULT WinHook::HookCallback(int code, LPARAM lparam, WPARAM wparam)
{
	const auto& callback = _callback_store[hook_type];

	std::cout << "Hello";

	callback(code,lparam,wparam);

	return CallNextHookEx(NULL, code, lparam, wparam);
}


#define InstallHookIf(hook_type) \
	case hook_type: \
	{\
	_hook_handle = SetWindowsHookEx((int)hook_type, (HOOKPROC)HookCallback<hook_type>, 0, 0); \
	break;\
	}

void WinHook::InstallHook()
{
	switch (_hook_type) {
		InstallHookIf(HookType::KeyboardLowLevel);
	}
}

void WinHook::HookLoop()
{
	InstallHook();

	MSG msg{};

	while (_thread_running) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(1);
	}
}