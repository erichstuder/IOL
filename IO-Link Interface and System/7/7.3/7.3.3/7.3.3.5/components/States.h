#pragma once

#include "ITransitions.h"
#include "PL_Transfer.h"

namespace State_machine_of_the_Device_message_handler {
	class States {
		public:
			/*enum class Event {  //TODO: vermutlich kann das weg
				dummy
			};*/

			enum class Guard {
				NoGuard
			};

			class State: public PL_Transfer {
				public:
					State(States* states, ITransitions* transitions);
					virtual State* tick(Guard guard) = 0;
					virtual void entry() {};

					void MH_Conf_ACTIVE();
					void MH_Conf_INACTIVE();

					void PL_Transfer_req(uint8_t Data);
					Status PL_Transfer_ind(uint8_t Data);
				protected:
					States* states;
					ITransitions* transitions;
			};

			State* const Inactive_0;
			State* const Idle_1;
			State* const GetMessage_2;
			State* const CheckMessage_3;
			State* const CreateMessage_4;

			States(ITransitions* transitions);
			State* get_state();
			void change_state(State* state);

		private:
			State* state;
	};
}