#include "State_machine_of_the_Device_message_handler.h"

namespace State_machine_of_the_Device_message_handler {
	void State_machine_of_the_Device_message_handler::tick(Guard guard) {(void)guard;}

	void State_machine_of_the_Device_message_handler::tm_event() {}

	void State_machine_of_the_Device_message_handler::PL_Transfer_req(uint8_t Data) {(void)Data;}
	PL_Transfer::Status State_machine_of_the_Device_message_handler::PL_Transfer_ind(uint8_t Data) {(void)Data; return PL_Transfer::Status::SUCCESS;}
	void State_machine_of_the_Device_message_handler::PL_Transfer_rsp() {}
}
