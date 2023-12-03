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

					void MH_Conf_COMx() override {}
					void MH_Conf_PREOPERATE() override {}
					void MH_Conf_OPERATE() override {}

					void DL_Read_req(DL_Read::Argument_type* Argument) override { (void)Argument; }
					void DL_Write_req(DL_Write::Argument_type* Argument) override { (void)Argument; }
					void DL_ReadParam_req(DL_ReadParam::Argument_type* Argument) override { (void)Argument; }
					void DL_WriteParam_req(DL_WriteParam::Argument_type* Argument) override { (void)Argument; };

				protected:
					States* states;
					Transitions_Interface* transitions;
					Administration* administration;
			};

			State_Base* const Inactive_0;
			State_Base* const AwaitReply_1;
			State_Base* const Startup_2;
			State_Base* const Response_3;
			State_Base* const AwaitReply_4;
			State_Base* const ErrorHandling_5;
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
