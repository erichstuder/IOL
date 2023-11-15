#pragma once

#include "ITransitions.h"

namespace OD_state_machine_of_the_Master_AL {
	class States {
		public:
			States(ITransitions* transitions);

			enum class Event {
				AL_Service_Portx,
				AL_Read,
				AL_Write,
				AL_Service,
				AL_Abort,
				DL_RWParam,
				DL_ReadParam,
				DL_WriteParam,
				DL_ISDUTransport,
				AL_Abort_Portx
			};

			enum class Guard {
				NoGuard,
				Argument_Error,
				//there is more to come
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

			IState* const OnReq_Idle_0;
			IState* const Build_DL_Service_1;
			IState* const Await_DL_Param_cnf_2;
			IState* const Await_DL_ISDU_cnf_3;
			IState* const Build_AL_cnf_4;
	};
}
