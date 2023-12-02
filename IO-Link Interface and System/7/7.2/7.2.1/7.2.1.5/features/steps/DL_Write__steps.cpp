#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "DL_Write_req.h"
#include "DL_Write_cnf.h"
#include "DL_Write_ind.h"

using namespace DL_Write;

class DL_Write_mock:
	public DL_Write_req__Interface,
	public DL_Write_cnf__Interface,
	public DL_Write_ind__Interface
{
	public:
		void DL_Write_req(Argument_type* Argument) override {
			(void)Argument;
		}

		Result_type DL_Write_cnf() override {
			Result_type result;
			result.ErrorInfo = ErrorInfo_type::STATE_CONFLICT;
			return result;
		}

		void DL_Write_ind(Argument_type* Argument) override {
			(void)Argument;
		}
};

static DL_Write_mock dl_write_mock;

static uint8_t Address_min;
static uint8_t Address_max;

THEN("^\\.req has Argument: yes") {
	DL_Write::Argument_type Argument;
	dl_write_mock.DL_Write_req(&Argument);
}

THEN("^\\.ind has Argument: yes") {
	DL_Write::Argument_type Argument;
	dl_write_mock.DL_Write_ind(&Argument);
}

THEN("^\\.cnf has Argument: no") {
	dl_write_mock.DL_Write_cnf();
}

THEN("^\\.req has Result: no$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.ind has Result: no$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.cnf has Result: yes$") {
	DL_Write::Result_type dummy = dl_write_mock.DL_Write_cnf();
	(void)dummy;
}

GIVEN("^Address is in the range 0 to 15$") {
	Address_min = 0;
	Address_max = 15;
}

GIVEN("^Value contains the Device parameter to be written$") {
	//TBD
}

THEN("^the Argument is in passable range$") {
	DL_Write::Argument_type Argument;
	Argument.Value = 22;

	Argument.Address = Address_min;
	dl_write_mock.DL_Write_req(&Argument);
	dl_write_mock.DL_Write_ind(&Argument);

	Argument.Address = Address_max;
	dl_write_mock.DL_Write_req(&Argument);
	dl_write_mock.DL_Write_ind(&Argument);
}

GIVEN("^the service executed successfully$") {
	DL_Write::Result_type result;
	result.ErrorInfo = DL_Write::ErrorInfo_type::SUCCESS;
	(void)result;
}

GIVEN("^the service failed$") {
	//nothing to test
}

THEN("^the parameter ErrorInfo contains error information$") {
	DL_Write::Result_type result;
	(void)result.ErrorInfo;
}

GIVEN("^ErrorInfo has the values NO_COMM or STATE_CONFLICT$") {
	DL_Write::ErrorInfo_type error_info;
	(void)error_info;
    	error_info = DL_Write::ErrorInfo_type::SUCCESS;
    	error_info = DL_Write::ErrorInfo_type::NO_COMM;
    	error_info = DL_Write::ErrorInfo_type::STATE_CONFLICT;
	EXPECT_EQ((int)DL_Write::ErrorInfo_type::_cnt, 3);
}
