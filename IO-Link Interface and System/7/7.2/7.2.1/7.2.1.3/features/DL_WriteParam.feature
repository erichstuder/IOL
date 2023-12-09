# language: en
Feature: DL_WriteParam
	Scenario Outline: primitives
		Then <primitive> has Argument: <Argument>
		* <primitive> has Result: <Result>

	Examples:
		| primitive | Argument | Result |
		| .req      | yes      | no     |
		| .cnf      | no       | yes    |
		| .ind      | yes      | no     |

	Scenario: Argument
		Given Address is in the range of 16 to 31
		Then the Argument is in passable range

	# # Scenario: Result Success
	# # 	Given the service executed successfully
	# # 	Then Value contains the read Data parameter values

	# Scenario: Result Fail
	# 	Then ErrorInfo contains the error information NO_COMM and STATE_CONFLICT
