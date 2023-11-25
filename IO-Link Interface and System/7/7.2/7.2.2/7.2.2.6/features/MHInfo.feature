# language: en
Feature: MHInfo
	Scenario Outline: primitives
		Then <primitive> has Argument: <Argument>

	Examples:
		| primitive | Argument |
		| .ind      | yes      |


	Scenario: Argument
		Given MHInfo is COMLOST, ILLEGAL_MESSAGETYPE or CHECKSUM_MISMATCH
		Then the Argument is in passable range
