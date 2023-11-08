#pragma once

#include "OctetStringT.h"

class OD {
	public:
		enum class RWDirection_type {
			READ,
			WRITE,
			_cnt
		};

		enum class ComChannel_type {
			DIAGNOSIS,
			PAGE,
			ISDU,
			_cnt
		};

		enum class AddressCtrl_type {
			_0, _1, _2, _3, _4, _5, _6, _7, _8, _9,
			_10, _11, _12, _13, _14, _15, _16, _17, _18, _19,
			_20, _21, _22, _23, _24, _25, _26, _27, _28, _29,
			_30, _31,
			_cnt
		};

		enum class Length_type {
			_0, _1, _2, _3, _4, _5, _6, _7, _8, _9,
			_10, _11, _12, _13, _14, _15, _16, _17, _18, _19,
			_20, _21, _22, _23, _24, _25, _26, _27, _28, _29,
			_30, _31, _32,
			_cnt
		};

		struct Result_type {
			enum class ErrorInfo_type {
				SUCCESS,
				NO_COMM,
				STATE_CONFLICT,
				_cnt
			};

			ErrorInfo_type ErrorInfo;
			OctetStringT* Data;
			//Length_type Length; see Data

			Result_type(uint8_t data_length) : Data(new OctetStringT(data_length)) { }
		};

		struct Argument_type {
			RWDirection_type RWDirection;
			ComChannel_type ComChannel;
			AddressCtrl_type AddressCtrl;
			Length_type Length;
			OctetStringT* Data;
		};

		void req(Argument_type Argument);
		void ind(Argument_type Argument);
		Result_type rsp();
		Result_type cnf();
};
