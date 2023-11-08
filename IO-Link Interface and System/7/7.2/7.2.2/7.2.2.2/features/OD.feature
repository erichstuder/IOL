# language: en
Feature: OD
	Scenario Outline: primitives
		Then <primitive> has Argument: <Argument>
		* <primitive> has Result: <Result>

	Examples:
		| primitive | Argument | Result |
		| .req      | yes      | no     |
		| .ind      | yes      | no     |
		| .rsp      | no       | yes    |
		| .cnf      | no       | yes    |


	Scenario: Argument
		Given RWDirection is in the range {READ, WRITE}
		* ComChannel is in the range {DIAGNOSIS, PAGE, ISDU}
		* AddressCtrl is in the range {0..31}
		* Length is in the range {0..32}
		* Data is of type Octet string
		Then the Argument is passable range

	# Scenario: Result Success
	# 	Given the service executed successfully
	# 	Then Data contains the read data values
	# 	* Length contains the length of the received data package
	# 	* Length is in range {0..32}

	# Scenario: Result Fail
	# 	Given the Service failed
	# 	Then ErrorInfo is in the range {NO_COMM, STATE_CONFLICT}
