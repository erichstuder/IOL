#pragma once

#include "components/States.h"
#include "components/Transitions.h"

namespace State_machine_of_the_Device_message_handler {
	class State_machine_of_the_Device_message_handler {
		public:
			void MH_Conf_ACTIVE();
		private:
			Transitions* transitions;
			States* states;
			//States::State* state;
	};
}
