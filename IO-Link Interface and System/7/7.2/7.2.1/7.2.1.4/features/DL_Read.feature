# language: en
Feature: DL_Read
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
		Given Address is in the range 0 to 15
		Then the Argument is in passable range

	Scenario: Result Success
		Given the service executed successfully
		# Then the parameter Value contains read Device parameter values (TBD: don't know how to test yet)

	Scenario: Result Fail
		Given the service failed
		Then the parameter ErrorInfo contains error information
		* ErrorInfo has the values NO_COMM or STATE_CONFLICT
