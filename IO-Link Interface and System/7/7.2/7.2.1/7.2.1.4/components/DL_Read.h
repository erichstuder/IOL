#pragma once

#include <cstdint>

namespace DL_Read {
	enum class ErrorInfo_type {
		SUCCESS,
		NO_COMM,
		STATE_CONFLICT,
		_cnt
	};

	struct Argument_type {
		uint8_t Address;
	};

	struct Result_type {
		uint8_t Value; //TBD: don't know yet what the data type will be
		ErrorInfo_type ErrorInfo;
	};
}