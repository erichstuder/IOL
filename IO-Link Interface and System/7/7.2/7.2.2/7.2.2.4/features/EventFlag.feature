# language: en
Feature: EventFlag
	Scenario Outline: primitives
		Then <primitive> has Argument: <Argument>

	Examples:
		| primitive | Argument |
		| .ind      | yes      |
		| .req      | yes      |


	Scenario: Argument
		Given Flag is TRUE or FALSE
		Then the Argument is passable range
