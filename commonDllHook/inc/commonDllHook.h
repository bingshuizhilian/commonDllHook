#pragma once

#include <windows.h>

/*
dllname:		���ٳ�dll��ԭʼ����
OrigDllPath:	���ٳ�dll�����������·��
*/
void commonDllHook(LPCWSTR dllname, LPWSTR OrigDllPath);

void callhook(HMODULE hMod, LPCWSTR fakedll, LPWSTR realdll);
void Patch(PVOID addr, PVOID code, DWORD size);
