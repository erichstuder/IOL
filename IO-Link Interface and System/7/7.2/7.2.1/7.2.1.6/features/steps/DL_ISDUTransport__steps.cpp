#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "DL_ISDUTransport_req.h"
#include "DL_ISDUTransport_ind.h"
#include "DL_ISDUTransport_cnf.h"
#include "DL_ISDUTransport_rsp.h"

using namespace DL_ISDUTransport;

class DL_ISDUTransport_mock:
	public DL_ISDUTransport_req__Interface,
	public DL_ISDUTransport_ind__Interface,
	public DL_ISDUTransport_cnf__Interface,
	public DL_ISDUTransport_rsp__Interface
{
	public:
		void DL_ISDUTransport_req(Argument_type* Argument) override {
			(void)Argument;
		}

		void DL_ISDUTransport_ind(Argument_type* Argument) override {
			(void)Argument;
		}

		Result_type DL_ISDUTransport_cnf() override {
			Result_type result(5);
			return result;
		}

		Result_type DL_ISDUTransport_rsp() override {
			Result_type result(4);
			return result;
		}
};


static uint16_t Index_min;
static uint16_t Index_max;

static uint8_t Subindex_min;
static uint8_t Subindex_max;

DL_ISDUTransport_mock dL_ISDUTransport_mock;

THEN("^\\.req has Argument: yes") {
	Argument_type Argument;
	dL_ISDUTransport_mock.DL_ISDUTransport_req(&Argument);
}

THEN("^\\.ind has Argument: yes") {
	Argument_type Argument;
	dL_ISDUTransport_mock.DL_ISDUTransport_ind(&Argument);
}

THEN("^\\.rsp has Argument: no") {
	dL_ISDUTransport_mock.DL_ISDUTransport_rsp();
}

THEN("^\\.cnf has Argument: no") {
	dL_ISDUTransport_mock.DL_ISDUTransport_cnf();
}

THEN("^\\.req has Result: no$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.ind has Result: no$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.rsp has Result: yes$") {
	Result_type dummy = dL_ISDUTransport_mock.DL_ISDUTransport_rsp();
	(void)dummy;
}

THEN("^\\.cnf has Result: yes$") {
	Result_type dummy = dL_ISDUTransport_mock.DL_ISDUTransport_cnf();
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
	Argument_type Argument;
	Argument.Data = new OctetStringT(23);
	(void)Argument;
}

GIVEN("^Direction is READ or WRITE$") {
	Argument_type Argument;
	(void)Argument;
	Argument.Direction = Direction_type::READ;
	Argument.Direction = Direction_type::WRITE;
	EXPECT_EQ((int)Direction_type::_cnt, 2);
}

THEN("^the Argument is in passable range$") {
	Argument_type Argument;
	Argument.Data = new OctetStringT(23);
	Argument.Direction = Direction_type::WRITE;

	Argument.Index = Index_min;
	Argument.Subindex = Subindex_min;
	dL_ISDUTransport_mock.DL_ISDUTransport_req(&Argument);
	dL_ISDUTransport_mock.DL_ISDUTransport_ind(&Argument);

	Argument.Index = Index_max;
	Argument.Subindex = Subindex_max;
	dL_ISDUTransport_mock.DL_ISDUTransport_req(&Argument);
	dL_ISDUTransport_mock.DL_ISDUTransport_ind(&Argument);
}

GIVEN("^the service executed successfully$") {
	Result_type result(18);
	result.ISDUTransportErrorInfo = ISDUTransportErrorInfo_type::SUCCESS;
	(void)result;
}

THEN("^the parameter Data is an Octet string$") {
	Result_type result(99);
	result.Data = new OctetStringT(50);
	(void)result;
}

THEN("^the parameter Qualifier contains an I-Service Device response$") {
	//TODO: test is pending
}

GIVEN("^the service failed$") {
	//nothing to test
}

THEN("^the parameter ISDUTransportErrorInfo contains error information$") {
	Result_type result(33);
	(void)result.ISDUTransportErrorInfo; 
}

THEN("^ISDUTransportErrorInfo has the permitted values NO_COMM, STATE_CONFLICT, ISDU_TIMEOUT, ISDU_NOT_SUPPORTED, VALUE_OUT_OF_RANGE$") {
	Result_type result(88);
	(void)result;
	result.ISDUTransportErrorInfo = ISDUTransportErrorInfo_type::SUCCESS;
	result.ISDUTransportErrorInfo = ISDUTransportErrorInfo_type::NO_COMM;
	result.ISDUTransportErrorInfo = ISDUTransportErrorInfo_type::STATE_CONFLICT;
	result.ISDUTransportErrorInfo = ISDUTransportErrorInfo_type::ISDU_TIMEOUT;
	result.ISDUTransportErrorInfo = ISDUTransportErrorInfo_type::ISDU_NOT_SUPPORTED;
	result.ISDUTransportErrorInfo = ISDUTransportErrorInfo_type::VALUE_OUT_OF_RANGE;
	EXPECT_EQ((int)ISDUTransportErrorInfo_type::_cnt, 6);
}
