#include <Windows.h>
#include "Window.h"
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "DirectXTK.lib")

LRESULT CALLBACK callback(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return ::DefWindowProcW(hwnd, message, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow){
	// create window and show 
	Window w(hInstance, nCmdShow, L"dx11_starting_point", callback);

	//handle messages
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(10);
	}
}