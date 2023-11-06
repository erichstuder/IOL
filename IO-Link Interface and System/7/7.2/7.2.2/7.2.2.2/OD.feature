# language: en
# Feature: OD
# 	Scenario: Argument
# 		Given RWDirection is in the range {READ, WRITE}
# 		* ComChannel is in the range {DIAGNOSIS, PAGE, ISDU} as defined in Table A.1  TODO: define the enums there first
# 		* AddressCtrl is in the range {0..31}
# 		* Length is in the range {0..32}
# 		* Data is of type Octet string
# 		Then the Argument is passable range

# 	Scenario: Result Success
# 		Given the service executed successfully
# 		Then Data contains the read data values
# 		* Length contains the length of the received data package
# 		* Length is in range {0..32}

# 	Scenario: Result Fail
# 		Given the Service failed
# 		Then ErrorInfo is in the range {NO_COMM, STATE_CONFLICT}
