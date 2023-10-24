#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp> //TODO: what is this good for?

#include "M-sequence types.h"
#include <regex>
#include <boost/range/irange.hpp>

using std::string;

static struct {
	uint8_t OPERATE_M_sequence_code_min;
	uint8_t OPERATE_M_sequence_code_max;
	uint8_t On_request_Data_Octets;
	uint8_t PDin_min;
	uint8_t PDin_max;
	uint8_t PDout_min;
	uint8_t PDout_max;
	M_sequence_types::PD_representation_type PD_representation;
	M_sequence_types::M_sequence_type expected_M_sequence_type;
} context;


GIVEN("^OPERATE M-sequence code: (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "0") {
		context.OPERATE_M_sequence_code_min = 0;
		context.OPERATE_M_sequence_code_max = 0;
	}
	else if(data == "1") {
		context.OPERATE_M_sequence_code_min = 1;
		context.OPERATE_M_sequence_code_max = 1;
	}
	else if(data == "don't care") {
		context.OPERATE_M_sequence_code_min = M_sequence_types::M_sequence_code_min;
		context.OPERATE_M_sequence_code_max = M_sequence_types::M_sequence_code_max;
	}
	else {
		FAIL();
	}
}

GIVEN("^On-request Data Octets: (\\d)$") {
	REGEX_PARAM(int, data); //TODO: warum geht da nicht uint8_t?
	context.On_request_Data_Octets = data;
}

GIVEN("^PDin: (.+)$") {
	REGEX_PARAM(string, data);

	if(data == "0") {
		context.PDin_min = 0;
		context.PDin_max = 0;
	}
	else if(data == "3...32 octets") {
		context.PDin_min = 3;
		context.PDin_max = 32;
		context.PD_representation = M_sequence_types::PD_representation_type::octets;
	}
	else if(data == "0...32 octets") {
		context.PDin_min = 0;
		context.PDin_max = 32;
		context.PD_representation = M_sequence_types::PD_representation_type::octets;
	}
	else if(data == "1...8 bit") {
		context.PDin_min = 1;
		context.PDin_max = 8;
		context.PD_representation = M_sequence_types::PD_representation_type::bit;
	}
	else if(data == "9...16 bit") {
		context.PDin_min = 9;
		context.PDin_max = 16;
		context.PD_representation = M_sequence_types::PD_representation_type::bit;
	}
	else {
		FAIL();
	}
}

GIVEN("^PDout: (.+)$") {
	REGEX_PARAM(string, data);

	if(data == "0") {
		context.PDout_min = 0;
		context.PDout_max = 0;
	}
	else if(data == "0...32 octets") {
		context.PDout_min = 0;
		context.PDout_max = 32;
		context.PD_representation = M_sequence_types::PD_representation_type::octets;
	}
	else if(data == "3...32 octets") {
		context.PDout_min = 3;
		context.PDout_max = 32;
		context.PD_representation = M_sequence_types::PD_representation_type::octets;
	}
	else if(data == "1...8 bit") {
		context.PDout_min = 1;
		context.PDout_max = 8;
		context.PD_representation = M_sequence_types::PD_representation_type::bit;
	}
	else if(data == "9...16 bit") {
		context.PDout_min = 9;
		context.PDout_max = 16;
		context.PD_representation = M_sequence_types::PD_representation_type::bit;
	}
	else {
		FAIL();
	}
}

GIVEN("^M-sequence type: (.+)$") {
	REGEX_PARAM(string, data);

	if(data == "TYPE_0") {
		context.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_0;
	}
	else if(data == "TYPE_1_2") {
		context.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_1_2;
	}
	else if(data == "TYPE_1_1/1_2") {
		context.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_1_1__1_2;
	}
	else if(data == "TYPE_2_1") {
		context.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_2_1;
	}
	else if(data == "TYPE_2_2") {
		context.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_2_2;
	}
	else if(data == "TYPE_2_3") {
		context.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_2_3;
	}
	else if(data == "TYPE_2_4") {
		context.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_2_4;
	}
	else if(data == "TYPE_2_5") {
		context.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_2_5;
	}
	else {
		FAIL();
	}
}

static void positive_test() {
	M_sequence_types::OPERATE_M_sequence_type_valid__parameters parameters;

	for(auto a = context.OPERATE_M_sequence_code_min; a <= context.OPERATE_M_sequence_code_max; a++) {
		parameters.M_sequence_code = a;
		parameters.On_request_Data_Octets = context.On_request_Data_Octets;

		for(auto b = context.PDin_min; b <= context.PDin_max; b++) {
			parameters.PDin = b;

			for(auto c = context.PDout_min; c <= context.PDout_max; c++) {
				parameters.PDout = c;
				parameters.PD_representation = context.PD_representation;
				parameters.expected_M_sequence_type = context.expected_M_sequence_type;
	
				EXPECT_TRUE(OPERATE_M_sequence_type_valid(&parameters))
					<< "values of 'parameters'\n"
					<< std::to_string(parameters.M_sequence_code) << "\n"
					<< std::to_string((int)parameters.On_request_Data_Octets) << "\n"
					<< std::to_string(parameters.PDin) << "\n"
					<< std::to_string(parameters.PDout) << "\n"
					<< std::to_string((int)parameters.PD_representation) << "\n"
					<< std::to_string((int)parameters.expected_M_sequence_type) << "\n";
			}
		}
	}
}

// ich glaube der Negativ-Test ist nur dann sinnvoll möglich, wenn der Positiv-Test korrekt ist. Dann macht der Negativ-Test aber gar keinen Sinn mehr.
/*static void negative_test() {
	M_sequence_types::OPERATE_M_sequence_type_valid__parameters parameters;

	for(parameters.M_sequence_code = M_sequence_types::M_sequence_code_min;
	    parameters.M_sequence_code <= M_sequence_types::M_sequence_code_max;
	    parameters.M_sequence_code++) {	
		for(parameters.On_request_Data_Octets = M_sequence_types::On_request_Data_Octets_min;
		    parameters.On_request_Data_Octets <= M_sequence_types::On_request_Data_Octets_min;
		    parameters.On_request_Data_Octets++) {
			for(parameters.PDin = M_sequence_types::PDin_min;
			    parameters.PDin <= M_sequence_types::PDin_max;
			    parameters.PDin++) {
				for(parameters.PDout = M_sequence_types::PDout_min;
				    parameters.PDout <= M_sequence_types::PDout_max;
				    parameters.PDout++) {
					for(unsigned int a = 0; a < (unsigned int)M_sequence_types::PD_representation_type::_cnt; a++) {
					    	parameters.PD_representation = (M_sequence_types::PD_representation_type)a;
						for(unsigned int b = 0; b < (unsigned int)M_sequence_types::M_sequence_type::_cnt; b++) {
							parameters.expected_M_sequence_type = (M_sequence_types::M_sequence_type)b;

							bool isValidCombination = 
								parameters.M_sequence_code >= context.OPERATE_M_sequence_code_min &&
								parameters.M_sequence_code <= context.OPERATE_M_sequence_code_max &&
								parameters.On_request_Data_Octets == context.On_request_Data_Octets &&
								parameters.PDin >= context.PDin_min &&
								parameters.PDin <= context.PDin_max &&
								parameters.PDout >= context.PDout_min &&
								parameters.PDout <= context.PDout_max &&
								parameters.PD_representation == context.PD_representation &&
								parameters.expected_M_sequence_type == context.expected_M_sequence_type;
							
							if(!isValidCombination) {
								EXPECT_FALSE(OPERATE_M_sequence_type_valid(&parameters))
									<< "values of 'parameters'\n"
									<< std::to_string(parameters.M_sequence_code) << "\n"
									<< std::to_string((int)parameters.On_request_Data_Octets) << "\n"
									<< std::to_string(parameters.PDin) << "\n"
									<< std::to_string(parameters.PDout) << "\n"
									<< std::to_string((int)parameters.PD_representation) << "\n"
									<< std::to_string((int)parameters.expected_M_sequence_type) << "\n";
							}
						}
					}
				}
			}
		}
	}
}*/

THEN("^the sequence type is valid$") {
	positive_test();
	//negative_test();
}
