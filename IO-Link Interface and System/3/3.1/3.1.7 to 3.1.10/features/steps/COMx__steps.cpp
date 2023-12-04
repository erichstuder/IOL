#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "COMx.h"

THEN("^COMx allows COM1, COM2, COM3$") {
	COMx com;
	(void)com;
	com = COMx::COM1;
	com = COMx::COM2;
	com = COMx::COM3;
	EXPECT_EQ((int)COMx::_cnt, 3);
}
