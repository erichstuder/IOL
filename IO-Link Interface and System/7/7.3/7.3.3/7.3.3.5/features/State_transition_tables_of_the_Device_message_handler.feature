# language: en
Feature: State machine of the Device message handler
	Scenario: T1
		Given T1
		Then no action

	Scenario: T2
		Given T2
		Then Start "MaxUARTframeTime" and "MaxCycleTime" when in OPERATE.

	Scenario: T3
		Given T3
		Then Restart timer "MaxUARTframeTime".

	Scenario: T4
		Given T4
		Then Reset timer "MaxUARTframeTime".

	Scenario: T5
		Given T5
		Then Invoke OD.ind and PD.ind service indications

	Scenario: T6
		Given T6
		Then Compile and invoke PL_Transfer.rsp service response

	Scenario: T7
		Given T7
		Then no action

	Scenario: T8
		Given T8
		Then Indicate error to DL-mode handler via MHInfo (ILLEGAL_MESSAGETYPE)

	Scenario: T9
		Given T9
		Then Reset both timers "MaxUARTframeTime" and "MaxCycleTime".

	Scenario: T10
		Given T10
		# Then Indicate error to actuator technology that shall observe this information
		# And take corresponding actions (see 10.2 and 10.8.3).

	Scenario: T11
		Given T11
		Then no action
		# Note: The mentioned action in the specification just illustrates the state transition which is not done here
