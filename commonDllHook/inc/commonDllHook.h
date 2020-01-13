#pragma once

#include <windows.h>

/*
dllname:		被劫持dll的原始名字
OrigDllPath:	被劫持dll改名后的完整路径
*/
void commonDllHook(LPCWSTR dllname, LPWSTR OrigDllPath);

void callhook(HMODULE hMod, LPCWSTR fakedll, LPWSTR realdll);
void Patch(PVOID addr, PVOID code, DWORD size);
