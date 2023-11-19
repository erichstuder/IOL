# language: en
Feature: State machine of the Device message handler
	Scenario Outline: States
		Given State is <State>
		#* Event is <Event>
		#* Guard is <Guard>
		#Then Transition is <Transition>
		#And Result State is <Result State>

	Examples:
		| State      | Event          | Guard | Transition | Result State |

		| Inactive_0 | MH_Conf_ACTIVE | -     | T1         | Idle_1       |
		
		# | OnReq_Idle_0         | AL_Abort_Portx       | - | T17        | OnReq_Idle_0 |
