#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp> //TODO: what is this good for?

static struct {
    int OPERATE_M_sequence_code;
} context;


//GIVEN("^I have entered (\\.) into the calculator$") {
GIVEN("^OPERATE M-sequence code: (.)$") {
    REGEX_PARAM(char, code);
    int value;

    switch(code) {
        case '0':
            value = 0;
            break;
        case '1':
            value = 1;
            break;
        case 'x':
            value = don_t_care;
            break;
        default:
            FAIL() << "unknown value: " << code;
            break;
    }
    context.OPERATE_M_sequence_code = value;
}
