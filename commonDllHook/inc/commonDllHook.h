#pragma once

#include <windows.h>

#define    FAKE_DLL_NAME    L"WeChatWin.dll"
#define    ORIGINAL_DLL_NAME    L"WeChatWin.dll.orig"

void callhook(HMODULE hMod, LPCWSTR fakedll, LPWSTR realdll);
void Patch(PVOID addr, PVOID code, DWORD size);
