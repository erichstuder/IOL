#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "AL_Read.h"

using std::string;

class AL_Read_mock: public AL_Read {
	public:
		void AL_Read_req(uint8_t Port, uint16_t Index, uint8_t Subindex) {
			(void)Port;
			(void)Index;
			(void)Subindex;
		}

		void AL_Read_ind(uint16_t Index, uint8_t Subindex) {
			(void)Index;
			(void)Subindex;
		}

		Result_type AL_Read_rsp() {
			return Result_type(42);
		}
		
		Result_type AL_Read_cnf() {
			return Result_type(14);
		}
};

AL_Read_mock service_mock;

THEN("^\\.req has Argument: Port, Index, Subindex$") {
	service_mock.AL_Read_req(1, 2, 3);
}

THEN("^\\.req has Result: -$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.ind has Argument: Index, Subindex$") {
	service_mock.AL_Read_ind(1, 2);
}

THEN("^\\.ind has Result: -$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.rsp has Argument: -$") {
	service_mock.AL_Read_rsp();
}

THEN("^\\.rsp has Result: Data$") {
	AL_Read_mock::Result_type result = service_mock.AL_Read_rsp();
	(void)result.Data;
}

THEN("^\\.cnf has Argument: -$") {
	service_mock.AL_Read_cnf();
}

THEN("^\\.cnf has Result: Port, Data, ErrorInfo$") {
	AL_Read_mock::Result_type result = service_mock.AL_Read_cnf();
	(void)result.Port;
	(void)result.Data;
	(void)result.ErrorInfo;
}


