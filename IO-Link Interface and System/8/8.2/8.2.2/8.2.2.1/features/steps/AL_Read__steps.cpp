#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "AL_Read.h"

using std::string;

class AL_Read_mock: public AL_Read {
	public:
		void req(uint8_t Port, uint16_t Index, uint8_t Subindex) {
			(void)Port;
			(void)Index;
			(void)Subindex;
		}

		void ind(uint16_t Index, uint8_t Subindex) {
			(void)Index;
			(void)Subindex;
		}

		Result_type rsp() {
			return Result_type(42);
		}
		
		Result_type cnf() {
			return Result_type(14);
		}
};

AL_Read_mock al_read_mock;

THEN("^\\.req has Argument: Port, Index, Subindex$") {
	al_read_mock.req(1, 2, 3);
}

THEN("^\\.req has Result: -$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.ind has Argument: Index, Subindex$") {
	al_read_mock.ind(1, 2);
}

THEN("^\\.ind has Result: -$") {
	//TODO: any idea to test for a void return value?
}

THEN("^\\.rsp has Argument: -$") {
	al_read_mock.rsp();
}

THEN("^\\.rsp has Result: Data$") {
	AL_Read_mock::Result_type result = al_read_mock.rsp();
	(void)result.Data;
}

THEN("^\\.cnf has Argument: -$") {
	al_read_mock.cnf();
}

THEN("^\\.cnf has Result: Port, Data, ErrorInfo$") {
	AL_Read_mock::Result_type result = al_read_mock.cnf();
	(void)result.Port;
	(void)result.Data;
	(void)result.ErrorInfo;
}


