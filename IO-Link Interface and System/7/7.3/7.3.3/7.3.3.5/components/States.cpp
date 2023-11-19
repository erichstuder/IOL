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

			/*State* handle_event(States::Event event, States::Guard guard) {
				(void)event;
				(void)guard;
				return this;
			}*/
	};

	class _Idle_1: public States::State {
		public:
			_Idle_1(States* states, ITransitions* transitions) : State(states, transitions) { }

			State* tick(States::Guard guard) {
				(void)guard;
				return this;
			}

			/*State* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				(void)event;
				return this;
			}*/
	};

	class _GetMessage_2: public States::State {
		public:
			_GetMessage_2(States* states, ITransitions* transitions) : State(states, transitions) { }

			State* tick(States::Guard guard) {
				(void)guard;
				return this;
			}

			/*State* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				(void)event;
				return this;
			}*/
	};

	class _CheckMessage_3: public States::State {
		public:
			_CheckMessage_3(States* states, ITransitions* transitions) : State(states, transitions) { }

			State* tick(States::Guard guard) {
				(void)guard;
				return this;
			}

			/*State* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				(void)event;
				return this;
			}*/
	};

	class _CreateMessage_4: public States::State {
		public:
			_CreateMessage_4(States* states, ITransitions* transitions) : State(states, transitions) { }

			State* tick(States::Guard guard) {
				(void)guard;
				return this;
			}

			/*State* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				(void)event;
				return this;
			}*/
	};

	States::States(ITransitions* transitions):
		Inactive_0(new _Inactive_0(this, transitions)),
		Idle_1(new _Idle_1(this, transitions)),
		GetMessage_2(new _GetMessage_2(this, transitions)),
		CheckMessage_3(new _CheckMessage_3(this, transitions)),
		CreateMessage_4(new _CreateMessage_4(this, transitions)) { }


	States::State::State(States* states, ITransitions* transitions): states(states), transitions(transitions) { }

	void States::State::MH_Conf_ACTIVE() {
		if(states->state == states->Inactive_0) {
			transitions->T1();
			states->state = states->Idle_1;
		}
	}

	void States::State::MH_Conf_INACTIVE() {
		if(states->state == states->Idle_1) {
			transitions->T11();
			states->state = states->Inactive_0;
		}
	}

	void States::State::PL_Transfer_req(uint8_t Data) {
		(void)Data;
	}
	
	PL_Transfer::Status States::State::PL_Transfer_ind(uint8_t Data) {
		if(states->state == states->Idle_1) {
			transitions->T2();
			states->state = states->GetMessage_2;
		}
		(void)Data; //TODO: was soll mit den Daten geschehen?
		return PL_Transfer::Status::SUCCESS; //TODO: wie kommt der Rückgabewert zustande?
	}
}
