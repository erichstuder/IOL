#pragma once
#include <cstdint>

//namespace SM_SetDeviceCom {
	enum class SupportedSIOMode {
		INACTIVE,
		DI,
		DO,
		_cnt
	};

	enum class SupportedTransmissionrate {
		COM1,
		COM2,
		COM3,
		_cnt
	};

	enum class M_sequence_Capability {
		ISDU,
		OPERATE,
		PREOPERATE,	
		_cnt
	};
//}
