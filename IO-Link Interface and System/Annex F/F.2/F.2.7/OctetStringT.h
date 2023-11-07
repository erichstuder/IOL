# pragma once

#include <cstdint>

struct OctetStringT{
	uint8_t Length;
	uint8_t* sequence;
	OctetStringT(uint8_t length) : Length(length > 232 ? 232 : length), sequence(new uint8_t[this->Length]) { }
};
