# language: en
Feature: PL_Transfer
	Scenario Outline: primitives
		Then <primitive> has Argument: <Argument>
		* <primitive> has Result: <Result>

	Examples:
		| primitive | Argument | Result |
		| .req      | Data     | -      |
		| .ind      | Data     | Status |

	Scenario: Argument
		Given Data is in the range of 0...255
		Then the Argument is in passable range

	Scenario: Result
		Then Status has the possible value SUCCESS, PARITY_ERROR, FRAMING_ERROR or OVERRUN
