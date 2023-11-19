#pragma once

#include "ITransitions.h"

namespace State_machine_of_the_Device_message_handler {
	class States {
		public:
			enum class Event {
				dummy
			};

			enum class Guard {
				dummy
			};

			class State {
				public:
					State(States* states, ITransitions* transitions);
					virtual State* tick(Guard guard) = 0;

					/*void AL_Read_req(uint8_t Port, uint16_t Index, uint8_t Subindex);
					void AL_Read_ind(uint16_t Index, uint8_t Subindex);
					Result_type AL_Read_rsp();
					Result_type AL_Read_cnf();*/
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
