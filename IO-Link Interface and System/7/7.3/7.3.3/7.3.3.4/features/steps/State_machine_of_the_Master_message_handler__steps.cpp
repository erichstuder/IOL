#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "../../components/States.h"

using std::string;

using namespace State_machine_of_the_Master_message_handler;

class Transitions_mock: public Transitions_Interface {
	public:
		// using Transitions_Interface::Transitions_Interface;

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
		void T12() override { transition_number = 12; }
		void T13() override { transition_number = 13; }
		void T14() override { transition_number = 14; }
		void T15() override { transition_number = 15; }
		void T16() override { transition_number = 16; }
		void T17() override { transition_number = 17; }
		void T18() override { transition_number = 18; }
		void T19() override { transition_number = 19; }
		void T20() override { transition_number = 20; }
		void T21() override { transition_number = 21; }
		void T22() override { transition_number = 22; }
		void T23() override { transition_number = 23; }
		void T24() override { transition_number = 24; }
		void T25() override { transition_number = 25; }
		void T26() override { transition_number = 26; }
		void T27() override { transition_number = 27; }
		void T28() override { transition_number = 28; }
		void T29() override { transition_number = 29; }
		void T30() override { transition_number = 30; }
		void T31() override { transition_number = 31; }
		void T32() override { transition_number = 32; }
		void T33() override { transition_number = 33; }
		void T34() override { transition_number = 34; }
		void T35() override { transition_number = 35; }
		void T36() override { transition_number = 36; }
		void T37() override { transition_number = 37; }
		void T38() override { transition_number = 38; }
		void T39() override { transition_number = 39; }

		unsigned int transition_number;

		void reset() {
			transition_number = 0;
		}
};

static Administration* administration = new Administration();
static Transitions_mock* transitions_mock = new Transitions_mock();
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
	else if(data == "AwaitReply_1") {
		states.state = states.AwaitReply_1;
	}
	else if(data == "Startup_2") {
		states.state = states.Startup_2;
	}
	else if(data == "Response_3") {
		states.state = states.Response_3;
	}
	else if(data == "Preoperate_6") {
		states.state = states.Preoperate_6;
	}
	else if(data == "GetOD_7") {
		states.state = states.GetOD_7;
	}
	else if(data == "Response_8") {
		states.state = states.Response_8;
	}
	else if(data == "CheckHandler_11") {
		states.state = states.CheckHandler_11;
	}
	else if(data == "Operate_12") {
		states.state = states.Operate_12;
	}
	else if(data == "GetPD_13") {
		states.state = states.GetPD_13;
	}
	else if(data == "GetOD_14") {
		states.state = states.GetOD_14;
	}
	else if(data == "Response_15") {
		states.state = states.Response_15;
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
	else if(data == "Response OK") {
		guard = State_Interface::Guard::Response_OK;
	}
	else if(data == "Response not OK") {
		guard = State_Interface::Guard::Response_not_OK;
	}
	else {
		FAIL() << "unknown Guard";
	}
}

THEN("^Transition is T(\\d+)$") {
	REGEX_PARAM(int, transition_id);
	expected_transiton_number = transition_id;
}

static void assert_state_and_transition(const string expected_state) {
	if(expected_state == "Inactive_0") {
		EXPECT_EQ(states.state, states.Inactive_0);
	}
	else if(expected_state == "AwaitReply_1") {
		EXPECT_EQ(states.state, states.AwaitReply_1);
	}
	else if(expected_state == "Startup_2") {
		EXPECT_EQ(states.state, states.Startup_2);
	}
	else if(expected_state == "Response_3") {
		EXPECT_EQ(states.state, states.Response_3);
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
	else if(event == "MH_Conf_COMx") {
		states.state->MH_Conf_COMx();
	}
	else if(event == "tm(TM-sequence)") {
		states.state->tm_event();
	}
	else if(event == "DL_Read") {
		states.state->DL_Read();
	}
	else {
		FAIL() << "unknown event";
	}
	assert_state_and_transition(expected_state);
}

/*
#include "mocks/OD_handler_mock.h"
#include "mocks/PD_handler_mock.h"
#include "mocks/PL_Transfer_mock.h"
#include "mocks/DL_mode_handler_mock.h"

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
*/