// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "commonDllHook.h"
#include <iostream>


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	HMODULE hm = hModule;
	//33 C0                xor eax,eax ; 90    nop
	BYTE code[] = { 0x33, 0xc0, 0x90 };
	//DWORD offset = 0x263061; // 0xC00 + 0x262461;
	DWORD offset = 0x28B171; // 0xC00 + 0x28A571;  wx ver: 2.8.0.111

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		std::cout << "hModule fake: " << hModule << std::endl;

		callhook(hModule, FAKE_DLL_NAME, ORIGINAL_DLL_NAME);

		hm = GetModuleHandle(ORIGINAL_DLL_NAME);

		std::cout << "hModule WeChatWin.dll: " << GetModuleHandle(FAKE_DLL_NAME) << std::endl;

		std::cout << "hModule WeChatWin.dll.orig: " << GetModuleHandle(ORIGINAL_DLL_NAME) << std::endl;

		std::wcout << std::hex << *((BYTE*)hm + offset) << " - " << *((BYTE*)hm + offset + 1) << " - " << *((BYTE*)hm + offset + 2) << std::endl;

		Patch(PVOID((BYTE*)hm + offset), code, 3);

		std::wcout << std::hex << *((BYTE*)hm + offset) << " - " << *((BYTE*)hm + offset + 1) << " - " << *((BYTE*)hm + offset + 2) << std::endl;

		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
