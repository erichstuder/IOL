#pragma once

#include <cstdint>

namespace ODTrig {
	struct Argument_type {
		uint8_t DataLength;
	};
}

class ODTrig_ind__Interface {
	public:
		virtual void ODTrig_ind(ODTrig::Argument_type Argument) = 0;
};
