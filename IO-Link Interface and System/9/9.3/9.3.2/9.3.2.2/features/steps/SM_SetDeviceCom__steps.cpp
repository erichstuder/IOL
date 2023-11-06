#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "SM_SetDeviceCom.h"


GIVEN("^SupportedSIOMode is in range \\{INACTIVE, DI, DO\\}$") {
	EXPECT_TRUE((int)SupportedSIOMode_type::INACTIVE >= 0);
	EXPECT_TRUE((int)SupportedSIOMode_type::DI >= 0);
	EXPECT_TRUE((int)SupportedSIOMode_type::DO >= 0);
	EXPECT_EQ((int)SupportedSIOMode_type::_cnt, 3);
}

GIVEN("^SupportedTransmissionrate is in range \\{COM1, COM2, COM3\\}$") {
	EXPECT_TRUE((int)SupportedTransmissionrate_type::COM1 >= 0);
	EXPECT_TRUE((int)SupportedTransmissionrate_type::COM2 >= 0);
	EXPECT_TRUE((int)SupportedTransmissionrate_type::COM3 >= 0);
	EXPECT_EQ((int)SupportedTransmissionrate_type::_cnt, 3);
}

GIVEN("^MinCycleTime has any value$") {
	SUCCEED();
}

GIVEN("^M-sequence Capability is in range \\{ISDU, OPERATE, PREOPERATE\\}$") {
	EXPECT_TRUE((int)M_sequence_Capability_type::ISDU >= 0);
	EXPECT_TRUE((int)M_sequence_Capability_type::OPERATE >= 0);
	EXPECT_TRUE((int)M_sequence_Capability_type::PREOPERATE >= 0);
	EXPECT_EQ((int)M_sequence_Capability_type::_cnt, 3);
}

GIVEN("^RevisionID \\(RID\\) has any value$") {
	SUCCEED();
}

GIVEN("^ProcessDataIn has any value$") {
	SUCCEED();
}

GIVEN("^ProcessDataOut has any value$") {
	SUCCEED();
}

THEN("^the Argument is in passable range$") {
	// check whether the service takes the above types
	SM_SetDeviceCom__parameters parameters;
	parameters.SupportedSIOMode = SupportedSIOMode_type::INACTIVE;
	parameters.SupportedTransmissionrate = SupportedTransmissionrate_type::COM1;
	parameters.MinCycleTime = 1.1f;
	parameters.M_sequence_Capability = M_sequence_Capability_type::ISDU;
	parameters.RevisionID = 42;
	parameters.ProcessDataIn = 100;
	parameters.ProcessDataOut = 72;

	SM_SetDeviceCom(parameters);
}

THEN("^the Result can only have the values SUCCESS and PARAMETER_CONFLICT$") {
	EXPECT_TRUE((int)Result_type::SUCCESS >= 0);
	EXPECT_TRUE((int)Result_type::PARAMETER_CONFLICT >= 0);
	EXPECT_EQ((int)Result_type::_cnt, 2);
}
