#pragma once

#include "cstdint"

namespace DL_WriteParam {
	struct Argument_type {
		uint8_t Address;
	};

	enum class ErrorInfo_type {
		SUCCESS,
		NO_COMM,
		STATE_CONFLICT,
		_cnt
	};

	struct Result_type {
		ErrorInfo_type ErrorInfo;
	};
}
