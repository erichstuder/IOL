# language: en
Feature: Table A.10 – M-sequence types for the OPERATE mode
	Scenario Outline: Validation
		Given OPERATE M-sequence code: <OPERATE M-sequence code>	
		* On-request Data Octets: <On-request Data Octets>
		* PDin: <PDin>
		* PDout: <PDout>
		* M-sequence type: <M-sequence type>
		Then the sequence type is valid for Table A.10

	Examples:
		| OPERATE M-sequence code | On-request Data Octets | PDin           | PDout          | M-sequence type |
		| 0                       | 1                      | 0              | 0              | TYPE_0          |
		| 1                       | 2                      | 0              | 0              | TYPE_1_2        |
		| 6                       | 8                      | 0              | 0              | TYPE_1_V        |
		| 7                       | 32                     | 0              | 0              | TYPE_1_V        |
		| 0                       | 1                      | 1…8 bit        | 0              | TYPE_2_1        |
		| 0                       | 1                      | 9…16 bit       | 0              | TYPE_2_2        |
		| 0                       | 1                      | 0              | 1…8 bit        | TYPE_2_3        |
		| 0                       | 1                      | 0              | 9…16 bit       | TYPE_2_4        |
		| 0                       | 1                      | 1…8 bit        | 1…8 bit        | TYPE_2_5        |
		| 0                       | 1                      | 9…16 bit       | 1…16 bit       | TYPE_2_V        |
		| 0                       | 1                      | 1…16 bit       | 9…16 bit       | TYPE_2_V        |
		| 4                       | 1                      | 0…32 octets    | 3…32 octets    | TYPE_2_V        |
		| 4                       | 1                      | 3…32 octets    | 0…32 octets    | TYPE_2_V        |
		| 5                       | 2                      | >0 bit, octets | ≥0 bit, octets | TYPE_2_V        |
		| 5                       | 2                      | ≥0 bit, octets | >0 bit, octets | TYPE_2_V        |
		| 6                       | 8                      | >0 bit, octets | ≥0 bit, octets | TYPE_2_V        |
		| 6                       | 8                      | ≥0 bit, octets | >0 bit, octets | TYPE_2_V        |
		| 7                       | 32                     | >0 bit, octets | ≥0 bit, octets | TYPE_2_V        |
		| 7                       | 32                     | ≥0 bit, octets | >0 bit, octets | TYPE_2_V        |
