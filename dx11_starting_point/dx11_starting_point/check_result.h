#pragma once
#include <Windows.h>
#include <comdef.h>
#include <string>

HRESULT check_result(HRESULT hr);

template <class T>
T check_that_result_is(T result, T successful_result) {
	if (result != successful_result) {
		MessageBoxA(nullptr, "Wrong result", "Error", MB_ICONERROR);
	}
	return result;
}


template <class T>
T check_that_result_isnt(T result, T unsuccessful_result) {
	if (result == unsuccessful_result) {
		MessageBoxA(nullptr, "Wrong result", "Error", MB_ICONERROR);
	}
	return result;
} 