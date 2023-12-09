#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "M_sequence_control.h"

using std::string;

using namespace M_sequence_control;

THEN("^the size of the M-sequence control \\(MC\\) is 1 octet$") {
	//TODO: implementation according to how it is used
}

THEN("^the Address is \\{0\\.\\.31\\}$") {
	//TODO: implementation according to how it is used
}


THEN("^the values of the communication channel are \\{Process, Page, Diagnosis, ISDU\\}$") {
	EXPECT_TRUE((unsigned int)Communication_channel::Process >= 0);
	EXPECT_TRUE((unsigned int)Communication_channel::Page >= 0);
	EXPECT_TRUE((unsigned int)Communication_channel::Diagnosis >= 0);
	EXPECT_TRUE((unsigned int)Communication_channel::ISDU >= 0);
	EXPECT_TRUE((unsigned int)Communication_channel::_cnt == 4);
}

/*
THEN("^Process has value 0$") {
    pending();
}

THEN("^Page has value 1$") {
    pending();
}

THEN("^Diagnosis has value 2$") {
    pending();
}

THEN("^ISDU has value 3$") {
    pending();
}*/
