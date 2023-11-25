#pragma once

namespace MHInfo {
	enum class MHInfo_type {
		COMLOST,
		ILLEGAL_MESSAGETYPE,
		CHECKSUM_MISMATCH,
		_cnt
	};

	struct Argument_type {
		MHInfo_type MHInfo;
	};
}

class MHInfo_ind__Interface {
	public:
		virtual void MHInfo_ind(MHInfo::Argument_type Argument) = 0;
};
