# language: en
# Feature: AL_Read
# 	Scenario: Argument
# 		Given Port is in the range of Unsigned8
# 		* Index is in the range of 0 to 65535
# 		* Subindex is in the range of 0 t 255
# 		Then the Argument is in passable range

# 	Scenario: Index and Subindex are 0
# 		Given Index is 0
# 		* Subindex is 0
# 		Then the entire set of Direct Parameters from 0 to 15 is addressed
# 		* the page communication channel is used

# 	Scenario: Index is 0 and Subindex is in the range 1 to 16
# 		Given Index is 0
# 		* Subindex is in the range 1 to 16
# 		Then individual parameters from 0 to 15 are addressed
# 		* the page communication channel is used

# 	Scenario: Index is 1 and Subindex is 0
# 		Given Index is 1
# 		* Subindex is 0
# 		Then the entire set of Direct Parameters from 16 to 31 is addressed
# 		* the page communication channel is used

# 	Scenario: Index is 1 and Subindex is in the range 16 to 31
# 		Given Index is 1
# 		* Subindex is in the range 1 to 16
# 		Then individual parameters from 16 to 31 are addressed
# 		* the page communication channel is used

# 	Scenario: ISDU communication channel
# 		Given Index is >=2
# 		Then the ISDU communication channel is used

# 	Scenario: Subindex is not 0
# 		Given Subindex is not 0
# 		Then an element within a structured On-request Data object is indicated

# 	Scenario: Subindex is 0
# 		Given Subindex is 0
# 		Then the entire set of elements is indicated

# 	Scenario: Result Success
# 		Given the service executed successfully
# 		Then the parameter Port contains the port number of the requested On-request Data
# 		* the parameter Data contains the read values of the On-request Data
# 		* the parameter Data is of type Octet string

# 	Scenario: Result Fail
# 		Given the service failed
# 		Then the parameter Port contains the port number of the requested On-request Data
# 		* the parameter ErrorInfo contains error information
