# language: en
Feature: OD state machine of the Master AL
	Scenario Outline: States
		Given State is <State>
		* Event is <Event>
		* Guard is <Guard>
		Then Transition is <Transition>
		And Result State is <Result State>

	Examples:
		| State                | Event                | Guard                                 | Transition | Result State         |

		#TODO: check if the steps are implemented correctly
		| OnReq_Idle_0         | AL_Service_Portx     | -                                     | T1         | Build_DL_Service_1   |
		# | OnReq_Idle_0         | AL_Abort_Portx       | -                                     | T17        | OnReq_Idle_0         |

		# | Build_DL_Service_1   | AL_Read              | Index <= 1                            | T3         | Await_DL_Param_cnf_2 |
		# | Build_DL_Service_1   | AL_Write             | Index = 1                             | T4         | Await_DL_Param_cnf_2 |
		# | Build_DL_Service_1   | AL_Write             | Index = 2 & Not_ISDU_flag             | T5         | Await_DL_Param_cnf_2 |
		# | Build_DL_Service_1   | AL_Read              | Index >= 2 & ISDU_flag                | T6         | Await_DL_ISDU_cnf_3  |
		# | Build_DL_Service_1   | AL_Write             | Index >= 2 & ISDU_flag                | T7         | Await_DL_ISDU_cnf_3  |
		# | Build_DL_Service_1   | AL_Write             | Index 0 & Subindex 16 & Not_ISDU_flag | T18        | Await_DL_Param_cnf_2 |

		# | Await_DL_Param_cnf_2 | AL_Service           | -                                     | T8         | Await_DL_Param_cnf_2 |
		# | Await_DL_Param_cnf_2 | AL_Abort             | -                                     | T9         | Build_AL_cnf_4       |
		# | Await_DL_Param_cnf_2 | DL_RWParam           | Octets_left                           | T10        | Await_DL_Param_cnf_2 |
		# | Await_DL_Param_cnf_2 | DL_ReadParam_cnf     | Reads completed                       | T13        | Build_AL_cnf_4       |
		# | Await_DL_Param_cnf_2 | DL_WriteParam_cnf    | Writes completed                      | T14        | Build_AL_cnf_4       |

		# | Await_DL_ISDU_cnf_3  | AL_Abort             | -                                     | T11        | Build_AL_cnf_4       |
		# | Await_DL_ISDU_cnf_3  | AL_Service           | -                                     | T12        | Await_DL_ISDU_cnf_3  |
		# | Await_DL_ISDU_cnf_3  | DL_ISDUTransport_cnf | -                                     | T15        | Build_AL_cnf_4       |

		# | Build_AL_cnf_4       | -                    | Service processed                     | T16        | Build_AL_cnf_4       |
