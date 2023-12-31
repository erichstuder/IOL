#pragma once

#include "ITransitions.h"

namespace State_machine_of_the_Master_ISDU_handler {
	class States {
		public:
			States(ITransitions* transitions);

			enum class Event {
				IH_Conf_ACTIVE,
				IH_Conf_INACTIVE,
				ISDUTrig,
				DL_Mode_COMLOST,
				ISDUAbort,
				DL_ISDUAbort
			};

			enum class Guard {
				NoGuard,
				DL_ISDUTransport,
				ParamRequest,
				Data_written,
				ResponseStart,
				Error,
				Transmission_completed
			};

			class IState {
				public:
					IState(States* states, ITransitions* transitions) :
						states(states),	transitions(transitions)
						{};
					virtual IState* tick(Guard guard) = 0;
					virtual IState* handle_event(Event event, Guard guard) = 0;
				protected:
					States* states;
					ITransitions* transitions;
			};

			IState* const Inactive_0;
			IState* const Idle_1;
			IState* const ISDURequest_2;
			IState* const ISDUWait_3;
			IState* const ISDUError_4;
			IState* const ISDUResponse_5;
	};
}
