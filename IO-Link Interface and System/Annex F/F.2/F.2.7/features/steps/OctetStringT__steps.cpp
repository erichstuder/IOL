#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "OctetStringT.h"

using std::string;


THEN("^An OctetStringT is representing an ordered sequence of octets$") {
	const uint8_t Length = 42;
	OctetStringT octetString(Length);
	EXPECT_EQ(octetString.Length, Length);
}

THEN("^with a fixed length$") {
	//TODO: Any idea for a test?
}

THEN("^maximum of 232 octets$") {
	OctetStringT octetString(250);
	EXPECT_EQ(octetString.Length, 232);
}
