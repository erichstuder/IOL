#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "OD_state_machine_of_the_Master_AL.h"

using std::string;

using namespace OD_state_machine_of_the_Master_AL;

class Transitions_mock: public ITransitions {
	public:
		void T1() { transition_number = 1; }
		void T2() { transition_number = 2; }
		void T3() { transition_number = 3; }
		void T4() { transition_number = 4; }
		void T5() { transition_number = 5; }
		void T6() { transition_number = 6; }
		void T7() { transition_number = 7; }
		void T8() { transition_number = 8; }
		void T9() { transition_number = 9; }
		void T10() { transition_number = 10; }
		void T11() { transition_number = 11; }
		void T12() { transition_number = 12; }
		void T13() { transition_number = 13; }
		void T14() { transition_number = 14; }
		void T15() { transition_number = 15; }
		void T16() { transition_number = 16; }
		void T17() { transition_number = 17; }
		void T18() { transition_number = 18; }

		unsigned int transition_number;

		void reset() {
			transition_number = 0;
		}
};

static Transitions_mock* transitions_mock = new Transitions_mock();
static States states(transitions_mock);
static States::State* initial_state;
static unsigned int expected_transiton_number;
static string event;

uint16_t Index_min;
uint16_t Index_max;


BEFORE() {
	transitions_mock->reset();
}

GIVEN("^State is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "OnReq_Idle_0") {
		initial_state = states.OnReq_Idle_0;
	}
	else if(data == "Build_DL_Service_1") {
		initial_state = states.Build_DL_Service_1;
	}
	/*else if(data == "ISDURequest_2") {
		state = states.ISDURequest_2;
	}
	else if(data == "ISDUWait_3") {
		state = states.ISDUWait_3;
	}
	else if(data == "ISDUError_4") {
		state = states.ISDUError_4;
	}
	else if(data == "ISDUResponse_5") {
		state = states.ISDUResponse_5;
	}*/
	else {
		FAIL() << "unknown State";
	}
}

GIVEN("^Event is (.+)$") {
	//there_is_an_event = true;
	REGEX_PARAM(string, data);
	event = data;
	/*if(data == "AL_Service_Portx") {
		event = States::Event::AL_Service_Portx;
	}
	else if(data == "AL_Abort_Portx") {
		event = States::Event::AL_Abort_Portx;
	}
	else if(data == "AL_Read") {
		event = States::Event::AL_Read;
	}
	else if(data == "DL_Mode_COMLOST") {
		event = States::Event::DL_Mode_COMLOST;
	}
	else if(data == "ISDUAbort") {
		event = States::Event::ISDUAbort;
	}
	else if(data == "DL_ISDUAbort") {
		event = States::Event::DL_ISDUAbort;
	}
	else if(data == "-") {
		there_is_an_event = false;
	}
	else {
		FAIL() << "unknown event";
	}*/
}

GIVEN("^Guard is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "-") {
		//guard = States::Guard::NoGuard;
	}
	else if(data == "Index <= 1") {
		//guard = States::Guard::NoGuard;
		Index_min = 0;
		Index_max = 1;
	}
	/*else if(data == "ParamRequest") {
		guard = States::Guard::ParamRequest;
	}
	else if(data == "Data written") {
		guard = States::Guard::Data_written;
	}
	else if(data == "ResponseStart") {
		guard = States::Guard::ResponseStart;
	}
	else if(data == "Error") {
		guard = States::Guard::Error;
	}
	else if(data == "Transmission completed") {
		guard = States::Guard::Transmission_completed;
	}*/
	else {
		FAIL() << "unknown Guard";
	}
}

GIVEN("^Transition is (.+)$") {
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
	else if(data == "T12") { expected_transiton_number = 12; }
	else if(data == "T13") { expected_transiton_number = 13; }
	else if(data == "T14") { expected_transiton_number = 14; }
	else if(data == "T15") { expected_transiton_number = 15; }
	else if(data == "T16") { expected_transiton_number = 16; }
	else if(data == "T17") { expected_transiton_number = 17; }
	else if(data == "T18") { expected_transiton_number = 18; }
	else { FAIL() << "unknown Transition"; }
}

static void assert_state_and_transition(const string expected_state) {
	if(expected_state == "OnReq_Idle_0") {
		EXPECT_EQ(states.state, states.OnReq_Idle_0);
	}
	else if(expected_state == "Build_DL_Service_1") {
		EXPECT_EQ(states.state, states.Build_DL_Service_1);
	}
	else if(expected_state == "Await_DL_Param_cnf_2") {
		EXPECT_EQ(states.state, states.Await_DL_Param_cnf_2);
	}
	else if(expected_state == "Await_DL_ISDU_cnf_3") {
		EXPECT_EQ(states.state, states.Await_DL_ISDU_cnf_3);
	}
	else if(expected_state == "Build_AL_cnf_4") {
		EXPECT_EQ(states.state, states.Build_AL_cnf_4);
	}
	else {
		FAIL() << "unknown Result State";
	}
	EXPECT_EQ(transitions_mock->transition_number, expected_transiton_number);
}

THEN("^Result State is (.+)$") {
	REGEX_PARAM(string, expected_state);

	if(event == "-") {
		// TODO:what todo? result_state = state->handle_event(event, guard);
	}
	else if(event == "AL_Read") {
		for(auto index = Index_min; index <= Index_max; index++) {
			states.state = initial_state;
			states.state->AL_Read_req(0, index, 0);
			assert_state_and_transition("expected_state");
		}
	}
}
