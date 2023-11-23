#include "Transitions.h"

namespace State_machine_of_the_Device_message_handler {
	Transitions::Transitions(Administration* administration):
		administration(administration) {}

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

	void Transitions::T5() {}
	void Transitions::T6() {}
	void Transitions::T7() {}
	void Transitions::T8() {}
	void Transitions::T9() {}
	void Transitions::T10() {}
	void Transitions::T11() {}
}
