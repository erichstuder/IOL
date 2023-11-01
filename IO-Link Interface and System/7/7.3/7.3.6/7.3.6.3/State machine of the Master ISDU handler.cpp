#include "State machine of the Master ISDU handler.h"

namespace State_machine_of_the_Master_ISDU_handler {
	enum class State {
		Inactive_0,
		Idle_1,
		ISDURequest_2,
		ISDUWait_3,
		ISDUError_4,
		ISDUResponse_5
	};

	enum class Event {
		IH_Conf_ACTIVE,
		IH_Conf_INACTIVE,
		ISDUTrig
		//there is more to come, see: Figure 51
	};


	void T1();
}
