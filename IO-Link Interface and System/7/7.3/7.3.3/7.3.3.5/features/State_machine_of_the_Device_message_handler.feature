# language: en
Feature: State machine of the Device message handler
	Scenario Outline: States
		Given State is <State>
		* Event is <Event>
		* Guard is <Guard>
		Then Transition is <Transition>
		And Result State is <Result State>

	Examples:
		| State      | Event             | Guard | Transition | Result State |

		| Inactive_0 | MH_Conf_ACTIVE    | -     | T1         | Idle_1       |
		
		| Idle_1     | PL_Transfer_ind   | -     | T2         | GetMessage_2 |
		| Idle_1     | tm(MaxCycleTime)  | -     | T10        | Idle_1       |
		| Idle_1     | MH_Conf_INACTIVE  | -     | T11        | Inactive_0   |
