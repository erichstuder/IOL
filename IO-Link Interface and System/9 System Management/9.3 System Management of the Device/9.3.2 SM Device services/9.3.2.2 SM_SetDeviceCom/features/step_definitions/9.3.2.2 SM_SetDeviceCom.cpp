#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp> //TODO: what is this good for?

#include "9.3.2.2 SM_SetDeviceCom.h"


//using cucumber::ScenarioScope;

//#define STR_HELPER(x) #x
//#define STR(x) STR_HELPER(x)
//#pragma message "__COUNTER__  " STR(__COUNTER__)

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
}

GIVEN("^SupportedTransmissionrate is in range \\{COM1, COM2, COM3\\}$") {
}

GIVEN("^MinCycleTime has any value$") {
}

GIVEN("^M-sequence Capability is in range \\{ISDU, OPERATE, PREOPERATE\\}$") {
}

GIVEN("^RevisionID \\(RID\\) has any value$") {
}

GIVEN("^ProcessDataIn has any value$") {
}

GIVEN("^ProcessDataOut has any value$") {
}

THEN("^the Arguments are in passable range$") {
}

THEN("^the Result can only have the values SUCCESS and PARAMETER_CONFLICT$") {
}
