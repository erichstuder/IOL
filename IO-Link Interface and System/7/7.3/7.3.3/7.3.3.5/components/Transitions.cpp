#include "Transitions.h"

namespace State_machine_of_the_Device_message_handler {
	void Transitions::T1() {}

	void Transitions::T2() {
		administration->MaxUARTframeTime_timer->start();
		administration->MaxCycleTime_timer->start();
	}

	void Transitions::T3() {
		administration->MaxUARTframeTime_timer->start();
	}

	void Transitions::T4() {
		administration->MaxUARTframeTime_timer->stop();
	}

	void Transitions::T5() {
		OD::Argument_type OD_Argument;
		OD_handler->OD_ind(OD_Argument);

		PD::Argument_type PD_Argument;
		PD_handler->PD_ind(PD_Argument);
	}

	void Transitions::T6() {
		PL_Transfer->PL_Transfer_rsp();
	}

	void Transitions::T7() {}
	void Transitions::T8() {}
	void Transitions::T9() {}
	void Transitions::T10() {}
	void Transitions::T11() {}
}
