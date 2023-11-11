#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "DL_ISDUTransport.h"

using std::string;

//using namespace State_machine_of_the_Master_ISDU_handler;

static uint16_t Index_min;
static uint16_t Index_max;

//static uint8_t Subindex_min;
//static uint8_t Subindex_max;


GIVEN("^Index is in the range of 2 to 65535$") {
    Index_min = 2;
    Index_max = 65535;
}

/*GIVEN("^Subindex is in the range of 0 t 255$") {
    Subindex_min = 0;
    Subindex_max = 255;
}*/
/*
GIVEN("^Data is of type Octet string$") {
	//OD::Argument_type Argument;
	//Argument.Data = new OctetStringT(23);
	//(void)Argument;
}*/
