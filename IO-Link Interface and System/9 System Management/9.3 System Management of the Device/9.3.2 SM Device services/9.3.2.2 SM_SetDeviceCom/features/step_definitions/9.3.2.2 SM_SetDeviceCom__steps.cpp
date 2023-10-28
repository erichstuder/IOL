#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "9.3.2.2 SM_SetDeviceCom.h"

/*#include <regex>
#include <boost/range/irange.hpp>

using std::string; //TODO: braucht es das? Wie funktioniert das genau?

using namespace A_2_M_sequence_types;

static struct {
	uint8_t OPERATE_M_sequence_code_min;
	uint8_t OPERATE_M_sequence_code_max;
	uint8_t On_request_Data_Octets;
	uint8_t PDin_min;
	uint8_t PDin_max;
	uint8_t PDout_min;
	uint8_t PDout_max;
	PD_representation_type PD_representation;
	M_sequence_type expected_M_sequence_type;
} context;

enum class Table_ID {
	A9,
	A10
};*/


GIVEN("^SupportedSIOMode is in range \\{INACTIVE, DI, DO\\}$") {
	//check whether the values exist
	EXPECT_TRUE((int)SupportedSIOMode::INACTIVE >= 0);
	EXPECT_TRUE((int)SupportedSIOMode::DI >= 0);
	EXPECT_TRUE((int)SupportedSIOMode::DO >= 0);
	EXPECT_EQ((int)SupportedSIOMode::_cnt, 3);
}

GIVEN("^SupportedTransmissionrate is in range \\{COM1, COM2, COM3\\}$") {
	//check whether the values exist
	EXPECT_TRUE((int)SupportedTransmissionrate::COM1 >= 0);
	EXPECT_TRUE((int)SupportedTransmissionrate::COM2 >= 0);
	EXPECT_TRUE((int)SupportedTransmissionrate::COM3 >= 0);
	EXPECT_EQ((int)SupportedTransmissionrate::_cnt, 3);
}

GIVEN("^MinCycleTime has any value$") {
	//TODO: check the type?
	FAIL();
}

GIVEN("^M-sequence Capability is in range \\{ISDU, OPERATE, PREOPERATE\\}$") {
	//check whether the values exist
	EXPECT_TRUE((int)M_sequence_Capability::ISDU >= 0);
	EXPECT_TRUE((int)M_sequence_Capability::OPERATE >= 0);
	EXPECT_TRUE((int)M_sequence_Capability::PREOPERATE >= 0);
	EXPECT_EQ((int)M_sequence_Capability::_cnt, 3);
}

GIVEN("^RevisionID \\(RID\\) has any value$") {
	//TODO: check the type?
	FAIL();
}

GIVEN("^ProcessDataIn has any value$") {
	//TODO: check the type?
	FAIL();
}

GIVEN("^ProcessDataOut has any value$") {
	//TODO: check the type?
	FAIL();
}

THEN("^the Arguments are in passable range$") {
	//TODO: check if the service takes the above types
	FAIL();
}

/*THEN("^the Result can only have the values SUCCESS and PARAMETER_CONFLICT$") {
	FAIL();
}*/
