# language: en
Feature: PDTrig
	Scenario Outline: primitives
		Then <primitive> has Argument: <Argument>

	Examples:
		| primitive | Argument |
		| .ind      | yes      |


	Scenario: Argument
		Given DataLength
		Then the Argument is in passable range
