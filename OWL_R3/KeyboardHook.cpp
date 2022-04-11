#include "KeyboardHook.h"
#include <iostream>
#include <Windows.h>
#include <UIAutomation.h>


KeyboardHook::KeyboardHook() :
	WinHook(HookType::KeyboardLowLevel, std::bind_front(&KeyboardHook::ParseKeyPress, this))
{

}

void KeyboardHook::ParseKeyPress(int, LPARAM, WPARAM)
{
    CoInitialize(NULL);
    IUIAutomation* g_pAutomation;
    HRESULT hr =
        CoCreateInstance(__uuidof(CUIAutomation),
            NULL, CLSCTX_INPROC_SERVER,
            __uuidof(IUIAutomation),
            (void**)&g_pAutomation);

    IUIAutomationElement* pFocusedElement;

    hr = g_pAutomation->GetFocusedElement(&pFocusedElement);

    if (FAILED(hr)) 
    {
        std::cout << "GetFocusedElement falied" << std::endl;
    }

    BOOL hasFocus{0};

    hr = pFocusedElement->get_CurrentHasKeyboardFocus(&hasFocus);

    if (FAILED(hr)) 
    {
        std::cout << "get_CurrentHasKeyboardFocus" << std::endl;
    }
    std::cout << "Element has keyboard focus" << std::endl;

    IValueProvider* pValueProvider;

    hr = pFocusedElement->GetCurrentPattern(UIA_ValuePatternId, reinterpret_cast<IUnknown**>(&pValueProvider));

    if (FAILED(hr)) 
    {
        std::cout << "GetCurrentPattern" << std::endl;
    }

    BSTR text{};
    hr = pValueProvider->get_Value(&text);
    if (FAILED(hr))
    {
        std::cout << "get_Value" << std::endl;
    }

    std::wcout << "Text: " << text << std::endl;

    SysFreeString(text);

    CoUninitialize();
}
