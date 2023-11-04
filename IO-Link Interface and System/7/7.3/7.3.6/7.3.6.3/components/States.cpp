#include "States.h"
#include "ITransitions.h"
namespace State_machine_of_the_Master_ISDU_handler {

	class _Inactive_0: public States::IState {
		public:
			_Inactive_0(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {(void)guard; return this; }

			IState* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
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

			IState* tick(States::Guard guard) {(void)guard; return this; }

			IState* handle_event(States::Event event, States::Guard guard) {
				if(event == States::Event::ISDUTrig && guard == States::Guard::DL_ISDUTransport) {
					transitions->T2();
					return states->ISDURequest_2;
				}
				return this;
			}
	};

	class _ISDURequest_2: public States::IState {
		public:
			_ISDURequest_2(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {(void)guard; return this; }

			IState* handle_event(States::Event event, States::Guard guard) {
				(void)event;
				(void)guard;
				return this;
			}
	};

	class _ISDUWait_3: public States::IState {
		public:
			_ISDUWait_3(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {(void)guard; return this; }

			IState* handle_event(States::Event event, States::Guard guard) {
				(void)event;
				(void)guard;
				return this;
			}
	};

	class _ISDUError_4: public States::IState {
		public:
			_ISDUError_4(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {(void)guard; return this; }

			IState* handle_event(States::Event event, States::Guard guard) {
				(void)event;
				(void)guard;
				return this;
			}
	};


	States::States(ITransitions* transitions):
		Inactive_0(new _Inactive_0(this, transitions)),
		Idle_1(new _Idle_1(this, transitions)),
		ISDURequest_2(new _Idle_1(this, transitions)),
		ISDUWait_3(new _Idle_1(this, transitions)),
		ISDUError_4(new _Idle_1(this, transitions)) { }
}
