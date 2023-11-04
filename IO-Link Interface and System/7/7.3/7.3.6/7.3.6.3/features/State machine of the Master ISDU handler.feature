# language: en
Feature: State machine of the Master ISDU handler
	Scenario Outline: States
		Given State is <State>	
		* Event is <Event>
		* Guard is <Guard>
		Then Transition is <Transition>
		And Result State is <Result State>

	Examples:
		| State         | Event           | Guard            | Transition | Result State  |
		| Inactive_0    | IH_Conf_ACTIVE  | -                | T1         | Idle_1        |
		# | Idle_1        | ISDUTrig        | DL_ISDUTransport | T2         | ISDURequest_2 |
		# | Idle_1        | ISDUTrig        | ParamRequest     | T13        | Idle_1        |
		# | Idle_1        | ISDUTrig        | -                | T14        | Idle_1        |
		# | ISDURequest_2 | -               | Data written     | T4         | ISDUWait_3    |
		# | ISDURequest_2 | ISDUTrig        | -                | T3         | ISDURequest_2 |
		# | ISDURequest_2 | ISDUTrig        | -                | T19        | ISDU_Error_4  |
		# | ISDURequest_2 | DL_Mode_COMLOST | -                | T12        | ISDU_Error_4  |
		#more
	
	#Scenario: Transitions
