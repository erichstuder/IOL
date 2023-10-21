namespace M_sequence_types {
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
		M_sequence_type expected_type;
	} M_sequence_type_valid__parameters;

	bool M_sequence_type_valid(M_sequence_type_valid__parameters *parameters);
}
