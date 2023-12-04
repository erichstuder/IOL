#include "Calculation_of_the_checksum.h"
#include "components/helpers.h"

using namespace Calculation_of_the_checksum__private;

uint8_t calculate_6_bit_checksum(uint8_t* data, uint8_t length)
{
	uint8_t result_8_bit = XOR_processing(data, length);
	return compress_to_6_bit(result_8_bit);
}
