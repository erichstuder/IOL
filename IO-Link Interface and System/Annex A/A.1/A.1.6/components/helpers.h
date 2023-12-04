#pragma once

#include "cstdint"

namespace Calculation_of_the_checksum__private {
	uint8_t XOR_processing(uint8_t* data, uint8_t length);
	uint8_t compress_to_6_bit(uint8_t result_8_bit);
}
