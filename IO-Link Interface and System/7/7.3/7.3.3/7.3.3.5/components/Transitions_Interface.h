#pragma once

#include "Administration.h"
#include "OD_handler_for_Device.h"
#include "PD_handler_for_Device.h"
#include "PL_Transfer_for_Device.h"

namespace State_machine_of_the_Device_message_handler {
	class Transitions_Interface
	{
		public:
			Transitions_Interface(
				Administration* administration,
				OD_handler_for_Device* OD_handler,
				PD_handler_for_Device* PD_handler,
				PL_Transfer_for_Device__Message_handler_Interface* PL_Transfer
			):
				administration(administration),
				OD_handler(OD_handler),
				PD_handler(PD_handler),
				PL_Transfer(PL_Transfer)
			{}

			virtual void T1() = 0;
			virtual void T2() = 0;
			virtual void T3() = 0;
			virtual void T4() = 0;
			virtual void T5() = 0;
			virtual void T6() = 0;
			virtual void T7() = 0;
			virtual void T8() = 0;
			virtual void T9() = 0;
			virtual void T10() = 0;
			virtual void T11() = 0;

			Administration* const administration;
			OD_handler_for_Device* const OD_handler;
			PD_handler_for_Device* const PD_handler;
			PL_Transfer_for_Device__Message_handler_Interface* const PL_Transfer;
	};
}
