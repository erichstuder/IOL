# language: en
Feature: M-sequence types for the OPERATE mode (legacy protocol)
	Scenario Outline: M-Sequence type
		Given OPERATE M-sequence code: <OPERATE M-sequence code>	
		* On-request Data Octets: <On-request Data Octets>
		* PDin: <PDin>
		* PDout: <PDout>
		Then M-sequence type: <M-sequence type>

	Examples:
		| OPERATE M-sequence code | On-request Data Octets | PDin          | PDout         | M-sequence type |
		| 0                       | 1                      | 0             | 0             | TYPE_0          |
		| 1                       | 2                      | 0             | 0             | TYPE_1_2        |
		| x                       | 2                      | 3...32 octets | 0...32 octets | TYPE_1_1/1_2    |
		| x                       | 2                      | 0...32 octets | 3...32 octets | TYPE_1_1/1_2    |
		| x                       | 1                      | 1...8 bit     | 0             | TYPE_2_1        |
		| x                       | 1                      | 9...16 bit    | 0             | TYPE_2_2        |
		| x                       | 1                      | 0             | 1...8 bit     | TYPE_2_3        |
		| x                       | 1                      | 0             | 9...16 bit    | TYPE_2_4        |
		| x                       | 1                      | 1...8 bit     | 1...8 bit     | TYPE_2_5        |


	#Scenario: failed
		#Given TBD


#Feature: M-sequence types for the OPERATE mode
