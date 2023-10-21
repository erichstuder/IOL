#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp> //TODO: what is this good for?

#include "M-sequence types.h"

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
} context;


GIVEN("^OPERATE M-sequence code: (.+)$") {
    REGEX_PARAM(string, data);

    if(data == "don't care") {
        context.OPERATE_M_sequence_code_min = M_sequence_types::M_sequence_code_min;
        context.OPERATE_M_sequence_code_max = M_sequence_types::M_sequence_code_max;
    }
    else if(data == "0") {
        context.OPERATE_M_sequence_code_min = 0;
        context.OPERATE_M_sequence_code_max = 0;
    }
    else if(data == "1") {
        context.OPERATE_M_sequence_code_min = 1;
        context.OPERATE_M_sequence_code_max = 1;
    }
    else {
        FAIL() << "unknown value";
    }
    
}

GIVEN("^On-request Data Octets: (.)$") {
    REGEX_PARAM(uint8_t, data);
    context.On_request_Data_Octets = data;
}

GIVEN("^PDin: (.+)$") {
    REGEX_PARAM(string, data);

    //TODO implement

    context.PDin_min = 0;
    context.PDin_max = 1;
    context.PD_representation = M_sequence_types::PD_representation_type::bit;
}

GIVEN("^PDout: (.+)$") {
    REGEX_PARAM(string, data);

    //TODO implement

    context.PDout_min = 2;
    context.PDout_max = 4;
    context.PD_representation = M_sequence_types::PD_representation_type::bit;
}

THEN("^M-sequence type: (.+)$") {
    REGEX_PARAM(string, data);

    M_sequence_types::OPERATE_M_sequence_type_valid__parameters parameters;

    if(data == "TYPE_0") {
        parameters.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_0;
    }
    else if(data == "TYPE_1_2") {
        parameters.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_1_2;
    }
    else if(data == "TYPE_1_1__1_2") {
        parameters.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_1_1__1_2;
    }
    else if(data == "TYPE_2_1") {
        parameters.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_2_1;
    }
    else if(data == "TYPE_2_2") {
        parameters.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_2_2;
    }
    else if(data == "TYPE_2_3") {
        parameters.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_2_3;
    }
    else if(data == "TYPE_2_4") {
        parameters.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_2_4;
    }
    else if(data == "TYPE_2_5") {
        parameters.expected_M_sequence_type = M_sequence_types::M_sequence_type::TYPE_2_5;
    }


    for(auto a = context.OPERATE_M_sequence_code_min; a++; a <= context.OPERATE_M_sequence_code_max) {
        parameters.M_sequence_code = a;
        parameters.On_request_Data_Octets = context.On_request_Data_Octets;
        parameters.PDin = 1;
        parameters.PDout = 1;
        parameters.PD_representation = context.PD_representation;
        EXPECT_TRUE( M_sequence_types::OPERATE_M_sequence_type_valid(&parameters) );
    }

    //TODO: Das gehört zu Annex A => entsprechend verschieben.
}
