#include "States.h"
#include "ITransitions.h"
namespace OD_state_machine_of_the_Master_AL {

	class _OnReq_Idle_0: public States::State {
		public:
			_OnReq_Idle_0(States* states, ITransitions* transitions) : State(states, transitions) { }

			State* tick(States::Guard guard) {
				(void)guard;
				return this;
			}

			State* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				switch(event) {
					case States::Event::AL_Service_Portx:
						transitions->T1();
						return states->Build_DL_Service_1;
					case States::Event::AL_Abort_Portx:
						transitions->T17();
						return states->OnReq_Idle_0;
					default:
						return this;
				}
			}
	};

	class _Build_DL_Service_1: public States::State {
		public:
			_Build_DL_Service_1(States* states, ITransitions* transitions) : State(states, transitions) { }

			State* tick(States::Guard guard) {
				(void)guard;
				return this;
			}

			State* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				(void)event;
				return this;
			}
	};

	class _Await_DL_Param_cnf_2: public States::State {
		public:
			_Await_DL_Param_cnf_2(States* states, ITransitions* transitions) : State(states, transitions) { }

			State* tick(States::Guard guard) {
				(void)guard;
				return this;
			}

			State* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				(void)event;
				return this;
			}
	};

	class _Await_DL_ISDU_cnf_3: public States::State {
		public:
			_Await_DL_ISDU_cnf_3(States* states, ITransitions* transitions) : State(states, transitions) { }

			State* tick(States::Guard guard) {
				(void)guard;
				return this;
			}

			State* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				(void)event;
				return this;
			}
	};

	class _Build_AL_cnf_4: public States::State {
		public:
			_Build_AL_cnf_4(States* states, ITransitions* transitions) : State(states, transitions) { }

			State* tick(States::Guard guard) {
				(void)guard;
				return this;
			}

			State* handle_event(States::Event event, States::Guard guard) {
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


	States::State::State(States* states, ITransitions* transitions): states(states), transitions(transitions) { }

	void States::State::AL_Read_req(uint8_t Port, uint16_t Index, uint8_t Subindex) {
		(void)Port;
		(void)Subindex;
		if(states->state == states->Build_DL_Service_1) {
			if(Index <= 1) {
				//DL_ReadParam(Index);
				transitions->T3();
				states->state = states->Await_DL_Param_cnf_2;
			}
		}
	}

	void States::State::AL_Read_ind(uint16_t Index, uint8_t Subindex) {
		(void)Index;
		(void)Subindex;
	}

	AL_Read::Result_type States::State::AL_Read_rsp() {
		return AL_Read::Result_type(44);
	}

	AL_Read::Result_type States::State::AL_Read_cnf() {
		return AL_Read::Result_type(9);
	}
}
