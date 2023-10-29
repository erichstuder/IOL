# language: en
Feature: 9.3.2.2 SM_SetDeviceCom
	Scenario: Argument
		# Note:
		# This test only checks if the parameters can be passed to the service
		# it is not checked if they are also accepted.
		Given SupportedSIOMode is in range {INACTIVE, DI, DO}
		* SupportedTransmissionrate is in range {COM1, COM2, COM3}
		* MinCycleTime has any value
		* M-sequence Capability is in range {ISDU, OPERATE, PREOPERATE}
		* RevisionID (RID) has any value
		* ProcessDataIn has any value
		* ProcessDataOut has any value
		Then the Arguments are in passable range

	Scenario: Result
		Then the Result can only have the values SUCCESS and PARAMETER_CONFLICT		
