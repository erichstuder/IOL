#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "DL_WriteParam_req.h"
#include "DL_WriteParam_cnf.h"
#include "DL_WriteParam_ind.h"

using namespace DL_WriteParam;

class DL_WriteParam_mock:
	public DL_WriteParam_req__Interface,
	public DL_WriteParam_cnf__Interface,
	public DL_WriteParam_ind__Interface
{
	public:
		void DL_WriteParam_req(Argument_type* Argument) override {
			(void)Argument;
		}

		Result_type DL_WriteParam_cnf() override {
			return Result_type();
		}

		void DL_WriteParam_ind(Argument_type* Argument) override {
			(void)Argument;
		}
};

DL_WriteParam_mock dl_writeParam_mock;
uint8_t Address_min;
uint8_t Address_max;

THEN("^\\.req has Argument: yes$") {
	Argument_type Argument;
	dl_writeParam_mock.DL_WriteParam_req(&Argument);
}

THEN("^\\.cnf has Argument: no$") {
	dl_writeParam_mock.DL_WriteParam_cnf();
}

THEN("^\\.ind has Argument: yes$") {
	Argument_type Argument;
	dl_writeParam_mock.DL_WriteParam_ind(&Argument);
}

THEN("^\\.req has Result: no$") {
	//TODO: how to test?
}

THEN("^\\.cnf has Result: yes$") {
	Result_type result = dl_writeParam_mock.DL_WriteParam_cnf();
	(void)result;
}

THEN("^\\.ind has Result: no$") {
	//TODO: how to test?
}

GIVEN("^Address is in the range of 16 to 31$") {
    Address_min = 16;
    Address_max = 31;
}

THEN("^the Argument is in passable range$") {
	Argument_type Argument;
	
	Argument.Address = Address_min;
	dl_writeParam_mock.DL_WriteParam_req(&Argument);
	dl_writeParam_mock.DL_WriteParam_ind(&Argument);

	Argument.Address = Address_max;
	dl_writeParam_mock.DL_WriteParam_req(&Argument);
	dl_writeParam_mock.DL_WriteParam_ind(&Argument);
}

THEN("^ErrorInfo contains the error information NO_COMM and STATE_CONFLICT$") {
	Result_type result_type;
	(void)result_type;
	result_type.ErrorInfo = ErrorInfo_type::SUCCESS;
	result_type.ErrorInfo = ErrorInfo_type::NO_COMM;
	result_type.ErrorInfo = ErrorInfo_type::STATE_CONFLICT;
	EXPECT_EQ((int)ErrorInfo_type::_cnt, 3);
}
