#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "PDTrig_ind.h"

class PDTrig_mock: PDTrig_ind__Interface {
	public:
		void PDTrig_ind(PDTrig::Argument_type Argument) override {
			(void)Argument;
		}
};


PDTrig_mock pdTrig;

THEN("^\\.ind has Argument: yes$") {
	PDTrig::Argument_type argument;
	pdTrig.PDTrig_ind(argument);
}

GIVEN("^DataLength$") {
	PDTrig::Argument_type argument;
	(void)argument;
	argument.DataLength = 42;
}

THEN("^the Argument is in passable range$") {
	PDTrig::Argument_type argument;
	argument.DataLength = 18;
	pdTrig.PDTrig_ind(argument);
}
