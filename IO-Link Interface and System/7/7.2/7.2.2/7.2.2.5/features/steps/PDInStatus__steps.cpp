#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "PDInStatus_req.h"
#include "PDInStatus_ind.h"

class PDInStatus_mock:
	public PDInStatus_req__Interface,
	public PDInStatus_ind__Interface
{
	public:
		void PDInStatus_req(PDInStatus::Argument_type Argument) override {
			(void)Argument;
		}

		void PDInStatus_ind(PDInStatus::Argument_type Argument) override {
			(void)Argument;
		}
};


PDInStatus_mock pdInStatus;

THEN("^\\.req has Argument: yes$") {
	PDInStatus::Argument_type argument;
	pdInStatus.PDInStatus_req(argument);
}

THEN("^\\.ind has Argument: yes$") {
	PDInStatus::Argument_type argument;
	pdInStatus.PDInStatus_ind(argument);
}

GIVEN("^Status is VALID or INVALID$") {
	PDInStatus::Argument_type argument;
	argument.Status = PDInStatus::Status_type::VALID;
	argument.Status = PDInStatus::Status_type::INVALID;
	(void)argument;
}

THEN("^the Argument is in passable range$") {
	PDInStatus::Argument_type argument;
	argument.Status = PDInStatus::Status_type::VALID;
	pdInStatus.PDInStatus_req(argument);
	pdInStatus.PDInStatus_ind(argument);
}
