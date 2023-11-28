#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "../../components/Transitions.h"
#include "mocks/Timer_mocks.h"
#include "mocks/OD_handler_mock.h"
#include "mocks/PD_handler_mock.h"
#include "mocks/PL_Transfer_mock.h"

using namespace State_machine_of_the_Device_message_handler;

MaxUARTframeTime_timer_mock maxUARTframeTime_timer_mock;
MaxCycleTime_timer_mock maxCycleTime_timer_mock;

Administration* administration = new Administration(&maxUARTframeTime_timer_mock, &maxCycleTime_timer_mock);
OD_handler_mock od_handler_mock;
PD_handler_mock pd_handler_mock;
PL_Transfer_mock PL_Transfer_mock;
Transitions* transitions = new Transitions(administration, &od_handler_mock, &pd_handler_mock, &PL_Transfer_mock);


BEFORE() {
	maxUARTframeTime_timer_mock.reset();
	maxCycleTime_timer_mock.reset();
	od_handler_mock.reset();
	pd_handler_mock.reset();
	PL_Transfer_mock.reset();
}

GIVEN("^T1$") {
	transitions->T1();
}

THEN("^no action$") {
	//no action
}

GIVEN("^T2$") {
	transitions->T2();
}

THEN("^Start \"MaxUARTframeTime\" and \"MaxCycleTime\" when in OPERATE$") {
	EXPECT_TRUE(maxUARTframeTime_timer_mock.start_called);
	EXPECT_TRUE(maxCycleTime_timer_mock.start_called);
}

GIVEN("^T3$") {
	transitions->T3();
}

THEN("^Restart timer \"MaxUARTframeTime\"$") {
	EXPECT_TRUE(maxUARTframeTime_timer_mock.start_called);
}

GIVEN("^T4$") {
	transitions->T4();
}

THEN("^Reset timer \"MaxUARTframeTime\"$") {
	EXPECT_TRUE(maxUARTframeTime_timer_mock.stop_called);
}

GIVEN("^T5$") {
	transitions->T5();
}

THEN("^Invoke OD\\.ind and PD\\.ind service indications$") {
	EXPECT_TRUE(od_handler_mock.ind_called);
	EXPECT_TRUE(pd_handler_mock.ind_called);
}

GIVEN("^T6$") {
	transitions->T6();
}

THEN("^Compile and invoke PL_Transfer\\.rsp service response$") {
	EXPECT_TRUE(PL_Transfer_mock.rsp_called);
}