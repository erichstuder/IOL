#pragma once

#include "ITransitions.h"

namespace State_machine_of_the_Device_message_handler {
	class Transitions: public ITransitions{
		public:
			Transitions(
				Administration* administration,
				OD_handler_for_Device* OD_handler,
				PD_handler_for_Device* PD_handler,
				PL_Transfer_for_Device__Message_handler_Interface* PL_Transfer
			):
				ITransitions(administration, OD_handler, PD_handler, PL_Transfer)
			{}

			void T1() override;
			void T2() override;
			void T3() override;
			void T4() override;
			void T5() override;
			void T6() override;
			void T7() override;
			void T8() override;
			void T9() override;
			void T10() override;
			void T11() override;

			//OD::Result_type OD_rsp() override;
			//PD::Result_type PD_rsp() override;
	};
}
