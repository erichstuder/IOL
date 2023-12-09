# language: en
Feature: Table A.9 – M-sequence types for the OPERATE mode (legacy protocol)
	Scenario Outline: Validation
		Given OPERATE M-sequence code: <OPERATE M-sequence code>	
		* On-request Data Octets: <On-request Data Octets>
		* PDin: <PDin>
		* PDout: <PDout>
		* M-sequence type: <M-sequence type>
		Then the sequence type is valid for Table A.9

	Examples:
		| OPERATE M-sequence code | On-request Data Octets | PDin        | PDout       | M-sequence type |
		| 0                       | 1                      | 0           | 0           | TYPE_0          |
		| 1                       | 2                      | 0           | 0           | TYPE_1_2        |
		| don't care              | 2                      | 3…32 octets | 0…32 octets | TYPE_1_1/1_2    |
		| don't care              | 2                      | 0…32 octets | 3…32 octets | TYPE_1_1/1_2    |
		| don't care              | 1                      | 1…8 bit     | 0           | TYPE_2_1        |
		| don't care              | 1                      | 9…16 bit    | 0           | TYPE_2_2        |
		| don't care              | 1                      | 0           | 1…8 bit     | TYPE_2_3        |
		| don't care              | 1                      | 0           | 9…16 bit    | TYPE_2_4        |
		| don't care              | 1                      | 1…8 bit     | 1…8 bit     | TYPE_2_5        |
