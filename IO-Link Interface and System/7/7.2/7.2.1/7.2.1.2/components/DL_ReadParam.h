#pragma once

#include "cstdint"

namespace DL_ReadParam {
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
		int Value; //TODO: don't know the type yet
		ErrorInfo_type ErrorInfo;
	};
}
