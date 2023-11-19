#pragma once

#include <cstdint>

class PL_Transfer {
	public:
		enum class Status {
			SUCCESS,
			PARITY_ERROR,
			FRAMING_ERROR,
			OVERRUN,
			_cnt
		};

		virtual void PL_Transfer_req(uint8_t Data) = 0;
		virtual Status PL_Transfer_ind(uint8_t Data) = 0;
};
