#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp> //TODO: what is this good for?

#include "M-sequence types.h"

using std::string;

static struct {
    string OPERATE_M_sequence_code;
    string On_request_Data_Octets;
    string PDin;
    string PDout;
} context;


GIVEN("^OPERATE M-sequence code: (.+)$") {
    REGEX_PARAM(string, data);
    context.OPERATE_M_sequence_code = data;
}

GIVEN("^On-request Data Octets: (.+)$") {
    REGEX_PARAM(string, data);
    context.On_request_Data_Octets = data;
}

GIVEN("^PDin: (.+)$") {
    REGEX_PARAM(string, data);
    context.PDin = data;
}

GIVEN("^PDout: (.+)$") {
    REGEX_PARAM(string, data);
    context.PDout = data;
}

THEN("^M-sequence type: (.+)$") {
    REGEX_PARAM(string, data);

    M_sequence_types::M_sequence_type_valid__parameters parameters;


    if(context.OPERATE_M_sequence_code == "don't care") {
        //für alle möglichen Werte
    }
    else {
        parameters.expected_type = M_sequence_types::M_sequence_type::TYPE_1_2;
        EXPECT_TRUE( M_sequence_types::M_sequence_type_valid(&parameters) );
    }

    //EXPECT_EQ(1,1);

    //TODO: Das gehört zu Annex A => entsprechend verschieben.
}
