# language: en
Feature: State_machine_of_the_Master_message_handler__Submachines
	Scenario Outline: Submachine "Response 3" of the message handler
		Given State is <State>
		* Event is <Event>
		* Guard is <Guard>
		Then Transition is <Transition>
		And Result State is <Result State>

	Examples:
		| State           | Event           | Guard            | Transition | Result State    |

		| AwaitReply_4    | -               | -                | enex_2     | -               |
		| AwaitReply_4    | tm(TM-sequence) | -                | T7         | ErrorHandling_5 |
		| AwaitReply_4    | -               | Response not OK  | T8         | ErrorHandling_5 |

		| ErrorHandling_5 | -               | -                | enex_1     | -               |
		| ErrorHandling_5 | tm(Tinitcyc)    | Retry < MaxRetry | T9         | AwaitReply_4    |


	Scenario Outline: Submachine "Response 8" of the message handler
		Given State is <State>
		* Event is <Event>
		* Guard is <Guard>
		Then Transition is <Transition>
		And Result State is <Result State>

	Examples:
		| State            | Event           | Guard            | Transition | Result State     |

		| AwaitReply_9     | -               | -                | enex_4     | -                |
		| AwaitReply_9     | tm(TM-sequence) | -                | T19        | ErrorHandling_10 |
		| AwaitReply_9     | -               | Response not OK  | T20        | ErrorHandling_10 |

		| ErrorHandling_10 | -               | -                | enex_3     | -                |
		| ErrorHandling_10 | tm(Tinitcyc)    | Retry < MaxRetry | T21        | AwaitReply_9     |


	Scenario Outline: Submachine "Response 15" of the message handler
		Given State is <State>
		* Event is <Event>
		* Guard is <Guard>
		Then Transition is <Transition>
		And Result State is <Result State>

	Examples:
		| State            | Event           | Guard            | Transition | Result State     |

		| AwaitReply_16    | -               | -                | enex_6     | -                |
		| AwaitReply_16    | tm(TM-sequence) | -                | ?          | ErrorHandling_17 |
		| AwaitReply_16    | -               | Response not OK  | ?          | ErrorHandling_17 |

		| ErrorHandling_17 | -               | -                | enex_5     | -                |
		| ErrorHandling_17 | tm(Tcyc)        | Retry < MaxRetry | T32        | AwaitReply_16    |
