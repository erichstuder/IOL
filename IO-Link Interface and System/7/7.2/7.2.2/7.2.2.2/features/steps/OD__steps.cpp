#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "OD_req.h"
#include "OD_ind.h"
#include "OD_rsp.h"
#include "OD_cnf.h"

using std::string;

class OD_mock:
	public OD_req__Interface,
	public OD_ind__Interface,
	public OD_rsp__Interface,
	public OD_cnf__Interface
{
	public:
		void OD_req(OD::Argument_type Argument) override {
			(void)Argument;
		}

		void OD_ind(OD::Argument_type Argument) override {
			(void)Argument;
		}
		
		OD::Result_type OD_rsp() override {
			return OD::Result_type(55);
		}
		
		OD::Result_type OD_cnf() override {
			return OD::Result_type(0);
		}
};


static OD_mock od;
static OD::Result_type* result;
static const uint8_t Data_Length = 6;
static const uint8_t Data_Sequence[] = {1,2,3,4,5,6};

THEN("^\\.req has Argument: yes") {
	OD::Argument_type Argument;
	od.OD_req(Argument);
}

THEN("^\\.ind has Argument: yes") {
	OD::Argument_type Argument;
	od.OD_ind(Argument);
}

THEN("^\\.rsp has Argument: no") {
	od.OD_rsp();
}

THEN("^\\.cnf has Argument: no") {
	od.OD_cnf();
}

THEN("^\\.req has Result: no$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.ind has Result: no$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.rsp has Result: yes$") {
	OD::Result_type dummy = od.OD_rsp();
	(void)dummy;
}

THEN("^\\.cnf has Result: yes$") {
	OD::Result_type dummy = od.OD_cnf();
	(void)dummy;
}

GIVEN("^RWDirection is in the range \\{READ, WRITE\\}$") {
	EXPECT_TRUE((int)OD::RWDirection_type::READ >= 0);
	EXPECT_TRUE((int)OD::RWDirection_type::WRITE >= 0);
	EXPECT_EQ((int)OD::RWDirection_type::_cnt, 2);
}

GIVEN("^ComChannel is in the range \\{DIAGNOSIS, PAGE, ISDU\\}$") {
	EXPECT_TRUE((int)OD::ComChannel_type::DIAGNOSIS >= 0);
	EXPECT_TRUE((int)OD::ComChannel_type::PAGE >= 0);
	EXPECT_TRUE((int)OD::ComChannel_type::ISDU >= 0);
	EXPECT_EQ((int)OD::ComChannel_type::_cnt, 3);
}

GIVEN("^AddressCtrl is in the range \\{0..31\\}$") {
	EXPECT_TRUE((int)OD::AddressCtrl_type::_0 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_1 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_2 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_3 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_4 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_5 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_6 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_7 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_8 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_9 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_10 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_11 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_12 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_13 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_14 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_15 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_16 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_17 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_18 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_19 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_20 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_21 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_22 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_23 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_24 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_25 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_26 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_27 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_28 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_29 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_30 >= 0);
	EXPECT_TRUE((int)OD::AddressCtrl_type::_31 >= 0);
	EXPECT_EQ((int)OD::AddressCtrl_type::_cnt, 32);
}

GIVEN("^Length is in the range \\{0..32\\}$") {
	EXPECT_TRUE((int)OD::Length_type::_0 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_1 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_2 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_3 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_4 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_5 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_6 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_7 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_8 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_9 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_10 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_11 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_12 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_13 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_14 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_15 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_16 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_17 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_18 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_19 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_20 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_21 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_22 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_23 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_24 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_25 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_26 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_27 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_28 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_29 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_30 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_31 >= 0);
	EXPECT_TRUE((int)OD::Length_type::_32 >= 0);
	EXPECT_EQ((int)OD::Length_type::_cnt, 33);
}

GIVEN("^Data is of type Octet string$") {
	OD::Argument_type Argument;
	Argument.Data = new OctetStringT(23);
	(void)Argument;
}

GIVEN("^the Argument is passable range$") {
	OD::Argument_type Argument;
	Argument.RWDirection = OD::RWDirection_type::READ;
	Argument.ComChannel = OD::ComChannel_type::DIAGNOSIS;
	Argument.AddressCtrl = OD::AddressCtrl_type::_17;
	Argument.Length = OD::Length_type::_32;
	Argument.Data = new OctetStringT(23);

	od.OD_req(Argument);
	od.OD_ind(Argument);
}

GIVEN("^the service executed successfully$") {
	result = new OD::Result_type(Data_Length);
	result->ErrorInfo = OD::Result_type::ErrorInfo_type::SUCCESS;
	result->Data->sequence = (uint8_t*)Data_Sequence;
}

THEN("^Data contains the read data values$") {
	for(auto i = 0; i < Data_Length; i++) {
		if(result->Data->sequence[i] != Data_Sequence[i]) {
			FAIL() << "data not equal";
		}
	}
}

THEN("^Length contains the length of the received data package$") {
	EXPECT_EQ(result->Data->Length, Data_Length);
}

THEN("^Length is in range \\{0\\.\\.32\\}$") {
	result = new OD::Result_type(0);
	EXPECT_EQ(result->Data->Length, 0);

	result = new OD::Result_type(32);
	EXPECT_EQ(result->Data->Length, 32);
}

GIVEN("^the Service failed$") {
	//nothing to test
}

THEN("^ErrorInfo is in the range \\{NO_COMM, STATE_CONFLICT\\}$") {
	OD::Result_type::ErrorInfo_type error;
	(void)error;
	error = OD::Result_type::ErrorInfo_type::NO_COMM;
	error = OD::Result_type::ErrorInfo_type::STATE_CONFLICT;
	EXPECT_EQ((int)OD::Result_type::ErrorInfo_type::_cnt, 3);
}
