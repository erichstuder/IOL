#include "States.h"
#include "ITransitions.h"

namespace State_machine_of_the_Master_ISDU_handler {

	class _Inactive_0: public States::IState {
		public:
			_Inactive_0(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick() { return this; }

			IState* handle_event(States::Event event) {
				if(event == States::Event::IH_Conf_ACTIVE) {
					transitions->T1();
					return states->Idle_1;
				}
				return this;
			}
	};

	class _Idle_1: public States::IState {
		public:
			_Idle_1(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick() { return this; }

			IState* handle_event(States::Event event) {
				(void)event;
				return this;
			}
	};

	/*class ISDURequest_2 : public IState {
		public:
			virtual void tick(Event event) {
				//TBD
			}
	};*/


	States::States(ITransitions* transitions):
		Inactive_0(new _Inactive_0(this, transitions)),
		Idle_1(new _Idle_1(this, transitions)) { }
}
