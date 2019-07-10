#pragma once
#include <assert.h>
#include "user_settings.h"
#include "check_result.h"

template <class callback_t>
Window::Window(HINSTANCE hInst, int nCmdShow, const wchar_t* windowClassName, callback_t callback) {
	// Register a window class for creating our render window with.
	WNDCLASSEXW windowClass = {};

	windowClass.cbSize = sizeof(WNDCLASSEXW);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = callback;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInst;
	windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	windowClass.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = windowClassName;

	static ATOM atom = check_that_result_isnt<ATOM>(::RegisterClassExW(&windowClass), 0);
	
	// Creating window
	int screenWidth = ::GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = ::GetSystemMetrics(SM_CYSCREEN);

	RECT windowRect = { 0, 0, user_settings::width, user_settings::height };
	::AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	m_hwnd = check_that_result_isnt<HWND>(::CreateWindowExW(
		WS_EX_APPWINDOW,
		windowClassName,
		L"", // no title
		WS_POPUP,
		CW_USEDEFAULT, CW_USEDEFAULT,
		windowRect.right - windowRect.left, // width
		windowRect.bottom - windowRect.top, // height
		NULL,
		NULL,
		hInst,
		nullptr
	), nullptr);

	assert(m_hwnd && "Failed to create window");
	
	m_renderer.reset(Renderer::createRenderer(m_hwnd));

	ShowWindow(m_hwnd, nCmdShow);
}
