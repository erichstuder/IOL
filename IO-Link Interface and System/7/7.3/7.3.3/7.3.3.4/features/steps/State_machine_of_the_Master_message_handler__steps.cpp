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
		void T40() override { transition_number = 40; }
		void T41() override { transition_number = 41; }

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
	else if(data == "AwaitReply_4") {
		states.state = states.AwaitReply_4;
	}
	else if(data == "ErrorHandling_5") {
		states.state = states.ErrorHandling_5;
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
	else if(data == "AwaitReply_9") {
		states.state = states.AwaitReply_9;
	}
	else if(data == "ErrorHandling_10") {
		states.state = states.ErrorHandling_10;
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
	else if(data == "AwaitReply_16") {
		states.state = states.AwaitReply_16;
	}
	else if(data == "ErrorHandling_17") {
		states.state = states.ErrorHandling_17;
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
	else if(data == "No error") {
		guard = State_Interface::Guard::No_error;
	}
	else if(data == "Retry < MaxRetry") {
		guard = State_Interface::Guard::Retry_less_than_MaxRetry;
	}
	else if(data == "Retry = MaxRetry") {
		guard = State_Interface::Guard::Retry_equals_MaxRetry;
	}
	else if(data == "Not Idle") {
		guard = State_Interface::Guard::Not_Idle;
	}
	else if(data == "Idle") {
		guard = State_Interface::Guard::Idle;
	}
	else if(data == "Tcyc") {
		guard = State_Interface::Guard::Tcyc;
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
	else if(expected_state == "AwaitReply_4") {
		EXPECT_EQ(states.state, states.AwaitReply_4);
	}
	else if(expected_state == "ErrorHandling_5") {
		EXPECT_EQ(states.state, states.ErrorHandling_5);
	}
	else if(expected_state == "Preoperate_6") {
		EXPECT_EQ(states.state, states.Preoperate_6);
	}
	else if(expected_state == "GetOD_7") {
		EXPECT_EQ(states.state, states.GetOD_7);
	}
	else if(expected_state == "Response_8") {
		EXPECT_EQ(states.state, states.Response_8);
	}
	else if(expected_state == "AwaitReply_9") {
		EXPECT_EQ(states.state, states.AwaitReply_9);
	}
	else if(expected_state == "ErrorHandling_10") {
		EXPECT_EQ(states.state, states.ErrorHandling_10);
	}
	else if(expected_state == "CheckHandler_11") {
		EXPECT_EQ(states.state, states.CheckHandler_11);
	}
	else if(expected_state == "Operate_12") {
		EXPECT_EQ(states.state, states.Operate_12);
	}
	else if(expected_state == "GetPD_13") {
		EXPECT_EQ(states.state, states.GetPD_13);
	}
	else if(expected_state == "GetOD_14") {
		EXPECT_EQ(states.state, states.	GetOD_14);
	}
	else if(expected_state == "Response_15") {
		EXPECT_EQ(states.state, states.Response_15);
	}
	else if(expected_state == "AwaitReply_16") {
		EXPECT_EQ(states.state, states.AwaitReply_16);
	}
	else if(expected_state == "ErrorHandling_17") {
		EXPECT_EQ(states.state, states.ErrorHandling_17);
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
		states.state->MH_Conf_COMx(COMx::COM1);
	}
	else if(event == "MH_Conf_PREOPERATE") {
		states.state->MH_Conf_PREOPERATE();
	}
	else if(event == "MH_Conf_OPERATE") {
		states.state->MH_Conf_OPERATE();
	}
	else if(event == "MH_Conf_INACTIVE") {
		states.state->MH_Conf_INACTIVE();
	}
	else if(event == "MH_Conf_Startup") {
		states.state->MH_Conf_Startup();
	}
	else if(event == "tm(TM-sequence)") {
		states.state->tm_event();
	}
	else if(event == "tm(Tinitcyc)") {
		states.state->tm_event();
	}
	else if(event == "tm(Tcyc)") {
		states.state->tm_event();
	}
	else if(event == "DL_Read") {
		DL_Read::Argument_type Argument;
		states.state->DL_Read_req(&Argument);
	}
	else if(event == "DL_Write") {
		DL_Write::Argument_type Argument;
		states.state->DL_Write_req(&Argument);
	}
	else if(event == "DL_ReadParam") {
		DL_ReadParam::Argument_type Argument;
		states.state->DL_ReadParam_req(&Argument);
	}
	else if(event == "DL_WriteParam") {
		DL_WriteParam::Argument_type Argument;
		states.state->DL_WriteParam_req(&Argument);
	}
	else if(event == "DL_ISDUTransport") {
		DL_ISDUTransport::Argument_type Argument;
		states.state->DL_ISDUTransport_req(&Argument);
	}
	else if(event == "EventFlag") {
		EventFlag::Argument_type Argument;
		states.state->EventFlag_req(&Argument);
	}
	else {
		FAIL() << "unknown event";
	}
	assert_state_and_transition(expected_state);
}

THEN("^MH_Conf_COMx accepts a transmission rate of COM3, COM2, COM1$") {
	States::State_Base state(NULL, NULL, NULL);
	state.MH_Conf_COMx(COMx::COM1);
	state.MH_Conf_COMx(COMx::COM2);
	state.MH_Conf_COMx(COMx::COM3);
	(void)state;
}
