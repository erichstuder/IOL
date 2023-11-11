#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "DL_ISDUTransport.h"

using std::string;

//using namespace State_machine_of_the_Master_ISDU_handler;

static uint16_t Index_min;
static uint16_t Index_max;

static uint8_t Subindex_min;
static uint8_t Subindex_max;

DL_ISDUTransport dL_ISDUTransport;

THEN("^\\.req has Argument: yes") {
	DL_ISDUTransport::Argument_type Argument;
	dL_ISDUTransport.req(Argument);
}

THEN("^\\.ind has Argument: yes") {
	DL_ISDUTransport::Argument_type Argument;
	dL_ISDUTransport.ind(Argument);
}

THEN("^\\.rsp has Argument: no") {
	dL_ISDUTransport.rsp();
}

THEN("^\\.cnf has Argument: no") {
	dL_ISDUTransport.cnf();
}

THEN("^\\.req has Result: no$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.ind has Result: no$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.rsp has Result: yes$") {
	DL_ISDUTransport::Result_type dummy = dL_ISDUTransport.rsp();
	(void)dummy;
}

THEN("^\\.cnf has Result: yes$") {
	DL_ISDUTransport::Result_type dummy = dL_ISDUTransport.cnf();
	(void)dummy;
}

GIVEN("^Index is in the range of 2 to 65535$") {
    Index_min = 2;
    Index_max = 65535;
}

GIVEN("^Subindex is in the range of 0 t 255$") {
    Subindex_min = 0;
    Subindex_max = 255;
}


GIVEN("^Data is of type Octet string$") {
	DL_ISDUTransport::Argument_type Argument;
	Argument.Data = new OctetStringT(23);
	(void)Argument;
}

GIVEN("^Direction is READ or WRITE$") {
	EXPECT_TRUE((int)DL_ISDUTransport::Direction_type::READ >= 0);
	EXPECT_TRUE((int)DL_ISDUTransport::Direction_type::WRITE >= 0);
	EXPECT_EQ((int)DL_ISDUTransport::Direction_type::_cnt, 2);
}

THEN("^the Argument is in passable range$") {
	DL_ISDUTransport::Argument_type Argument;
	Argument.Data = new OctetStringT(23);
	Argument.Direction = DL_ISDUTransport::Direction_type::WRITE;

	Argument.Index = Index_min;
	Argument.Subindex = Subindex_min;
	dL_ISDUTransport.req(Argument);
	dL_ISDUTransport.ind(Argument);

	Argument.Index = Index_max;
	Argument.Subindex = Subindex_max;
	dL_ISDUTransport.req(Argument);
	dL_ISDUTransport.ind(Argument);
}
