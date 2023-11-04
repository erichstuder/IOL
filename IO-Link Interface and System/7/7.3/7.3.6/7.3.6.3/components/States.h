#pragma once

#include "ITransitions.h"

namespace State_machine_of_the_Master_ISDU_handler {
	class States {
		public:
			States(ITransitions* transitions);

			enum class Event {
				NoEvent,
				IH_Conf_ACTIVE,
				IH_Conf_INACTIVE,
				ISDUTrig
				//there is more to come, see: Figure 51
			};

			class IState {
				public:
					IState(States* states, ITransitions* transitions) :
						states(states),	transitions(transitions)
						{};
					virtual IState* tick() = 0;
					virtual IState* handle_event(Event event) = 0;
				protected:
					States* states;
					ITransitions* transitions;
			};

			IState* const Inactive_0;
			IState* const Idle_1;
	};
}
