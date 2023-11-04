#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "State_machine_of_the_Master_ISDU_handler.h"

using std::string;

using namespace State_machine_of_the_Master_ISDU_handler;

class Transitions_mock: public ITransitions {
	public:
		void T1() { set_transition_number(1); }
		void T2() { set_transition_number(2); }
		void T3() { set_transition_number(3); }
		void T4() { set_transition_number(4); }
		void T5() { set_transition_number(5); }
		void T6() { set_transition_number(6); }
		void T7() { set_transition_number(7); }
		void T8() { set_transition_number(8); }
		void T9() { set_transition_number(9); }
		void T10() { set_transition_number(10); }
		void T11() { set_transition_number(11); }
		void T12() { set_transition_number(12); }
		void T13() { set_transition_number(13); }
		void T14() { set_transition_number(14); }
		void T15() { set_transition_number(15); }
		void T16() { set_transition_number(16); }
		void T17() { set_transition_number(17); }
		void T18() { set_transition_number(18); }
		void T19() { set_transition_number(19); }

		unsigned int transition_number;

		void set_transition_number(unsigned int transition_number) {
			this->transition_number = transition_number;
		}
};

static Transitions_mock* transitions_mock = new Transitions_mock();
static States states(transitions_mock);
static States::IState* state;
static States::Event event;
static States::Guard guard;
static unsigned int expected_transiton_number;

GIVEN("^State is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "Inactive_0") {
		state = states.Inactive_0;
	}
	else if(data == "Idle_1") {
		state = states.Idle_1;
	}
	else {
		FAIL() << "unknown State";
	}
}

GIVEN("^Event is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "IH_Conf_ACTIVE") {
		event = States::Event::IH_Conf_ACTIVE;
	}
	else if(data == "ISDUTrig") {
		event = States::Event::ISDUTrig;
	}
	else {
		FAIL() << "unknown Event";
	}
}

GIVEN("^Guard is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "-") {
		guard = States::Guard::NoGuard;
	}
	else if(data == "DL_ISDUTransport") {
		guard = States::Guard::DL_ISDUTransport;
	}
	else {
		FAIL() << "unknown Guard";
	}
}

GIVEN("^Transition is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "T1") {
		expected_transiton_number = 1;
	}
	else if(data == "T2") {
		expected_transiton_number = 2;
	}
	else {
		FAIL() << "unknown Transition";
	}
}

THEN("^Result State is (.+)$") {
	REGEX_PARAM(string, data);

	States::IState* result_state = state->handle_event(event, guard);
	if(data == "Idle_1") {
		EXPECT_EQ(result_state, states.Idle_1);
		EXPECT_EQ(transitions_mock->transition_number, expected_transiton_number);
	}
	else if(data == "ISDURequest_2") {
		EXPECT_EQ(result_state, states.ISDURequest_2);
		EXPECT_EQ(transitions_mock->transition_number, expected_transiton_number);
	}
	else {
		FAIL() << "unknown Result State";
	}
}
