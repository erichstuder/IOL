#pragma once

#include <cstdint>

namespace M_sequence_control {
	enum class Communication_channel {
		Process,
		Page,
		Diagnosis,
		ISDU,
		_cnt
	};
}
