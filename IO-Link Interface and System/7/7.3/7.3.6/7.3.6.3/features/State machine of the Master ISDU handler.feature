# language: en
Feature: State machine of the Master ISDU handler
	Scenario Outline: States
		Given State is <State>	
		* Event is <Event>
		* Guard is <Guard>
		Then Transition is <Transition>
		And Result State is <Result State>

	Examples:
		| State          | Event            | Guard                  | Transition | Result State   |

		| Inactive_0     | IH_Conf_ACTIVE   | -                      | T1         | Idle_1         |

		| Idle_1         | ISDUTrig         | DL_ISDUTransport       | T2         | ISDURequest_2  |
		| Idle_1         | ISDUTrig         | ParamRequest           | T13        | Idle_1         |
		| Idle_1         | ISDUTrig         | -                      | T14        | Idle_1         |
		| Idle_1         | IH_Conf_INACTIVE | -                      | T16        | Inactive_0     |

		| ISDURequest_2  | ISDUTrig         | -                      | T3         | ISDURequest_2  |
		| ISDURequest_2  | -                | Data written           | T4         | ISDUWait_3     |
		| ISDURequest_2  | DL_Mode_COMLOST  | -                      | T12        | ISDUError_4    |
		| ISDURequest_2  | ISDUAbort        | -                      | T19        | ISDUError_4    |

		| ISDUWait_3     | ISDUTrig         | -                      | T5         | ISDUWait_3     |
		| ISDUWait_3     | -                | ResponseStart          | T6         | ISDUResponse_5 |
		| ISDUWait_3     | -                | Error                  | T9         | ISDUError_4    |
		| ISDUWait_3     | DL_ISDUAbort     | -                      | T17        | ISDUError_4    |

		| ISDUError_4    | ISDUTrig         | -                      | T11        | Idle_1         |
		| ISDUError_4    | IH_Conf_INACTIVE | -                      | T15        | Inactive_0     |

		| ISDUResponse_5 | ISDUTrig         | -                      | T7         | ISDUResponse_5 |
		| ISDUResponse_5 | ISDUTrig         | Transmission completed | T8         | Idle_1         |
		| ISDUResponse_5 | -                | Error                  | T10        | ISDUError_4    |
		| ISDUResponse_5 | DL_ISDUAbort     | -                      | T18        | ISDUError_4    |

	
	#Scenario: Transitions
