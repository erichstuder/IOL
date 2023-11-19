#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "Behavioral_description.h"

using std::string;

class Behavioral_description_mock: public Behavioral_description {
	public:
		void tm(float time_ms) {
			(void)time_ms;
		}
};

Behavioral_description_mock mock;

/*THEN("^State is (.+)$") {
	REGEX_PARAM(string, data);
	if(data == "Inactive_0") {
		states.state = states.Inactive_0;
	}
	else if(data == "Idle_1") {
		states.state = states.Idle_1;
	}
	else {
		FAIL() << "unknown State";
	}
}*/

THEN("^Timing constraints are labelled \"tm\\(time in ms\\)\"$") {
	mock.tm(23.1582);
}
