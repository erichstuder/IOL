#pragma once

#include "OctetStringT.h"

namespace PD {
	enum class PDInLength_type {
		_0, _1, _2, _3, _4, _5, _6, _7, _8, _9,
		_10, _11, _12, _13, _14, _15, _16, _17, _18, _19,
		_20, _21, _22, _23, _24, _25, _26, _27, _28, _29,
		_30, _31, _32,
		_cnt
	};
	enum class PDOutLength_type {
		_0, _1, _2, _3, _4, _5, _6, _7, _8, _9,
		_10, _11, _12, _13, _14, _15, _16, _17, _18, _19,
		_20, _21, _22, _23, _24, _25, _26, _27, _28, _29,
		_30, _31, _32,
		_cnt
	};

	

	struct Argument_type {
		uint8_t PDInAddress = 0; //TODO: size is not yet clear
		PDInLength_type PDInLength;
		OctetStringT* PDout;
		uint8_t PDOutAddress = 0; //TODO: size is not yet clear
		PDOutLength_type PDOutLength;
	};

	struct Result_type {
		enum class ErrorInfo_type {
			SUCCESS,
			NO_COMM,
			STATE_CONFLICT,
			_cnt
		};

		ErrorInfo_type ErrorInfo;
		OctetStringT* PDIn;

		Result_type(uint8_t PDIn_length) : PDIn(new OctetStringT(PDIn_length)) { }
	};
}
