# language: en
Feature: State machine of the Device message handler
	Scenario Outline: States
		Given State is <State>
		* Event is <Event>
		* Guard is <Guard>
		Then Transition is <Transition>
		And Result State is <Result State>

	Examples:
		| State           | Event                | Guard                           | Transition | Result State    |

		| Inactive_0      | MH_Conf_ACTIVE       | -                               | T1         | Idle_1          |
		
		| Idle_1          | PL_Transfer_ind      | -                               | T2         | GetMessage_2    |
		| Idle_1          | tm(MaxCycleTime)     | -                               | T10        | Idle_1          |
		| Idle_1          | MH_Conf_INACTIVE     | -                               | T11        | Inactive_0      |

		| GetMessage_2    | PL_Transfer_req      | -                               | T3         | GetMessage_2    |
		| GetMessage_2    | -                    | Completed                       | T4         | CheckMessage_3  |
		| GetMessage_2    | tm(MaxUARTframeTime) | -                               | T9         | Idle_1          |

		| CheckMessage_3  | -                    | No error                        | T5         | CreateMessage_4 |
		| CheckMessage_3  | -                    | ChecksumError                   | T7         | Idle_1          |
		| CheckMessage_3  | -                    | TypeError and not ChecksumError | T8         | Idle_1          |

		| CreateMessage_4 | -                    | Ready                           | T6         | Idle_1          |
