#pragma once

namespace PDInStatus {
	enum class Status_type {
		VALID,
		INVALID,
		_cnt
	};

	struct Argument_type {
		Status_type Status;
	};
}
