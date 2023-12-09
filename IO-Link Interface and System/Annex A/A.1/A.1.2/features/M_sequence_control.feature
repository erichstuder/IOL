# language: en
Feature: M-sequence control (MC)
	# Scenario: M-sequence control (MC)
	# 	Then the size of the M-sequence control (MC) is 1 octet
	# 	* Bit 0 to 4 are the Address
	# 	* Bit 5 to 6 are the Communication channel
	# 	* Bit 7 is R/W

	# Scenario: Address
	# 	Then the Address is {0..31}

	Scenario: Communication channel
		Then the values of the communication channel are {Process, Page, Diagnosis, ISDU}
		#TODO: the following steps depent on the actual usage of the byte (see: above)
		#* Process has value 0
		#* Page has value 1
		#* Diagnosis has value 2
		#* ISDU has value 3

	# Scenario: R/W
	# 	Then the values of R/W are {Write, Read}
