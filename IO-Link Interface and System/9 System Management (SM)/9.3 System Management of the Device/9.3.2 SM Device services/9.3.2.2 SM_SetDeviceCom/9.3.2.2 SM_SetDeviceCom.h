#pragma once
#include <cstdint>

//namespace SM_SetDeviceCom {
	enum class SupportedSIOMode_type {
		INACTIVE,
		DI,
		DO,
		_cnt
	};

	enum class SupportedTransmissionrate_type {
		COM1,
		COM2,
		COM3,
		_cnt
	};

	enum class M_sequence_Capability_type {
		ISDU,
		OPERATE,
		PREOPERATE,	
		_cnt
	};

	enum class Result_type {
		SUCCESS,
		PARAMETER_CONFLICT,
		_cnt
	};

	typedef struct {
		SupportedSIOMode_type SupportedSIOMode;
		SupportedTransmissionrate_type SupportedTransmissionrate;
		float MinCycleTime;
		M_sequence_Capability_type M_sequence_Capability;
		uint8_t RevisionID;
		uint8_t ProcessDataIn;
		uint8_t ProcessDataOut;
	} SM_SetDeviceCom__parameters;

	Result_type SM_SetDeviceCom(SM_SetDeviceCom__parameters parameters);
//}
