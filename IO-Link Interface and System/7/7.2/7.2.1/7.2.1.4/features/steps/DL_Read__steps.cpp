#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "DL_Read_req.h"
#include "DL_Read_cnf.h"
#include "DL_Read_ind.h"
#include "DL_Read_rsp.h"

using namespace DL_Read;

class DL_Read_mock:
	public DL_Read_req__Interface,
	public DL_Read_cnf__Interface,
	public DL_Read_ind__Interface,
	public DL_Read_rsp__Interface
{
	public:
		void DL_Read_req(Argument_type* Argument) override {
			(void)Argument;
		}

		Result_type DL_Read_cnf() override {
			Result_type result;
			result.Value = 0;
			return result;
		}

		void DL_Read_ind(Argument_type* Argument) override {
			(void)Argument;
		}

		Result_type DL_Read_rsp() override {
			Result_type result;
			result.Value = 0;
			return result;
		}
};

static DL_Read_mock dl_read_mock;

static uint8_t Address_min;
static uint8_t Address_max;

THEN("^\\.req has Argument: yes") {
	DL_Read::Argument_type Argument;
	dl_read_mock.DL_Read_req(&Argument);
}

THEN("^\\.ind has Argument: yes") {
	DL_Read::Argument_type Argument;
	dl_read_mock.DL_Read_ind(&Argument);
}

THEN("^\\.rsp has Argument: no") {
	dl_read_mock.DL_Read_rsp();
}

THEN("^\\.cnf has Argument: no") {
	dl_read_mock.DL_Read_cnf();
}

THEN("^\\.req has Result: no$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.ind has Result: no$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.rsp has Result: yes$") {
	DL_Read::Result_type dummy = dl_read_mock.DL_Read_rsp();
	(void)dummy;
}

THEN("^\\.cnf has Result: yes$") {
	DL_Read::Result_type dummy = dl_read_mock.DL_Read_cnf();
	(void)dummy;
}

GIVEN("^Address is in the range 0 to 15$") {
	Address_min = 0;
	Address_max = 15;
}

THEN("^the Argument is in passable range$") {
	DL_Read::Argument_type Argument;

	Argument.Address = Address_min;
	dl_read_mock.DL_Read_req(&Argument);
	dl_read_mock.DL_Read_ind(&Argument);

	Argument.Address = Address_max;
	dl_read_mock.DL_Read_req(&Argument);
	dl_read_mock.DL_Read_ind(&Argument);
}

GIVEN("^the service executed successfully$") {
	DL_Read::Result_type result;
	result.ErrorInfo = DL_Read::ErrorInfo_type::SUCCESS;
	(void)result;
}

GIVEN("^the service failed$") {
	//nothing to test
}

THEN("^the parameter ErrorInfo contains error information$") {
	DL_Read::Result_type result;
	(void)result.ErrorInfo;
}

GIVEN("^ErrorInfo has the values NO_COMM or STATE_CONFLICT$") {
	DL_Read::ErrorInfo_type error_info;
	(void)error_info;
    	error_info = DL_Read::ErrorInfo_type::SUCCESS;
    	error_info = DL_Read::ErrorInfo_type::NO_COMM;
    	error_info = DL_Read::ErrorInfo_type::STATE_CONFLICT;
	EXPECT_EQ((int)DL_Read::ErrorInfo_type::_cnt, 3);
}
