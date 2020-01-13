#include <iostream>
#include <windows.h>

int main(int argc, char* argv[])
{
	HMODULE hm = LoadLibrary(L"WeChatWin.dll");

	if (!hm)
		printf("hm error: %d\n", GetLastError());
	else
		printf("hm : 0x%x\n", hm);

	getchar();
	return 0;
}