#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

//#include "9.3.2.2 SM_SetDeviceCom.h"

static unsigned int Index_min;
static unsigned int Index_max;

GIVEN("^the Index is >1$") {
    Index_min = 2;
    Index_max = 255; //TBD: what ist the maximum?
}

WHEN("^the AL_Read service is executed on the Master$") {
    for(auto Index = Index_min; Index <= Index_max; Index++) {
    	//AL_Read.req(Index);
    }
    FAIL() << "implement me";
}
