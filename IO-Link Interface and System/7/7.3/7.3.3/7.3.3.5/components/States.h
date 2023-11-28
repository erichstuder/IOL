#pragma once

#include "State_Interface.h"
#include "Administration.h"
#include "Transitions_Interface.h"

namespace State_machine_of_the_Device_message_handler {
	class States {
		public:
			States(Administration* administration, Transitions_Interface* transitions);

			class State_Base: public State_Interface
			{
				public:
					State_Base(
						States* states,
						Transitions_Interface* transitions,
						Administration* administration
					):
						states(states),
						transitions(transitions),
						administration(administration)
					{}

					void tick(Guard guard) override;

					void tm_event() override;

					void MH_Conf_ACTIVE(); //TODO: ins Interface auslagern?
					void MH_Conf_INACTIVE(); //TODO: ins Interface auslagern?

					void PL_Transfer_req(uint8_t Data) override;
					PL_Transfer::Status PL_Transfer_ind(uint8_t Data) override;
					void PL_Transfer_rsp() override;

				protected:
					States* states;
					Transitions_Interface* transitions;
					Administration* administration;
			};

			State_Base* const Inactive_0;
			State_Base* const Idle_1;
			State_Base* const GetMessage_2;
			State_Base* const CheckMessage_3;
			State_Base* const CreateMessage_4;
			const float MaxCycleTime_ms = 42.8; //TODO: don't understand yet how to set this time. see Specification and maybe also 10.8.3
			const float MaxUARTframeTime_ms = 88.9; //TODO: don't understand yet how to set this time. see Specification and maybe also 10.8.3

			State_Base* state;
	};
}
