#pragma once

#include "OctetStringT.h"

class DL_ISDUTransport {
	public:
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

		struct Result_type {
			//OctetStringT* Data;
		};

		void req(Argument_type argument);
		void ind(Argument_type argument);
		Result_type cnf(void);
		Result_type rsp(void);
};
