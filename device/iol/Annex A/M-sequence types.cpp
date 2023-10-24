#include "M-sequence types.h"

namespace M_sequence_types {
	//TODO: make deprecated?
	bool OPERATE_M_sequence_type_valid(OPERATE_M_sequence_type_valid__parameters *parameters) {
		/*parameters->M_sequence_code = 0 ;
		parameters->On_request_Data_Octets = 1 ;
		parameters->PDin = 0 ;
		parameters->PDout = 0 ;
		parameters->expected_M_sequence_type ==M_sequence_type::TYPE_0;*/

		bool line_1 =
			parameters->M_sequence_code == 0 &&
			parameters->On_request_Data_Octets == 1 &&
			parameters->PDin == 0 &&
			parameters->PDout == 0 &&
			parameters->expected_M_sequence_type == M_sequence_type::TYPE_0;

		bool line_2 =
			parameters->M_sequence_code == 1 &&
			parameters->On_request_Data_Octets == 2 &&
			parameters->PDin == 0 &&
			parameters->PDout == 0 &&
			parameters->expected_M_sequence_type == M_sequence_type::TYPE_1_2;

		bool line_3 = 
			parameters->On_request_Data_Octets == 2 &&
			parameters->PDin >= 3 &&
			parameters->PDin <= 32 &&
			parameters->PDout >= 0 &&
			parameters->PDout <= 32 &&
			parameters->PD_representation == PD_representation_type::octets;
			parameters->expected_M_sequence_type == M_sequence_type::TYPE_1_1__1_2;

		bool line_4 = 
			parameters->On_request_Data_Octets == 2 &&
			parameters->PDin >= 0 &&
			parameters->PDin <= 32 &&
			parameters->PDout >= 3 &&
			parameters->PDout <= 32 &&
			parameters->PD_representation == PD_representation_type::octets;
			parameters->expected_M_sequence_type == M_sequence_type::TYPE_1_1__1_2;

		bool line_5 = 
			parameters->On_request_Data_Octets == 1 &&
			parameters->PDin >= 1 &&
			parameters->PDin <= 8 &&
			parameters->PDout == 0 &&
			parameters->PD_representation == PD_representation_type::bit;
			parameters->expected_M_sequence_type == M_sequence_type::TYPE_2_1;

		bool line_6 = 
			parameters->On_request_Data_Octets == 1 &&
			parameters->PDin >= 9 &&
			parameters->PDin <= 16 &&
			parameters->PDout == 0 &&
			parameters->PD_representation == PD_representation_type::bit;
			parameters->expected_M_sequence_type == M_sequence_type::TYPE_2_2;

		bool line_7 = 
			parameters->On_request_Data_Octets == 1 &&
			parameters->PDin == 0 &&
			parameters->PDout >= 1 &&
			parameters->PDout <= 8 &&
			parameters->PD_representation == PD_representation_type::bit;
			parameters->expected_M_sequence_type == M_sequence_type::TYPE_2_3;

		bool line_8 = 
			parameters->On_request_Data_Octets == 1 &&
			parameters->PDin == 0 &&
			parameters->PDout >= 9 &&
			parameters->PDout <= 16 &&
			parameters->PD_representation == PD_representation_type::bit;
			parameters->expected_M_sequence_type == M_sequence_type::TYPE_2_4;

		bool line_9 = 
			parameters->On_request_Data_Octets == 1 &&
			parameters->PDin >= 1 &&
			parameters->PDin <= 8 &&
			parameters->PDout >= 1 &&
			parameters->PDout <= 8 &&
			parameters->PD_representation == PD_representation_type::bit;
			parameters->expected_M_sequence_type == M_sequence_type::TYPE_2_5;

		if(line_1 || line_2 || line_3 || line_4 || line_5 || line_6 || line_7 || line_8 || line_9) {
			return true;
		}
		return false;
	}
}
