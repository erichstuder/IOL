#pragma once

#include <cstdint>

class PL_Transfer_req__Interface {
	public:
		virtual void PL_Transfer_req(uint8_t Data) = 0;
};
