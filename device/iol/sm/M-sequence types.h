#include <cstdint>

namespace M_sequence_types {
	const uint8_t M_sequence_code_min = 0;
	const uint8_t M_sequence_code_max = 7;

	enum class PD_representation_type { //TODO: das muss wohl an eine andere Stelle
		bit,
		octets
	};

	enum class M_sequence_type {
		TYPE_0,
		TYPE_1_2,
		TYPE_1_1__1_2,
		TYPE_2_1,
		TYPE_2_2,
		TYPE_2_3,
		TYPE_2_4,
		TYPE_2_5
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
