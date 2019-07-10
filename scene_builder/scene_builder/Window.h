#pragma once
#include "Renderer.h"

class Window {
public:
	Window(int width, int height);

private:
	HWND m_handle;
	Renderer m_renderer;
};