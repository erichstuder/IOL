# language: en
# Feature: Figure 61 – Sequence diagram for the transmission of On-request Data
# 	Scenario: Read Parameter via ISDU
# 		Given the Index is >1
# 		When the AL_Read service is executed on the Master
# 		Then the DL_ISDUTransport service is executed on the Master
# 		* the Message is transmitted to the Device
# 		* the DL_ISDUTransport service is executed on the Device
# 		* the AL_Read service is executed on the Device
# 		* a Parameter via ISDU is read from the Device

# 	Scenario: Read Direct Parameter page 0 or 1
# 		Given the Index is 0 or 1
# 		When the AL_Read service is executed on the Master
# 		Then the DL_ISDUTransport service is executed on the Master
# 		* the Message is transmitted to the Device
# 		* the DL_ISDUTransport service is executed on the Device
# 		* the AL_Read service is executed on the Device
# 		* a Direct Parameter is read from the Device
