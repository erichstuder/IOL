# language: en
Feature: State machine of the Master message handler
	Scenario Outline: States
		Given State is <State>
		* Event is <Event>
		* Guard is <Guard>
		Then Transition is <Transition>
		And Result State is <Result State>

	Examples:
		| State           | Event               | Guard            | Transition | Result State    |

		| Inactive_0      | MH_Conf_COMx        | -                | T1         | AwaitReply_1    |

		| AwaitReply_1    | -                   | Response OK      | T2         | Startup_2       |
		| AwaitReply_1    | -                   | Response not OK  | T3         | Inactive_0      |
		| AwaitReply_1    | tm(TM-sequence)     | -                | T4         | Inactive_0      |

		| Startup_2       | DL_Read             | -                | T5         | Response_3      |
		| Startup_2       | DL_Write            | -                | T6         | Response_3      |
		| Startup_2       | MH_Conf_PREOPERATE  | -                | T12        | Preoperate_6    |
		| Startup_2       | MH_Conf_OPERATE     | -                | T39        | Operate_12      |

		| Response_3      | -                   | No error         | T10        | Startup_2       |
		| Response_3      | -                   | Retry = MaxRetry | T11        | Inactive_0      |

		| Preoperate_6    | DL_ReadParam        | -                | T13        | GetOD_7         |
		| Preoperate_6    | DL_WriteParam       | -                | T14        | GetOD_7         |
		| Preoperate_6    | DL_ISDUTransport    | -                | T15        | GetOD_7         |
		| Preoperate_6    | EventFlag           | -                | T16        | GetOD_7         |
		| Preoperate_6    | DL_Write_DEVICEMODE | -                | T17        | GetOD_7         |
		| Preoperate_6    | MH_Conf_PREOPERATE  | -                | T26        | Operate_12      |
		| Preoperate_6    | MH_Conf_INACTIVE    | -                | T36        | Inactive_0      |
		| Preoperate_6    | MH_Conf_Startup     | -                | T37        | Startup_2       |

		| GetOD_7         | OD                  | Tinitcyc         | T18        | Response_8      |

		| Response_8      | -                   | Retry = MaxRetry | T22        | Inactive_0      |
		| Response_8      | -                   | No error         | T23        | CheckHandler_11 |

		| CheckHandler_11 | -                   | Not Idle         | T24        | GetOD_7         |
		| CheckHandler_11 | -                   | Idle             | T25        | Preoperate_6    |

		| Operate_12      | -                   | Tcyc             | T27        | GetPD_13        |
		| Operate_12      | MH_Conf_INACTIVE    | -                | T35        | Inactive_0      |
		| Operate_12      | MH_Conf_Startup     | -                | T38        | Startup_2       |

		| GetPD_13        | PD                  | -                | T28        | GetOD_14        |

		| GetOD_14        | OD                  | -                | T29        | Response_15     |

		| Response_15     | -                   | Retry = MaxRetry | T33        | Inactive_0      |
		| Response_15     | -                   | No error         | T34        | Operate_12      |
