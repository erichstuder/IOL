# language: en
Feature: PDInStatus
	Scenario Outline: primitives
		Then <primitive> has Argument: <Argument>

	Examples:
		| primitive | Argument |
		| .req      | yes      |
		| .ind      | yes      |


	Scenario: Argument
		Given Status is VALID or INVALID
		Then the Argument is in passable range
