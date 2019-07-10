#pragma once
#define NOMINMAX
#include <windows.h>
#include <memory>

#include "Renderer.h"

class Window
{
public:
	template <class callback_t>
	Window(HINSTANCE hInst, int nCmdShow, const wchar_t* windowClassName, callback_t);

	Window(HINSTANCE hInst, int nCmdShow, const wchar_t* windowClassName) : Window(hInst, nCmdShow, windowClassName, DefWindowProc){};

private:
	std::unique_ptr<Renderer> m_renderer;
	HWND					  m_hwnd;
};

#include "Window.hpp"