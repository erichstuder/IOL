#include "States.h"
#include "ITransitions.h"
namespace State_machine_of_the_Device_message_handler {

	class _Inactive_0: public States::State {
		public:
			_Inactive_0(States* states, ITransitions* transitions) : State(states, transitions) { }

			State* tick(States::Guard guard) {
				(void)guard;
				return this;
			}

			State* handle_event(States::Event event, States::Guard guard) {
				(void)event;
				(void)guard;
				return this;
			}
	};

	class _Idle_1: public States::State {
		public:
			_Idle_1(States* states, ITransitions* transitions) : State(states, transitions) { }

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

	class _GetMessage_2: public States::State {
		public:
			_GetMessage_2(States* states, ITransitions* transitions) : State(states, transitions) { }

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

	class _CheckMessage_3: public States::State {
		public:
			_CheckMessage_3(States* states, ITransitions* transitions) : State(states, transitions) { }

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

	class _CreateMessage_4: public States::State {
		public:
			_CreateMessage_4(States* states, ITransitions* transitions) : State(states, transitions) { }

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
		Inactive_0(new _Inactive_0(this, transitions)),
		Idle_1(new _Idle_1(this, transitions)),
		GetMessage_2(new _GetMessage_2(this, transitions)),
		CheckMessage_3(new _CheckMessage_3(this, transitions)),
		CreateMessage_4(new _CreateMessage_4(this, transitions)) { }


	States::State::State(States* states, ITransitions* transitions): states(states), transitions(transitions) { }

	/*void States::State::AL_Read_req(uint8_t Port, uint16_t Index, uint8_t Subindex) {
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
	}*/
}
