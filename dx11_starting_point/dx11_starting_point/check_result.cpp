#include "check_result.h"

HRESULT check_result(HRESULT hr){
	if (FAILED(hr)) {
		_com_error error(hr);
		MessageBoxA(NULL, error.ErrorMessage(), "Error", MB_ICONERROR);
	}
	return hr;
}