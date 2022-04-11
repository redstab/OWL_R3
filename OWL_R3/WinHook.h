#pragma once
#include <Windows.h>
#include <unordered_map>
#include <thread>
#include <functional>

enum class HookType {
	KeyboardLowLevel = WH_KEYBOARD_LL,
};

using HookFunc = std::function<void(int, LPARAM, WPARAM)>;

class WinHook
{
public:

	WinHook(HookType hook_type, HookFunc callback);

	~WinHook();
private:

	static std::unordered_map<HookType, HookFunc> _callback_store;
	template<HookType>
	static LRESULT HookCallback(int, LPARAM, WPARAM);

	HHOOK _hook_handle;

	bool _thread_running;
	std::thread _message_loop_thread;


	HookType _hook_type;
	HookFunc _callback;
	
	void InstallHook();

	void HookLoop();
};
