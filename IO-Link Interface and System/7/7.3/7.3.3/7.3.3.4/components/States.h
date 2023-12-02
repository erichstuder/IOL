#pragma once

#include "State_Interface.h"
#include "Administration.h"
#include "Transitions_Interface.h"

namespace State_machine_of_the_Master_message_handler {
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

					void tick(Guard guard) override { (void)guard; }

					void tm_event() override {}

					virtual void MH_Conf_COMx() {}
					virtual void DL_Read() {}

			// 		void PL_Transfer_req(uint8_t Data) override;
			// 		PL_Transfer::Status PL_Transfer_ind(uint8_t Data) override;
			// 		void PL_Transfer_rsp() override;

				protected:
					States* states;
					Transitions_Interface* transitions;
					Administration* administration;
			};

			State_Base* const Inactive_0;
			State_Base* const AwaitReply_1;
			State_Base* const Startup_2;
			State_Base* const Response_3;
			State_Base* const Preoperate_6;
			State_Base* const GetOD_7;
			State_Base* const Response_8;
			State_Base* const CheckHandler_11;
			State_Base* const Operate_12;
			State_Base* const GetPD_13;
			State_Base* const GetOD_14;
			State_Base* const Response_15;
			State_Base* state;
	};
}
