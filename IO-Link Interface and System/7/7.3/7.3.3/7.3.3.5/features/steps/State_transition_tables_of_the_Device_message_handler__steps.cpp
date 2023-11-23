#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "../../components/Transitions.h"
#include "../../components/Administration.h"

using std::string;

using namespace State_machine_of_the_Device_message_handler;

class MaxUARTframeTime_timer_mock: public ITimer {
	public:
		void start() override {
			start_called = true;
		}

		void stop() override {
			stop_called = true;
		}

		void reset() {
			start_called = false;
			stop_called = false;
		}

		bool start_called;
		bool stop_called;

};

class MaxCycleTime_timer_mock: public ITimer {
	public:
		void start() override {
			start_called = true;
		}

		void stop() override {
			stop_called = true;
		}

		void reset() {
			start_called = false;
			stop_called = false;
		}

		bool start_called;
		bool stop_called;

};

MaxUARTframeTime_timer_mock maxUARTframeTime_timer_mock;
MaxCycleTime_timer_mock maxCycleTime_timer_mock;

Administration* administration = new Administration(&maxUARTframeTime_timer_mock, &maxCycleTime_timer_mock);
Transitions* transitions = new Transitions(administration);


BEFORE() {
	maxUARTframeTime_timer_mock.reset();
	maxCycleTime_timer_mock.reset();
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
	pending();
}

