# language: en
Feature: State transition tables of the Master ISDU handler
	Scenario: T1
		When T1
		Then no Action

	# Scenario: T2
	# 	When T2
	# 	Then Invoke OD.req with ISDU write start condition: OD.req (W, ISDU, flowCtrl = START, data)

	# Scenario: T3
	# 	When T3
	# 	Then Invoke OD.req with ISDU data write and FlowCTRL under conditions of Table 52

	# Scenario: T4
	# 	When T4
	# 	Then Start timer (ISDUTime)

	# Scenario: T5
	# 	When T5
	# 	Then Invoke OD.req with ISDU read start condition: OD.req (R, ISDU, flowCtrl = START)

	# Scenario: T6
	# 	When T6
	# 	Then Stop timer (ISDUTime)

	# Scenario: T7
	# 	When T7
	# 	Then Invoke OD.req with ISDU data read and FlowCTRL under conditions of Table 52

	# Scenario: T8
	# 	When T8
	# 	Then OD.req (R, ISDU, flowCtrl = IDLE) Invoke positive DL_ISDUTransport confirmation

	# Scenario: T9
	# 	When T9
	# 	Then no Action

	# Scenario: T10
	# 	When T10
	# 	Then no Action

	# Scenario: T11
	# 	When T11
	# 	Then Invoke OD.req with ISDU abortion: OD.req (R, ISDU, flowCtrl = ABORT).
	# 	* Invoke negative DL_ISDUTransport confirmation

	# Scenario: T12
	# 	When T12
	# 	Then no Action

	# Scenario: T13
	# 	When T13
	# 	Then Invoke OD.req with appropriate data.
	#	* Invoke positive DL_ReadParam/DL_WriteParam confirmation

	# Scenario: T14
	# 	When T14
	#	Then Invoke OD.req with idle message: OD.req (R, ISDU, flowCtrl = IDLE)

	# Scenario: T15
	# 	When T15
	#	Then In case of lost communication, the message handler informs the DL_Mode handler which in turn uses the administrative call IH_Conf_INACTIVE.
	# 	* No actions during this transition required.

	# Scenario: T16
	# 	When T16
	# 	Then no Action

	# Scenario: T17
	# 	When T17
	# 	Then no Action

	# Scenario: T18
	# 	When T18
	# 	Then no Action

	# Scenario: T19
	# 	When T19
	# 	Then no Action
