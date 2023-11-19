#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "../../components/Transitions.h"

using std::string;

using namespace State_machine_of_the_Master_ISDU_handler;

Transitions transitions;

unsigned int transition_id;


GIVEN("^T(\\d+)$") {
	REGEX_PARAM(unsigned int, data);
	transition_id = data;
}

THEN("^no Action$") {
	//no Action
}

/*THEN("^Invoke OD.req with ISDU write start condition: OD.req (W, ISDU, flowCtrl = START, data)$") {
	
}*/
