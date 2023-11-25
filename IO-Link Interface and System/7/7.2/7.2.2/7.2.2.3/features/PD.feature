# language: en
Feature: PD
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
		Given PDInAddress
		* PDInLength is 0 to 32
		* PDOut is an Octet string
		* PDOutAddress
		* PDOutLength is 0 to 32
		Then the Argument is passable range

	Scenario: Result Success
		Given the service executed successfully
		Then PDIn contains the Process Data to be transferred from the device
		* PDIn is an Octet string

	Scenario: Result Fail
		Given the Service failed
		Then ErrorInfo is in the range {NO_COMM, STATE_CONFLICT}