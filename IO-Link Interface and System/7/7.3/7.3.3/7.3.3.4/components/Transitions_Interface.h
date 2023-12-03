#pragma once

// #include "Administration.h"
// #include "OD_handler_for_Device.h"
// #include "PD_handler_for_Device.h"
// #include "PL_Transfer_for_Device.h"
// #include "MHInfo_ind.h"

namespace State_machine_of_the_Master_message_handler {
	class Transitions_Interface
	{
		public:
		// 	Transitions_Interface(
		// 		Administration* administration,
		// 		OD_handler_for_Device* OD_handler,
		// 		PD_handler_for_Device* PD_handler,
		// 		PL_Transfer_for_Device__Message_handler_Interface* PL_Transfer,
		// 		MHInfo_ind__Interface* DL_mode_handler
		// 	):
		// 		administration(administration),
		// 		OD_handler(OD_handler),
		// 		PD_handler(PD_handler),
		// 		PL_Transfer(PL_Transfer),
		// 		DL_mode_handler(DL_mode_handler)
		// 	{}

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
			virtual void T12() = 0;
			virtual void T13() = 0;
			virtual void T14() = 0;
			virtual void T15() = 0;
			virtual void T16() = 0;
			virtual void T17() = 0;
			virtual void T18() = 0;
			virtual void T19() = 0;
			virtual void T20() = 0;
			virtual void T21() = 0;
			virtual void T22() = 0;
			virtual void T23() = 0;
			virtual void T24() = 0;
			virtual void T25() = 0;
			virtual void T26() = 0;
			virtual void T27() = 0;
			virtual void T28() = 0;
			virtual void T29() = 0;
			virtual void T30() = 0;
			virtual void T31() = 0;
			virtual void T32() = 0;
			virtual void T33() = 0;
			virtual void T34() = 0;
			virtual void T35() = 0;
			virtual void T36() = 0;
			virtual void T37() = 0;
			virtual void T38() = 0;
			virtual void T39() = 0;
			virtual void T40() = 0; //missing in the specification
			virtual void T41() = 0; //missing in the specification

		// 	Administration* const administration;
		// 	OD_handler_for_Device* const OD_handler;
		// 	PD_handler_for_Device* const PD_handler;
		// 	PL_Transfer_for_Device__Message_handler_Interface* const PL_Transfer;
		// 	MHInfo_ind__Interface* const DL_mode_handler;
	};
}
