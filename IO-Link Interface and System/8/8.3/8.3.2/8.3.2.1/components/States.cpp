#include "States.h"
#include "ITransitions.h"
namespace OD_state_machine_of_the_Master_AL {

	class _OnReq_Idle_0: public States::IState {
		public:
			_OnReq_Idle_0(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {(void)guard; return this; }

			IState* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				if(event == States::Event::AL_Service_Portx) {
					transitions->T1();
					return states->Build_DL_Service_1;
				}
				return this;
			}
	};

	class _Build_DL_Service_1: public States::IState {
		public:
			_Build_DL_Service_1(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {(void)guard; return this; }

			IState* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				(void)event;
				return this;
			}
	};

	class _Await_DL_Param_cnf_2: public States::IState {
		public:
			_Await_DL_Param_cnf_2(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {(void)guard; return this; }

			IState* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				(void)event;
				return this;
			}
	};

	class _Await_DL_ISDU_cnf_3: public States::IState {
		public:
			_Await_DL_ISDU_cnf_3(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {(void)guard; return this; }

			IState* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				(void)event;
				return this;
			}
	};

	class _Build_AL_cnf_4: public States::IState {
		public:
			_Build_AL_cnf_4(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {(void)guard; return this; }

			IState* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				(void)event;
				return this;
			}
	};

	States::States(ITransitions* transitions):
		OnReq_Idle_0(new _OnReq_Idle_0(this, transitions)),
		Build_DL_Service_1(new _Build_DL_Service_1(this, transitions)),
		Await_DL_Param_cnf_2(new _Await_DL_Param_cnf_2(this, transitions)),
		Await_DL_ISDU_cnf_3(new _Await_DL_ISDU_cnf_3(this, transitions)),
		Build_AL_cnf_4(new _Build_AL_cnf_4(this, transitions)) { }
}
