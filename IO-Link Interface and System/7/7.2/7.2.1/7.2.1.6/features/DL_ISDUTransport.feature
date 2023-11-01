# language: en
Feature: DL_ISDUTransport
	Scenario: Argument
		Given Index is in the range of 0 to 65535
		* Subindex is in the range of 0 t 255
		* Data is of type Octet string
		* Direction is READ or WRITE
		Then the Argument is in passable range

	Scenario: Result Success
		Given the service executed successfully
		Then the parameter Data an Octet string
		* the parameter Qualifier contains an I-Service Device response

	Scenario: Result Fail
		Given the service failed
		Then the parameter ISDUTransportErrorInfo contains error information
		* ISDUTransportErrorInfo has the permitted values NO_COMM, STATE_CONFLICT, ISDU_TIMEOUT, ISDU_NOT_SUPPORTED, VALUE_OUT_OF_RANGE
