#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "PL_Transfer.h"

using std::string;

class PL_Transfer_mock: public PL_Transfer {
	public:
		void PL_Transfer_req(uint8_t Data) {
			(void)Data;
		}

		Status PL_Transfer_ind(uint8_t Data) {
			(void)Data;
			return Status::SUCCESS;
		}
};

static PL_Transfer_mock service_mock;
static uint8_t Data_min;
static uint8_t Data_max;

THEN("^\\.req has Argument: Data$") {
	service_mock.PL_Transfer_req(100);
}

THEN("^\\.req has Result: -$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.ind has Argument: Data$") {
	service_mock.PL_Transfer_ind(66);
}

THEN("^\\.ind has Result: Status$") {
	PL_Transfer::Status status = service_mock.PL_Transfer_ind(6);
	(void)status;
}

GIVEN("^Data is in the range of 0\\.\\.\\.255$") {
	Data_min = 0;
	Data_max = 255;
}

THEN("^the Argument is in passable range$") {
	service_mock.PL_Transfer_req(Data_min);
	service_mock.PL_Transfer_req(Data_max);

	service_mock.PL_Transfer_ind(Data_min);
	service_mock.PL_Transfer_ind(Data_max);
}

THEN("^Status has the possible value SUCCESS, PARITY_ERROR, FRAMING_ERROR or OVERRUN$") {
	PL_Transfer::Status status;
	(void)status;
	status = PL_Transfer::Status::SUCCESS;
	status = PL_Transfer::Status::PARITY_ERROR;
	status = PL_Transfer::Status::FRAMING_ERROR;
	status = PL_Transfer::Status::OVERRUN;
	EXPECT_EQ((int)PL_Transfer::Status::_cnt, 4);
}
