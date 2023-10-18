# language: en
Feature: SM_SetDeviceCom

	Scenario: executed successfully
		Given SupportedSIOMode is in range INACTIVE, DI, DO
		* SupportedTransmissionrate is in range COM1, COM2, COM3
		* MinCycleTime is in range TBD
		* M-sequence Capability is in range ISDU, OPERATE, PREOPERATE
		* RevisionID (RID) is in range TBD
		* ProcessDataIn is in range TBD
		* ProcessDataOut is in range TBD
		When I use SM_SetDeviceCom
		Then SM_SetDeviceCom executes successfully

	Scenario: failed
		Given TBD
		When I use SM_SetDeviceCom
		Then SM_SetDeviceCom fails with PARAMETER_CONFLICT
