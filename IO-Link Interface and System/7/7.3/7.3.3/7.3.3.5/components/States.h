#pragma once

#include "ITransitions.h"
#include "PL_Transfer.h"
#include "Behavioral_description.h"
#include "ITimer.h"

namespace State_machine_of_the_Device_message_handler {
	class States {
		public:
			/*enum class Event {  //TODO: vermutlich kann das weg
				dummy
			};*/

			enum class Guard {
				NoGuard
			};

			class State: public PL_Transfer, public Behavioral_description {
				public:
					State(States* states, ITransitions* transitions);
					virtual State* tick(Guard guard) = 0;
					virtual void enter() {};
					virtual void exit() {};

					void tm_event() override {};

					void MH_Conf_ACTIVE();
					void MH_Conf_INACTIVE();

					void PL_Transfer_req(uint8_t Data) override;
					Status PL_Transfer_ind(uint8_t Data) override;
				protected:
					States* states;
					ITransitions* transitions;
			};

			State* const Inactive_0;
			State* const Idle_1;
			State* const GetMessage_2;
			State* const CheckMessage_3;
			State* const CreateMessage_4;
			ITimer* const timer;
			float MaxCycleTime_ms = 42.8; //TODO: don't understand yet how to set this time. see Specification and maybe also 10.8.3

			States(ITransitions* transitions, ITimer* timer);
			State* get_state();
			void change_state(State* state);

		private:
			State* state;
	};
}
