#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "../../components/States.h"

#include "mocks/OD_handler_mock.h"
#include "mocks/PD_handler_mock.h"
#include "mocks/PL_Transfer_mock.h"
#include "mocks/DL_mode_handler_mock.h"

using std::string;

using namespace State_machine_of_the_Device_message_handler;

class Transitions_mock: public Transitions_Interface {
	public:
		using Transitions_Interface::Transitions_Interface;

		void T1() override { transition_number = 1; }
		void T2() override { transition_number = 2; }
		void T3() override { transition_number = 3; }
		void T4() override { transition_number = 4; }
		void T5() override { transition_number = 5; }
		void T6() override { transition_number = 6; }
		void T7() override { transition_number = 7; }
		void T8() override { transition_number = 8; }
		void T9() override { transition_number = 9; }
		void T10() override { transition_number = 10; }
		void T11() override { transition_number = 11; }

		unsigned int transition_number;

		void reset() {
			transition_number = 0;
		}
};

class Timer_mock: public ITimer {
	public:
		void start() override {
			FAIL() << "Timer_mock start";
		}

		void restart() override {
			FAIL() << "Timer_mock restart";
		}

		void reset() override {
			FAIL() << "Timer_mock reset";
		}
};

static Timer_mock* timer_mock = new Timer_mock();
static Administration* administration = new Administration(timer_mock, timer_mock);
static Transitions_mock* transitions_mock = new Transitions_mock(
	administration,
	new OD_handler_mock(),
	new PD_handler_mock(),
	new PL_Transfer_mock(),
	new DL_mode_handler_mock()
);

static States states(administration, transitions_mock);
static State_Interface::Guard guard;
static unsigned int expected_transiton_number;
static string event;


BEFORE() {
	transitions_mock->reset();
}

GIVEN("^State is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "Inactive_0") {
		states.state = states.Inactive_0;
	}
	else if(data == "Idle_1") {
		states.state = states.Idle_1;
	}
	else if(data == "GetMessage_2") {
		states.state = states.GetMessage_2;
	}
	else if(data == "CheckMessage_3") {
		states.state = states.CheckMessage_3;
	}
	else if(data == "CreateMessage_4") {
		states.state = states.CreateMessage_4;
	}
	else {
		FAIL() << "unknown State";
	}
}

GIVEN("^Event is (.+)$") {
	REGEX_PARAM(string, data);
	event = data;
}

GIVEN("^Guard is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "-") {
		guard = State_Interface::Guard::NoGuard;
	}
	else if(data == "Completed") {
		guard = State_Interface::Guard::Completed;
	}
	else if(data == "No error") {
		guard = State_Interface::Guard::No_error;
	}
	else if(data == "ChecksumError") {
		guard = State_Interface::Guard::ChecksumError;
	}
	else if(data == "TypeError and not ChecksumError") {
		guard = State_Interface::Guard::TypeError_and_not_ChecksumError;
	}
	else if(data == "Ready") {
		guard = State_Interface::Guard::Ready;
	}
	else {
		FAIL() << "unknown Guard";
	}
}

THEN("^Transition is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "T1") { expected_transiton_number = 1; }
	else if(data == "T2") { expected_transiton_number = 2; }
	else if(data == "T3") { expected_transiton_number = 3; }
	else if(data == "T4") { expected_transiton_number = 4; }
	else if(data == "T5") { expected_transiton_number = 5; }
	else if(data == "T6") { expected_transiton_number = 6; }
	else if(data == "T7") { expected_transiton_number = 7; }
	else if(data == "T8") { expected_transiton_number = 8; }
	else if(data == "T9") { expected_transiton_number = 9; }
	else if(data == "T10") { expected_transiton_number = 10; }
	else if(data == "T11") { expected_transiton_number = 11; }
	else { FAIL() << "unknown Transition"; }
}

static void assert_state_and_transition(const string expected_state) {
	if(expected_state == "Inactive_0") {
		EXPECT_EQ(states.state, states.Inactive_0);
	}
	else if(expected_state == "Idle_1") {
		EXPECT_EQ(states.state, states.Idle_1);
	}
	else if(expected_state == "GetMessage_2") {
		EXPECT_EQ(states.state, states.GetMessage_2);
	}
	else if(expected_state == "CheckMessage_3") {
		EXPECT_EQ(states.state, states.CheckMessage_3);
	}
	else if(expected_state == "CreateMessage_4") {
		EXPECT_EQ(states.state, states.CreateMessage_4);
	}
	else {
		FAIL() << "unknown Result State";
	}
	EXPECT_EQ(transitions_mock->transition_number, expected_transiton_number);
}

THEN("^Result State is (.+)$") {
	REGEX_PARAM(string, expected_state);
	(void)expected_state;

	if(event == "-") {
		states.state->tick(guard);
	}
	else if(event == "MH_Conf_ACTIVE") {
		states.state->MH_Conf_ACTIVE();
	}
	else if(event == "MH_Conf_INACTIVE") {
		states.state->MH_Conf_INACTIVE();
	}
	else if(event == "tm(MaxCycleTime)") {
		states.state->tm_event();
	}
	else if(event == "tm(MaxUARTframeTime)") {
		states.state->tm_event();
	}
	else if(event == "PL_Transfer_req") {
		states.state->PL_Transfer_req(42);
	}
	else if(event == "PL_Transfer_ind") {
		states.state->PL_Transfer_ind(42);
	}
	else {
		FAIL() << "unknown event";
	}
	assert_state_and_transition(expected_state);
}
