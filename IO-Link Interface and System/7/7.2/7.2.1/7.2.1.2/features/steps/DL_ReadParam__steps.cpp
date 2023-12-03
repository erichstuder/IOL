#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "DL_ReadParam_req.h"
#include "DL_ReadParam_cnf.h"
#include "DL_ReadParam_ind.h"
#include "DL_ReadParam_rsp.h"

using namespace DL_ReadParam;

class DL_ReadParam_mock:
	public DL_ReadParam_req__Interface,
	public DL_ReadParam_cnf__Interface,
	public DL_ReadParam_ind__Interface,
	public DL_ReadParam_rsp__Interface
{
	public:
		void DL_ReadParam_req(Argument_type* Address) override {
			(void)Address;
		}

		Result_type DL_ReadParam_cnf() override {
			return Result_type();
		}

		void DL_ReadParam_ind(Argument_type* Address) override {
			(void)Address;
		}

		Result_type DL_ReadParam_rsp() override {
			return Result_type();
		}
};

DL_ReadParam_mock dl_readParam_mock;
uint8_t Address_min;
uint8_t Address_max;

THEN("^\\.req has Argument: yes$") {
	Argument_type Argument;
	dl_readParam_mock.DL_ReadParam_req(&Argument);
}

THEN("^\\.cnf has Argument: no$") {
	dl_readParam_mock.DL_ReadParam_cnf();
}

THEN("^\\.ind has Argument: yes$") {
	Argument_type Argument;
	dl_readParam_mock.DL_ReadParam_ind(&Argument);
}

THEN("^\\.rsp has Argument: no$") {
	dl_readParam_mock.DL_ReadParam_rsp();
}

THEN("^\\.req has Result: no$") {
	//TODO: how to test?
}

THEN("^\\.cnf has Result: yes$") {
	DL_ReadParam::Result_type result = dl_readParam_mock.DL_ReadParam_cnf();
	(void)result;
}

THEN("^\\.ind has Result: no$") {
	//TODO: how to test?
}

THEN("^\\.rsp has Result: yes$") {
	DL_ReadParam::Result_type result = dl_readParam_mock.DL_ReadParam_rsp();
	(void)result;
}

GIVEN("^Address is in the range of 0 to 31$") {
    Address_min = 0;
    Address_max = 31;
}

THEN("^the Argument is in passable range$") {
	Argument_type Argument;
	
	Argument.Address = Address_min;
	dl_readParam_mock.DL_ReadParam_req(&Argument);
	dl_readParam_mock.DL_ReadParam_ind(&Argument);

	Argument.Address = Address_max;
	dl_readParam_mock.DL_ReadParam_req(&Argument);
	dl_readParam_mock.DL_ReadParam_ind(&Argument);
}

THEN("^ErrorInfo contains the error information NO_COMM and STATE_CONFLICT$") {
	Result_type result_tpye;
	(void)result_tpye;
	result_tpye.ErrorInfo = ErrorInfo_type::SUCCESS;
	result_tpye.ErrorInfo = ErrorInfo_type::NO_COMM;
	result_tpye.ErrorInfo = ErrorInfo_type::STATE_CONFLICT;
	EXPECT_EQ((int)ErrorInfo_type::_cnt, 3);
}
