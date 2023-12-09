#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "MHInfo_ind.h"

class MHInfo_mock: MHInfo_ind__Interface {
	public:
		void MHInfo_ind(MHInfo::Argument_type Argument) override {
			(void)Argument;
		}
};


MHInfo_mock mhInfo;

THEN("^\\.ind has Argument: yes$") {
	MHInfo::Argument_type argument;
	mhInfo.MHInfo_ind(argument);
}

GIVEN("^MHInfo is COMLOST, ILLEGAL_MESSAGETYPE or CHECKSUM_MISMATCH$") {
	MHInfo::Argument_type argument;
	(void)argument;
	argument.MHInfo = MHInfo::MHInfo_type::COMLOST;
	argument.MHInfo = MHInfo::MHInfo_type::ILLEGAL_MESSAGETYPE;
	argument.MHInfo = MHInfo::MHInfo_type::CHECKSUM_MISMATCH;
	EXPECT_EQ((int)MHInfo::MHInfo_type::_cnt, 3);
}

THEN("^the Argument is in passable range$") {
	MHInfo::Argument_type argument;
	argument.MHInfo = MHInfo::MHInfo_type::ILLEGAL_MESSAGETYPE;
	mhInfo.MHInfo_ind(argument);
}
