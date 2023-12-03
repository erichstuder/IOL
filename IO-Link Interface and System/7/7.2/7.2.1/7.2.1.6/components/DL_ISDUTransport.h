#pragma once

#include "OctetStringT.h"

namespace DL_ISDUTransport {
	enum class Direction_type {
		READ,
		WRITE,
		_cnt
	};

	struct Argument_type {
		uint16_t Index;
		uint8_t Subindex;
		OctetStringT* Data;
		Direction_type Direction;
	};

	enum class ISDUTransportErrorInfo_type {
		SUCCESS,
		NO_COMM,
		STATE_CONFLICT,
		ISDU_TIMEOUT,
		ISDU_NOT_SUPPORTED,
		VALUE_OUT_OF_RANGE,
		_cnt
	};

	struct Result_type {
		OctetStringT* Data;
		int Qualifier; //TODO: dont know the datatype yet
		ISDUTransportErrorInfo_type ISDUTransportErrorInfo;

		Result_type(uint8_t Data_length):
			Data(new OctetStringT(Data_length))
		{}
	};
}
