#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cucumber-cpp/autodetect.hpp>

#include "State_machine_of_the_Master_ISDU_handler.h"
#include "Transitions_mock.h"

using std::string;

using namespace State_machine_of_the_Master_ISDU_handler;

static Transitions_mock* transitions = new Transitions_mock();
static States states(transitions);
static States::IState* state;
static States::Event event;

GIVEN("^State is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "Inactive_0") {
		state = states.Inactive_0;
	}
	else {
		FAIL();
	}
}

GIVEN("^Event is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "IH_Conf_ACTIVE") {
		event = States::Event::IH_Conf_ACTIVE;
	}
	else {
		FAIL();
	}
}

GIVEN("^Guard is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "-") {
		//no Guard
	}
	else {
		FAIL();
	}
}

GIVEN("^Transition is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "T1") {
		EXPECT_CALL(*transitions, T1()).Times(1);
		EXPECT_CALL(*transitions, T19()).Times(1);
		FAIL() << "Möglicherweise kann man gmock nicht einsetzen. Wenn ja wie?";
	}
	else {
		FAIL();
	}
}

THEN("^Result State is (.+)$") {
	REGEX_PARAM(string, data);

	States::IState* result_state = state->handle_event(event);
	if(data == "Idle_1") {
		EXPECT_EQ(result_state, states.Idle_1);
	}
	else {
		FAIL();
	}
}
