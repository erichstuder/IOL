# language: en
Feature: State machine of the Device message handler
	Scenario: T1
		Given T1
		Then no action

	Scenario: T2
		Given T2
		Then Start "MaxUARTframeTime" and "MaxCycleTime" when in OPERATE

	Scenario: T3
		Given T3
		Then Restart timer "MaxUARTframeTime"

	Scenario: T4
		Given T4
		Then Reset timer "MaxUARTframeTime"

	Scenario: T5
		Given T5
		Then Invoke OD.ind and PD.ind service indications
