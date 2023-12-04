#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "Calculation_of_the_checksum.h"
#include "../../components/helpers.h"

GIVEN("^the checksum is calculated$") {
	uint8_t dummy[42];
	uint8_t result = calculate_6_bit_checksum(dummy, 0);
	(void)result;
}

THEN("^the Seed is 0x52$") {
	uint8_t result = Calculation_of_the_checksum__private::XOR_processing(NULL, 0);
	EXPECT_EQ(result, 0x52);
}

THEN("^every byte is XOR processed$") {
	uint8_t data[] = {0xFF, 0x01};
	uint8_t result = Calculation_of_the_checksum__private::XOR_processing(data, sizeof(data));
	EXPECT_EQ(result, 0xAC);
}

THEN("^the result is compressed from 8 to 6$") {
	uint8_t result_6_bit = Calculation_of_the_checksum__private::compress_to_6_bit(0xFF);
	EXPECT_EQ(result_6_bit & 0xC0, 0x00);
}

THEN("^bit 0 = XOR of 0,1$") {
	uint8_t result;
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x00);
	EXPECT_EQ(result & 0x0F, 0x00);
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x01);
	EXPECT_EQ(result & 0x0F, 0x01);
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x02);
	EXPECT_EQ(result & 0x0F, 0x01);
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x03);
	EXPECT_EQ(result & 0x0F, 0x00);
}

THEN("^bit 1 = XOR of 2,3$") {
	uint8_t result;
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x01 << 2);
	EXPECT_EQ(result & 0x0F, 0x02);
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x02 << 2);
	EXPECT_EQ(result & 0x0F, 0x02);
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x03 << 2);
	EXPECT_EQ(result & 0x0F, 0x00);
}

THEN("^bit 2 = XOR of 4,5$") {
	uint8_t result;
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x01 << 4);
	EXPECT_EQ(result & 0x0F, 0x04);
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x02 << 4);
	EXPECT_EQ(result & 0x0F, 0x04);
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x03 << 4);
	EXPECT_EQ(result & 0x0F, 0x00);
}

THEN("^bit 3 = XOR of 6,7$") {
	uint8_t result;
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x01 << 6);
	EXPECT_EQ(result & 0x0F, 0x08);
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x02 << 6);
	EXPECT_EQ(result & 0x0F, 0x08);
	
	result = Calculation_of_the_checksum__private::compress_to_6_bit(0x03 << 6);
	EXPECT_EQ(result & 0x0F, 0x00);
}

THEN("^bit 4 = XOR of 0,2,4,6$") {
	const uint8_t Combination_Count = 16;
	const uint8_t Truthtable[Combination_Count][2] = {
		{ 0x00, 0},
		{ 0x01, 1},
		{ 0x04, 1},
		{ 0x05, 0},
		{ 0x10, 1},
		{ 0x11, 0},
		{ 0x14, 0},
		{ 0x15, 1},
		{ 0x40, 1},
		{ 0x41, 0},
		{ 0x44, 0},
		{ 0x45, 1},
		{ 0x50, 0},
		{ 0x51, 1},
		{ 0x54, 1},
		{ 0x55, 0}
	};

	uint8_t result;
	for(auto n=0; n<Combination_Count; n++) {
		result = Calculation_of_the_checksum__private::compress_to_6_bit(Truthtable[n][0]);
		EXPECT_EQ(result & 0x10, Truthtable[n][1]<<4) << "n: " << n;
	}
}

THEN("^bit 5 = XOR of 1,3,5,7$") {
	const uint8_t Combination_Count = 16;
	const uint8_t Truthtable[Combination_Count][2] = {
		{ 0x00, 0},
		{ 0x02, 1},
		{ 0x08, 1},
		{ 0x0A, 0},
		{ 0x20, 1},
		{ 0x22, 0},
		{ 0x28, 0},
		{ 0x2A, 1},
		{ 0x80, 1},
		{ 0x82, 0},
		{ 0x88, 0},
		{ 0x8A, 1},
		{ 0xA0, 0},
		{ 0xA2, 1},
		{ 0xA8, 1},
		{ 0xAA, 0}
	};

	uint8_t result;
	for(auto n=0; n<Combination_Count; n++) {
		result = Calculation_of_the_checksum__private::compress_to_6_bit(Truthtable[n][0]);
		EXPECT_EQ(result & 0x20, Truthtable[n][1]<<5) << "n: " << n;
	}
}
