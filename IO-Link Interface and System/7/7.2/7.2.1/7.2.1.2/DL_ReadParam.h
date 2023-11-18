#pragma once

//#include "OctetStringT.h"

class DL_ReadParam {
	public:
		enum class ErrorInfo_type {
			NO_COMM,
			STATE_CONFLICT,
			_cnt
		};

		typedef int Value_type; //don't know the type yet, so I just set int

		struct Result_type {
			Value_type Value;
			ErrorInfo_type ErrorInfo;
		};

		virtual void DL_ReadParam_req(uint8_t Address) = 0;
		virtual Result_type DL_ReadParam_cnf() = 0;
		virtual void DL_ReadParam_ind(uint8_t Address) = 0;
		virtual Value_type DL_ReadParam_rsp() = 0;
};
