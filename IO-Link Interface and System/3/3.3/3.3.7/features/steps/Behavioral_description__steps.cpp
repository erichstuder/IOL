#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "Behavioral_description.h"
#include "ITimer.h"

using std::string;

class Behavioral_description_mock: public Behavioral_description {
	public:
		void tm_event() {}
};

class Timer_mock: public ITimer {
	public:
		void start() {}

		void stop() {}
};

Behavioral_description_mock behavioral_mock;
Timer_mock timer_mock;

THEN("^Timing constraints are labelled \"tm\\(time in ms\\)\"$") {
	timer_mock.start();
	timer_mock.stop();
	behavioral_mock.tm_event();
}
