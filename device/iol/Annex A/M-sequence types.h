#include <cstdint>

namespace M_sequence_types {
	const uint8_t M_sequence_code_min = 0;
	const uint8_t M_sequence_code_max = 7;

	const uint8_t On_request_Data_Octets_min = 1;
	const uint8_t On_request_Data_Octets_max = 2;

	const uint8_t PDin_min = 0;
	const uint8_t PDin_max = 32;

	const uint8_t PDout_min = 0;
	const uint8_t PDout_max = 32;

	

	enum class PD_representation_type {
		bit,
		octets,
		_cnt //use only for tests
	};

	enum class M_sequence_type {
		TYPE_0,
		TYPE_1_2,
		TYPE_1_1__1_2,
		TYPE_2_1,
		TYPE_2_2,
		TYPE_2_3,
		TYPE_2_4,
		TYPE_2_5,
		_cnt //use only for tests
	};

	typedef struct {
		uint8_t M_sequence_code;
		uint8_t On_request_Data_Octets;
		uint8_t PDin;
		uint8_t PDout;
		PD_representation_type PD_representation;
		M_sequence_type expected_M_sequence_type;
	} OPERATE_M_sequence_type_valid__parameters;

	bool OPERATE_M_sequence_type_valid(OPERATE_M_sequence_type_valid__parameters *parameters);
}
