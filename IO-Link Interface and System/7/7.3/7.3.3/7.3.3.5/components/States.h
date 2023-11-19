#pragma once

#include "ITransitions.h"

namespace State_machine_of_the_Device_message_handler {
	class States {
		public:
			/*enum class Event {  //TODO: vermutlich kann das weg
				dummy
			};*/

			enum class Guard {
				NoGuard
			};

			class State {
				public:
					State(States* states, ITransitions* transitions);
					virtual State* tick(Guard guard) = 0;

					void MH_Conf_ACTIVE();
				protected:
					States* states;
					ITransitions* transitions;
			};

			State* const Inactive_0;
			State* const Idle_1;
			State* const GetMessage_2;
			State* const CheckMessage_3;
			State* const CreateMessage_4;
			State* state;

			States(ITransitions* transitions);
	};
}
