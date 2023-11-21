#include "States.h"
#include "ITransitions.h"
#include <cstddef>

namespace State_machine_of_the_Device_message_handler {

	class _Inactive_0: public States::State {
		public:
			_Inactive_0(States* states, ITransitions* transitions) : State(states, transitions) {}
	};

	class _Idle_1: public States::State {
		public:
			_Idle_1(States* states, ITransitions* transitions) : State(states, transitions) {}

			void enter() override {
				states->timer->start(states->MaxCycleTime_ms);
			}

			void exit() override {
				states->timer->stop();
			}

			void tm_event() override {
				transitions->T10();
				states->change_state(states->Idle_1);
			}
	};

	class _GetMessage_2: public States::State {
		public:
			_GetMessage_2(States* states, ITransitions* transitions) : State(states, transitions) {}

			void tick(States::Guard guard) override {
				if(guard == States::Guard::Completed) {
					transitions->T4();
					states->change_state(states->CheckMessage_3);
				}
			}

			void enter() override {
				states->timer->start(states->MaxUARTframeTime);
			}

			void exit() override {
				states->timer->stop();
			}

			void tm_event() override {
				transitions->T9();
				states->change_state(states->Idle_1);
			}
	};

	class _CheckMessage_3: public States::State {
		public:
			_CheckMessage_3(States* states, ITransitions* transitions) : State(states, transitions) {}

			void tick(States::Guard guard) override {
				switch(guard) {
					case States::Guard::No_error:
						transitions->T5();
						states->change_state(states->CreateMessage_4);
						return;
					case States::Guard::ChecksumError:
						transitions->T7();
						states->change_state(states->Idle_1);
						return;
					case States::Guard::TypeError_and_not_ChecksumError:
						transitions->T8();
						states->change_state(states->Idle_1);
						return;
					default:
						return;
				}
			}
	};

	class _CreateMessage_4: public States::State {
		public:
			_CreateMessage_4(States* states, ITransitions* transitions) : State(states, transitions) {}
	};

	States::States(ITransitions* transitions, ITimer* timer):
		Inactive_0(new _Inactive_0(this, transitions)),
		Idle_1(new _Idle_1(this, transitions)),
		GetMessage_2(new _GetMessage_2(this, transitions)),
		CheckMessage_3(new _CheckMessage_3(this, transitions)),
		CreateMessage_4(new _CreateMessage_4(this, transitions)),
		timer(timer) { }

	States::State* States::get_state() {
		return state;
	}

	void States::change_state(State* state) {
		if(this->state != NULL) {
			this->state->exit();
		}
		this->state = state;
		this->state->enter();
	}


	States::State::State(States* states, ITransitions* transitions): states(states), transitions(transitions) {}

	void States::State::MH_Conf_ACTIVE() {
		if(states->get_state() == states->Inactive_0) {
			transitions->T1();
			states->change_state(states->Idle_1);
		}
	}

	void States::State::MH_Conf_INACTIVE() {
		if(states->get_state() == states->Idle_1) {
			transitions->T11();
			states->change_state(states->Inactive_0);
		}
	}

	void States::State::PL_Transfer_req(uint8_t Data) {
		if(states->get_state() == states->GetMessage_2) {
			transitions->T3();
			states->change_state(states->GetMessage_2);
		} 
		(void)Data; //TODO: was soll mit den Daten geschehen?
	}
	
	PL_Transfer::Status States::State::PL_Transfer_ind(uint8_t Data) {
		if(states->get_state() == states->Idle_1) {
			transitions->T2();
			states->change_state(states->GetMessage_2);
		}
		(void)Data; //TODO: was soll mit den Daten geschehen?
		return PL_Transfer::Status::SUCCESS; //TODO: wie kommt der Rückgabewert zustande?
	}
}
