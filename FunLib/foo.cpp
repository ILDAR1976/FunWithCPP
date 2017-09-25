

#include "stdafx.h"

#include <iostream>


namespace myCode {

	void sayHello()
	{
		using namespace std;
		cout << "Hello, world!" << endl;
	}

}    // namespace myCode

#undef UNICODE
#define UNICODE
#include <windows.h>

extern "C"
__declspec(dllexport)
void CALLBACK sayHello(HWND, HINSTANCE, wchar_t const*, int)
{
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	DWORD const infoBoxOptions = MB_ICONINFORMATION | MB_SETFOREGROUND;
	MessageBox(0, L"Before call...", L"DLL message:", infoBoxOptions);
	myCode::sayHello();
	MessageBox(0, L"After call...", L"DLL message:", infoBoxOptions);
}

extern "C"
__declspec(dllexport)
void CALLBACK Print(HWND, HINSTANCE, wchar_t const*, int)
{

	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	DWORD const infoBoxOptions = MB_ICONINFORMATION | MB_SETFOREGROUND;
	MessageBox(0, L"Hello, world!", L"DLL message:", infoBoxOptions);
	
}
