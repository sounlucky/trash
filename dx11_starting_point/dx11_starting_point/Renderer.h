#pragma once
#include <d3d11_1.h>
#include <utility>
#include <wrl.h>
class Renderer
{
public:
	static Renderer* createRenderer(HWND);

private:
	Renderer() = default;

};
