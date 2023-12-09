#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "ODTrig_ind.h"

class ODTrig_mock: ODTrig_ind__Interface {
	public:
		void ODTrig_ind(ODTrig::Argument_type Argument) override {
			(void)Argument;
		}
};


ODTrig_mock odTrig;

THEN("^\\.ind has Argument: yes$") {
	ODTrig::Argument_type argument;
	odTrig.ODTrig_ind(argument);
}

GIVEN("^DataLength$") {
	ODTrig::Argument_type argument;
	(void)argument;
	argument.DataLength = 42;
}

THEN("^the Argument is in passable range$") {
	ODTrig::Argument_type argument;
	argument.DataLength = 18;
	odTrig.ODTrig_ind(argument);
}
