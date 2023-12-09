#pragma once

#include "components/States.h"

namespace State_machine_of_the_Device_message_handler {
	class State_machine_of_the_Device_message_handler: public State_Interface {
		public:
			void tick(Guard guard) override;

			void tm_event() override;

			void PL_Transfer_req(uint8_t Data) override;
			PL_Transfer::Status PL_Transfer_ind(uint8_t Data) override;
			void PL_Transfer_rsp() override;
		private:
			//Transitions* transitions;
			//States* states;
			//States::State* state;
	};
}
