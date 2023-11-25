#pragma once

#include <cstdint>

namespace PDTrig {
	struct Argument_type {
		uint8_t DataLength;
	};
}

class PDTrig_ind__Interface {
	public:
		virtual void PDTrig_ind(PDTrig::Argument_type Argument) = 0;
};
