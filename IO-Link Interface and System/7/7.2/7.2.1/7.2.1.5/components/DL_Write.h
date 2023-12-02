#pragma once

#include <cstdint>

namespace DL_Write {
	enum class ErrorInfo_type {
		SUCCESS,
		NO_COMM,
		STATE_CONFLICT,
		_cnt
	};

	struct Argument_type {
		uint8_t Address;
		uint8_t Value; //TBD: don't know the data type yet
	};

	struct Result_type {
		ErrorInfo_type ErrorInfo;
	};
}