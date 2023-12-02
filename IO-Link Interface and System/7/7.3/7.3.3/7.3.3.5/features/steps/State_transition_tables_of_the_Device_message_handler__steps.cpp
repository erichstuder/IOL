#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "../../components/Transitions.h"
#include "mocks/Timer_mocks.h"
#include "mocks/OD_handler_mock.h"
#include "mocks/PD_handler_mock.h"
#include "mocks/PL_Transfer_mock.h"
#include "mocks/DL_mode_handler_mock.h"

using namespace State_machine_of_the_Device_message_handler;

MaxUARTframeTime_timer_mock maxUARTframeTime_timer_mock;
MaxCycleTime_timer_mock maxCycleTime_timer_mock;

Administration* administration = new Administration(&maxUARTframeTime_timer_mock, &maxCycleTime_timer_mock);
OD_handler_mock od_handler_mock;
PD_handler_mock pd_handler_mock;
PL_Transfer_mock pl_Transfer_mock;
DL_mode_handler_mock dl_mode_handler_mock;
Transitions* transitions = new Transitions(administration, &od_handler_mock, &pd_handler_mock, &pl_Transfer_mock, &dl_mode_handler_mock);


BEFORE() {
	maxUARTframeTime_timer_mock.reset_mock();
	maxCycleTime_timer_mock.reset_mock();
	od_handler_mock.reset_mock();
	pd_handler_mock.reset_mock();
	pl_Transfer_mock.reset_mock();
	dl_mode_handler_mock.reset_mock();
}

GIVEN("^T(\\d+)$") {
	REGEX_PARAM(int, transition_id);
	switch(transition_id) {
		case 1: transitions->T1(); break;
		case 2: transitions->T2(); break;
		case 3: transitions->T3(); break;
		case 4: transitions->T4(); break;
		case 5: transitions->T5(); break;
		case 6: transitions->T6(); break;
		case 7: transitions->T7(); break;
		case 8: transitions->T8(); break;
		case 9: transitions->T9(); break;
		case 10: transitions->T10(); break;
		case 11: transitions->T11(); break;
		default: FAIL() << "unknown transition id"; break;
	}
}

THEN("^no action$") {
	//no action
}

THEN("^Start \"MaxUARTframeTime\" and \"MaxCycleTime\" when in OPERATE.$") {
	EXPECT_TRUE(maxUARTframeTime_timer_mock.start_called);
	EXPECT_TRUE(maxCycleTime_timer_mock.start_called);
}

THEN("^Restart timer \"MaxUARTframeTime\".$") {
	EXPECT_TRUE(maxUARTframeTime_timer_mock.restart_called);
}

THEN("^Reset timer \"MaxUARTframeTime\".$") {
	EXPECT_TRUE(maxUARTframeTime_timer_mock.reset_called);
}

THEN("^Invoke OD\\.ind and PD\\.ind service indications$") {
	EXPECT_TRUE(od_handler_mock.ind_called);
	EXPECT_TRUE(pd_handler_mock.ind_called);
}

THEN("^Compile and invoke PL_Transfer\\.rsp service response$") {
	EXPECT_TRUE(pl_Transfer_mock.rsp_called);
}

THEN("^Indicate error to DL-mode handler via MHInfo \\(ILLEGAL_MESSAGETYPE\\)$") {
	EXPECT_TRUE(dl_mode_handler_mock.ind_called);
}

THEN("^Reset both timers \"MaxUARTframeTime\" and \"MaxCycleTime\"\\.$") {
	EXPECT_TRUE(maxUARTframeTime_timer_mock.reset_called);
	EXPECT_TRUE(maxCycleTime_timer_mock.reset_called);
}
