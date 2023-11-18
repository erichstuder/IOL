#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "DL_ReadParam.h"

class DL_ReadParam_mock: public DL_ReadParam {
	public:
		void DL_ReadParam_req(uint8_t Address) {
			(void)Address;
		}

		Result_type DL_ReadParam_cnf() {
			return Result_type();
		}

		void DL_ReadParam_ind(uint8_t Address) {
			(void)Address;
		}

		Value_type DL_ReadParam_rsp() {
			return 14;
		}
};

DL_ReadParam_mock service_mock;
uint8_t Address_min;
uint8_t Address_max;

THEN("^\\.req has Argument: Address$") {
	service_mock.DL_ReadParam_req(42);
}

THEN("^\\.req has Result: -$") {
	//TODO: how to test?
}

THEN("^\\.cnf has Argument: -$") {
	service_mock.DL_ReadParam_cnf();
}

THEN("^\\.cnf has Result: Value, ErrorInfo$") {
	DL_ReadParam::Result_type result = service_mock.DL_ReadParam_cnf();
	(void)result;
}

THEN("^\\.ind has Argument: Address$") {
	service_mock.DL_ReadParam_ind(61);
}

THEN("^\\.ind has Result: -$") {
	//TODO: how to test?
}

THEN("^\\.rsp has Argument: -$") {
	service_mock.DL_ReadParam_rsp();
}

THEN("^\\.rsp has Result: Value$") {
	DL_ReadParam::Value_type value = service_mock.DL_ReadParam_rsp();
	(void)value;
}

GIVEN("^Address is in the range of 0 to 31$") {
    Address_min = 0;
    Address_max = 31;
}

THEN("^the Argument is in passable range$") {
	service_mock.DL_ReadParam_req(Address_min);
	service_mock.DL_ReadParam_ind(Address_min);
	service_mock.DL_ReadParam_req(Address_max);
	service_mock.DL_ReadParam_ind(Address_max);
}

THEN("^ErrorInfo contains the error information NO_COMM and STATE_CONFLICT$") {
	DL_ReadParam::ErrorInfo_type error_info;
	(void)error_info;
	error_info = DL_ReadParam::ErrorInfo_type::NO_COMM;
	error_info = DL_ReadParam::ErrorInfo_type::STATE_CONFLICT;
	EXPECT_EQ((int)DL_ReadParam::ErrorInfo_type::_cnt, 2);
}
