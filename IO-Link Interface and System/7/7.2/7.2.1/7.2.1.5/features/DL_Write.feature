# language: en
Feature: DL_Read
	Scenario Outline: primitives
		Then <primitive> has Argument: <Argument>
		* <primitive> has Result: <Result>

	Examples:
		| primitive | Argument | Result |
		| .req      | yes      | no     |
		| .cnf      | no       | yes    |
		| .ind      | yes      | no     |


	Scenario: Argument
		Given Address is in the range 0 to 15
		* Value contains the Device parameter to be written
		Then the Argument is in passable range

	Scenario: Result Success
		Given the service executed successfully

	Scenario: Result Fail
		Given the service failed
		Then the parameter ErrorInfo contains error information
		* ErrorInfo has the values NO_COMM or STATE_CONFLICT
