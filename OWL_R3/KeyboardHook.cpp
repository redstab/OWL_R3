#include "KeyboardHook.h"
#include <iostream>
#include <Windows.h>
#include <UIAutomation.h>
#include <bitset>


KeyboardHook::KeyboardHook() :
	WinHook(HookType::KeyboardLowLevel, std::bind_front(&KeyboardHook::ParseKeyPress, this))
{
    //CoInitialize(nullptr);
    //HRESULT hr =
    //    CoCreateInstance(__uuidof(CUIAutomation),
    //        NULL, CLSCTX_INPROC_SERVER,
    //        __uuidof(IUIAutomation),
    //        (void**)&g_pAutomation);

}

KeyboardHook::~KeyboardHook()
{
    //CoUninitialize();
}

void KeyboardHook::ParseKeyPress(int code, LPARAM lparam, WPARAM wparam)
{
    LPKBDLLHOOKSTRUCT hook_struct = (LPKBDLLHOOKSTRUCT)wparam;

    //std::cout << "[EVENT] Keyboard: " 
    //    << "vkCode: " << hook_struct->vkCode 
    //    << ", scanCode: " << hook_struct->scanCode 
    //    << ", flags: " << std::bitset<8>(hook_struct->flags) 
    //    << ", Key: " << magic_enum::enum_name((vKey)hook_struct->vkCode)
    //    << ", Key_info: " << std::bitset<25>(key_information)
    //    << ", State: " << (bool(LLKHF_UP & hook_struct->flags) ? "UP" : "DOWN")
    //    << ", Key_info: " << key_name << std::endl;

    KeyEvent ev(*hook_struct);
    
    std::cout << ev.toString() << std::endl;


    /*CoInitialize(NULL);*/
    

    //CoUninitialize();
   /* HRESULT hr = g_pAutomation->GetFocusedElement(&pFocusedElement);

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

    pFocusedElement->Release();

    pFocusedElement = nullptr;*/


    //CONTROLTYPEID pControlType{};

    //hr = pFocusedElement->get_CurrentControlType(&pControlType);

    //if (FAILED(hr)) {
    //    std::cout << "get_CurrentControlType" << std::endl;
    //}
    //
    //VARIANT IsTextPatternAvailable{};
    //VARIANT IsValuePatternAvailable{};

    //hr = pFocusedElement->GetCurrentPropertyValue(UIA_IsTextPatternAvailablePropertyId, &IsTextPatternAvailable);
    //if (FAILED(hr))
    //{
    //    std::cout << "GetCurrentPropertyValue_text" << std::endl;
    //}
    //hr = pFocusedElement->GetCurrentPropertyValue(UIA_IsValuePatternAvailablePropertyId, &IsValuePatternAvailable);
    //if (FAILED(hr))
    //{
    //    std::cout << "GetCurrentPropertyValue_value" << std::endl;
    //}
    //BSTR str;
    //pFocusedElement->get_CurrentLocalizedControlType(&str);
    //std::wcout << "LocalizedControlType: " << str << std::endl;
    //SysFreeString(str);    
    //
    //BSTR str1;
    //pFocusedElement->get_CurrentClassName(&str1);
    //std::wcout << "ClassName: " << str1 << std::endl;
    //SysFreeString(str1);   
    //
    //int proc;
    //pFocusedElement->get_CurrentProcessId(&proc);
    //std::wcout << "ProcessId: " << proc << std::endl;

    //BOOL pass;
    //pFocusedElement->get_CurrentIsPassword(&pass);
    //std::wcout << "Password: " << pass << std::endl;

    //std::cout << "Type: " << pControlType << std::endl;
    //std::cout << "IsTextPatternAvailable: " << (IsTextPatternAvailable.boolVal == -1) << std::endl;
    //std::cout << "IsValuePatternAvailable: " << (IsValuePatternAvailable.boolVal == -1) << std::endl;

    //IUIAutomationTextPattern* pTextProvider{};

    //hr = pFocusedElement->GetCurrentPattern(UIA_TextPatternId/*UIA_ValuePatternId*/, reinterpret_cast<IUnknown**>(&pTextProvider));

    //if (FAILED(hr)) 
    //{
    //    std::cout << "GetCurrentPattern" << std::endl;
    //}
    //std::cout << "TextProvider: " << pTextProvider << " HR: " << hr << std::endl;

    //SupportedTextSelection sTextSelectionMode;

    //hr = pTextProvider->get_SupportedTextSelection(&sTextSelectionMode);

    //if (FAILED(hr)) {
    //    std::cout << "get_SupportedTextSelection" << std::endl;
    //}

    //if (sTextSelectionMode != SupportedTextSelection_None) {
    //    std::cout << "Element Supports selection" << std::endl;
    //    //IUIAutomationTextRangeArray ar;
    //    IUIAutomationTextRangeArray* arr;

    //    hr = pTextProvider->GetSelection(&arr);
    //    //ar.
    //    
    //    //hr = pTextProvider->GetSelection(&ar);

    //    if (FAILED(hr)) {
    //        std::cout << "GetSelection" << std::endl;
    //    }

    //    int length{ 0 };
    //    arr->get_Length(&length);

    //    std::cout << "Selection-Size: " << length << std::endl;

    //    for (int i = 0; i < length; i++)
    //    {
    //        IUIAutomationTextRange* range;
    //        arr->GetElement(i, &range);

    //        BSTR text;

    //        range->GetText(-1, &text);

    //        std::wcout << "Element: " << text << std::endl;

    //        SysFreeString(text);
    //        range->Release();
    //    }

    //    arr->Release();
    //}

    //pTextProvider->Release();
    //pFocusedElement->Release();
    //g_pAutomation->Release();
    ///*wchar_t* text{};
    //hr = pValueProvider->get_Value(&text);
    //if (FAILED(hr))
    //{
    //    std::cout << "get_Value" << std::endl;
    //}

    //std::wcout << "Text: " << text << std::endl;

    //SysFreeString(text);*/
    //std::cout << "Freeing stuff!" << std::endl;
//Sleep(5999);
}
