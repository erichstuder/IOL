#pragma once

#include <cstdint>

namespace PL_Transfer {
	enum class Status {
		SUCCESS,
		PARITY_ERROR,
		FRAMING_ERROR,
		OVERRUN,
		_cnt
	};
}

class PL_Transfer_ind__Interface {
	public:
		virtual PL_Transfer::Status PL_Transfer_ind(uint8_t Data) = 0;
};
