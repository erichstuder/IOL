#pragma once

#include "OctetStringT.h"

class AL_Read {
	public:
		struct Result_type {
			enum class ErrorInfo_type {
				// TODO: verwende Annex C statt dieser enum class
				_cnt
			};

			ErrorInfo_type ErrorInfo;
			unsigned int Port;
			OctetStringT* Data;

			Result_type(uint8_t data_length) : Data(new OctetStringT(data_length)) { }
		};

		void req(uint8_t Port, uint16_t Index, uint8_t Subindex);
		void ind(uint16_t Index, uint8_t Subindex);
		Result_type rsp();
		Result_type cnf();
};
