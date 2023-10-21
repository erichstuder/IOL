# language: en
#Feature: SM_SetDeviceCom
#	Scenario: executed successfully
#		Given SupportedSIOMode is in range {INACTIVE, DI, DO}
#		* SupportedTransmissionrate is in range {COM1, COM2, COM3}
#		* MinCycleTime is in range {0.4:0.1:6.3, 6.4:0.4:31.6, 32:1.6:132.8} [ms]
#		* M-sequence Capability is in range {ISDU, OPERATE, PREOPERATE}
#		* RevisionID (RID) is in range {0:63}.{0:63}
#		* ProcessDataIn is in range BYTE{true,false}, SIO{0,1}, Length{0:16|BYTE=false, 3:32|BYTE=true}
#		* ProcessDataOut is in range BYTE{true,false}, Length{0:16|BYTE=false, 3:32|BYTE=true}
#		When I use SM_SetDeviceCom
#		Then SM_SetDeviceCom executes successfully
#
#	Scenario: failed
#		Given TBD
#		When I use SM_SetDeviceCom
#		Then SM_SetDeviceCom fails with PARAMETER_CONFLICT
#
#	Scenario: SupportedSIOMode
		
