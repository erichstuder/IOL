# language: en
Feature: Calculation of the checksum
	Scenario: checksum
		Given the checksum is calculated
		Then the Seed is 0x52
		* every byte is XOR processed
		* the result is compressed from 8 to 6

	Scenario Outline: compression to 6 bit
		Then bit <Bit of 6 bit> = XOR of <Bits of 8 bit> 

	Examples:
		| Bit of 6 bit | Bits of 8 bit |
		| 0            | 0,1           |
		| 1            | 2,3           |
		| 2            | 4,5           |
		| 3            | 6,7           |
		| 4            | 0,2,4,6       |
		| 5            | 1,3,5,7       |
