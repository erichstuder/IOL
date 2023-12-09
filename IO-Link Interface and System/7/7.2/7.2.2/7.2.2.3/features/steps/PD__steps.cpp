#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "PD_req.h"
#include "PD_ind.h"
#include "PD_rsp.h"
#include "PD_cnf.h"

using std::string;

class PD_mock:
	public PD_req__Interface,
	public PD_ind__Interface,
	public PD_rsp__Interface,
	public PD_cnf__Interface
{
	public:
		void PD_req(PD::Argument_type Argument) override {
			(void)Argument;
		}

		void PD_ind(PD::Argument_type Argument) override {
			(void)Argument;
		}
		
		PD::Result_type PD_rsp() override {
			return PD::Result_type(1);
		}
		
		PD::Result_type PD_cnf() override {
			return PD::Result_type(2);
		}
};


static PD_mock pd;
static PD::Result_type* result;

THEN("^\\.req has Argument: yes") {
	PD::Argument_type argument;
	pd.PD_req(argument);
}

THEN("^\\.ind has Argument: yes") {
	PD::Argument_type argument;
	pd.PD_ind(argument);
}

THEN("^\\.rsp has Argument: no") {
	pd.PD_rsp();
}

THEN("^\\.cnf has Argument: no") {
	pd.PD_cnf();
}

THEN("^\\.req has Result: no$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.ind has Result: no$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.rsp has Result: yes$") {
	PD::Result_type dummy = pd.PD_rsp();
	(void)dummy;
}

THEN("^\\.cnf has Result: yes$") {
	PD::Result_type dummy = pd.PD_cnf();
	(void)dummy;
}

GIVEN("^PDInAddress$") {
	PD::Argument_type argument;
	uint8_t address = argument.PDInAddress;
	(void)address;
}

GIVEN("^PDInLength is 0 to 32$") {
	PD::Argument_type argument;
	(void)argument;
	argument.PDInLength = PD::PDInLength_type::_0;
	argument.PDInLength = PD::PDInLength_type::_1;
	argument.PDInLength = PD::PDInLength_type::_2;
	argument.PDInLength = PD::PDInLength_type::_3;
	argument.PDInLength = PD::PDInLength_type::_4;
	argument.PDInLength = PD::PDInLength_type::_5;
	argument.PDInLength = PD::PDInLength_type::_6;
	argument.PDInLength = PD::PDInLength_type::_7;
	argument.PDInLength = PD::PDInLength_type::_8;
	argument.PDInLength = PD::PDInLength_type::_9;
	argument.PDInLength = PD::PDInLength_type::_10;
	argument.PDInLength = PD::PDInLength_type::_11;
	argument.PDInLength = PD::PDInLength_type::_12;
	argument.PDInLength = PD::PDInLength_type::_13;
	argument.PDInLength = PD::PDInLength_type::_14;
	argument.PDInLength = PD::PDInLength_type::_15;
	argument.PDInLength = PD::PDInLength_type::_16;
	argument.PDInLength = PD::PDInLength_type::_17;
	argument.PDInLength = PD::PDInLength_type::_18;
	argument.PDInLength = PD::PDInLength_type::_19;
	argument.PDInLength = PD::PDInLength_type::_20;
	argument.PDInLength = PD::PDInLength_type::_21;
	argument.PDInLength = PD::PDInLength_type::_22;
	argument.PDInLength = PD::PDInLength_type::_23;
	argument.PDInLength = PD::PDInLength_type::_24;
	argument.PDInLength = PD::PDInLength_type::_25;
	argument.PDInLength = PD::PDInLength_type::_26;
	argument.PDInLength = PD::PDInLength_type::_27;
	argument.PDInLength = PD::PDInLength_type::_28;
	argument.PDInLength = PD::PDInLength_type::_29;
	argument.PDInLength = PD::PDInLength_type::_30;
	argument.PDInLength = PD::PDInLength_type::_31;
	argument.PDInLength = PD::PDInLength_type::_32;
	EXPECT_EQ((int)PD::PDInLength_type::_cnt, 33);
}

GIVEN("^PDOut is an Octet string$") {
	PD::Argument_type argument;
	(void)argument;
	argument.PDout = new OctetStringT(88);
}

GIVEN("^PDOutAddress$") {
	PD::Argument_type argument;
	uint8_t address = argument.PDOutAddress;
	(void)address;
}

GIVEN("^PDOutLength is 0 to 32$") {
	PD::Argument_type argument;
	(void)argument;
	argument.PDOutLength = PD::PDOutLength_type::_0;
	argument.PDOutLength = PD::PDOutLength_type::_1;
	argument.PDOutLength = PD::PDOutLength_type::_2;
	argument.PDOutLength = PD::PDOutLength_type::_3;
	argument.PDOutLength = PD::PDOutLength_type::_4;
	argument.PDOutLength = PD::PDOutLength_type::_5;
	argument.PDOutLength = PD::PDOutLength_type::_6;
	argument.PDOutLength = PD::PDOutLength_type::_7;
	argument.PDOutLength = PD::PDOutLength_type::_8;
	argument.PDOutLength = PD::PDOutLength_type::_9;
	argument.PDOutLength = PD::PDOutLength_type::_10;
	argument.PDOutLength = PD::PDOutLength_type::_11;
	argument.PDOutLength = PD::PDOutLength_type::_12;
	argument.PDOutLength = PD::PDOutLength_type::_13;
	argument.PDOutLength = PD::PDOutLength_type::_14;
	argument.PDOutLength = PD::PDOutLength_type::_15;
	argument.PDOutLength = PD::PDOutLength_type::_16;
	argument.PDOutLength = PD::PDOutLength_type::_17;
	argument.PDOutLength = PD::PDOutLength_type::_18;
	argument.PDOutLength = PD::PDOutLength_type::_19;
	argument.PDOutLength = PD::PDOutLength_type::_20;
	argument.PDOutLength = PD::PDOutLength_type::_21;
	argument.PDOutLength = PD::PDOutLength_type::_22;
	argument.PDOutLength = PD::PDOutLength_type::_23;
	argument.PDOutLength = PD::PDOutLength_type::_24;
	argument.PDOutLength = PD::PDOutLength_type::_25;
	argument.PDOutLength = PD::PDOutLength_type::_26;
	argument.PDOutLength = PD::PDOutLength_type::_27;
	argument.PDOutLength = PD::PDOutLength_type::_28;
	argument.PDOutLength = PD::PDOutLength_type::_29;
	argument.PDOutLength = PD::PDOutLength_type::_30;
	argument.PDOutLength = PD::PDOutLength_type::_31;
	argument.PDOutLength = PD::PDOutLength_type::_32;
	EXPECT_EQ((int)PD::PDOutLength_type::_cnt, 33);
}

THEN("^the Argument is passable range$") {
	PD::Argument_type Argument;
	Argument.PDInAddress = 22;
	Argument.PDInLength = PD::PDInLength_type::_13;
	Argument.PDout = new OctetStringT(23);
	Argument.PDOutAddress = 66;
	Argument.PDOutLength = PD::PDOutLength_type::_13;

	pd.PD_req(Argument);
	pd.PD_ind(Argument);
}

GIVEN("^the service executed successfully$") {
	result = new PD::Result_type(44);
	result->ErrorInfo = PD::Result_type::ErrorInfo_type::SUCCESS;
}

THEN("^PDIn contains the Process Data to be transferred from the device$") {
	//nothing to test
}

THEN("^PDIn is an Octet string$") {
	result->PDIn = new OctetStringT(33);
}

GIVEN("^the Service failed$") {
	//nothing to test
}

THEN("^ErrorInfo is in the range \\{NO_COMM, STATE_CONFLICT\\}$") {
	PD::Result_type::ErrorInfo_type error;
	(void)error;
	error = PD::Result_type::ErrorInfo_type::NO_COMM;
	error = PD::Result_type::ErrorInfo_type::STATE_CONFLICT;
	EXPECT_EQ((int)PD::Result_type::ErrorInfo_type::_cnt, 3);
}
