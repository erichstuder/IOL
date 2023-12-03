#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "EventFlag_ind.h"
#include "EventFlag_req.h"

class EventFlag_mock:
	public EventFlag_ind__Interface,
	public EventFlag_req__Interface
{
	public:
		void EventFlag_ind(EventFlag::Argument_type* Argument) override {
			(void)Argument;
		}

		void EventFlag_req(EventFlag::Argument_type* Argument) override {
			(void)Argument;
		}
};


EventFlag_mock eventFlag;

THEN("^\\.ind has Argument: yes$") {
	EventFlag::Argument_type argument;
	eventFlag.EventFlag_ind(&argument);
}

THEN("^\\.req has Argument: yes$") {
	EventFlag::Argument_type argument;
	eventFlag.EventFlag_req(&argument);
}

GIVEN("^Flag is TRUE or FALSE$") {
	EventFlag::Argument_type argument;
	argument.Flag = true;
	argument.Flag = false;
	(void)argument;
}

THEN("^the Argument is passable range$") {
	EventFlag::Argument_type argument;
	argument.Flag = true;
	eventFlag.EventFlag_ind(&argument);
	eventFlag.EventFlag_req(&argument);
}
