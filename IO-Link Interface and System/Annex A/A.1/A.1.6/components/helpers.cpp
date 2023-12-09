#include "helpers.h"

namespace Calculation_of_the_checksum__private {
	uint8_t XOR_processing(uint8_t* data, uint8_t length) {
		const uint8_t Seed = 0x52;
		uint8_t result_8_bit = Seed;

		for(auto n=0; n<length; n++) {
			result_8_bit ^= data[n];	
		}

		return result_8_bit;
	}

	uint8_t compress_to_6_bit(uint8_t result_8_bit) {
		bool bit_0;
		bool bit_1;
		bool bit_2;
		bool bit_3;
		bool bit_4;
		bool bit_5;

		bit_0 = (result_8_bit      & 0x01) ^ (result_8_bit >> 1 & 0x01);
		bit_1 = (result_8_bit >> 2 & 0x01) ^ (result_8_bit >> 3 & 0x01);
		bit_2 = (result_8_bit >> 4 & 0x01) ^ (result_8_bit >> 5 & 0x01);
		bit_3 = (result_8_bit >> 6 & 0x01) ^ (result_8_bit >> 7 & 0x01);

		bit_4 = (result_8_bit      & 0x01) ^ (result_8_bit >> 2 & 0x01) ^ (result_8_bit >> 4 & 0x01) ^ (result_8_bit >> 6 & 0x01);
		bit_5 = (result_8_bit >> 1 & 0x01) ^ (result_8_bit >> 3 & 0x01) ^ (result_8_bit >> 5 & 0x01) ^ (result_8_bit >> 7 & 0x01);

		uint8_t result_6_bit = 0x00;
		result_6_bit |= bit_0;
		result_6_bit |= bit_1 << 1 ;
		result_6_bit |= bit_2 << 2;
		result_6_bit |= bit_3 << 3 ;
		result_6_bit |= bit_4 << 4 ;
		result_6_bit |= bit_5 << 5 ;

		return result_6_bit;
	}
}