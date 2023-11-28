#include "States.h"
#include "Transitions_Interface.h"
#include <cstddef>

namespace State_machine_of_the_Device_message_handler {

	class _Inactive_0: public States::State_Base {
		public:
			_Inactive_0(
				States* states,
				Transitions_Interface* transitions,
				Administration* administration
			):
				State_Base(states, transitions, administration)
			{}
	};

	class _Idle_1: public States::State_Base {
		public:
			_Idle_1(
				States* states,
				Transitions_Interface* transitions,
				Administration* administration
			):
				State_Base(states, transitions, administration)
			{}

			void tm_event() override {
				transitions->T10();
				states->state = states->Idle_1;
			}
	};

	class _GetMessage_2: public States::State_Base {
		public:
			_GetMessage_2(
				States* states,
				Transitions_Interface* transitions,
				Administration* administration
			):
				State_Base(states, transitions, administration)
			{}

			void tick(Guard guard) override {
				if(guard == Guard::Completed) {
					transitions->T4();
					states->state = states->CheckMessage_3;
				}
			}

			void tm_event() override {
				transitions->T9();
				states->state = states->Idle_1;
			}
	};

	class _CheckMessage_3: public States::State_Base {
		public:
			_CheckMessage_3(
				States* states,
				Transitions_Interface* transitions,
				Administration* administration
			):
				State_Base(states, transitions, administration)
			{}

			void tick(Guard guard) override {
				switch(guard) {
					case Guard::No_error:
						transitions->T5();
						states->state = states->CreateMessage_4;
						return;
					case Guard::ChecksumError:
						transitions->T7();
						states->state = states->Idle_1;
						return;
					case Guard::TypeError_and_not_ChecksumError:
						transitions->T8();
						states->state = states->Idle_1;
						return;
					default:
						return;
				}
			}
	};

	class _CreateMessage_4: public States::State_Base {
		public:
			_CreateMessage_4(
				States* states,
				Transitions_Interface* transitions,
				Administration* administration
			):
				State_Base(states, transitions, administration)
			{}

			void tick(Guard guard) override {
				if(guard == Guard::Ready) {
					transitions->T6();
					states->state = states->Idle_1;
				}
			}
	};

	States::States(Administration* administration, Transitions_Interface* transitions):
		Inactive_0(new _Inactive_0(this, transitions, administration)),
		Idle_1(new _Idle_1(this, transitions, administration)),
		GetMessage_2(new _GetMessage_2(this, transitions, administration)),
		CheckMessage_3(new _CheckMessage_3(this, transitions, administration)),
		CreateMessage_4(new _CreateMessage_4(this, transitions, administration)){}


	void States::State_Base::tick(Guard guard) { (void)guard; }

	void States::State_Base::tm_event() {}

	void States::State_Base::MH_Conf_ACTIVE() {
		if(states->state == states->Inactive_0) {
			transitions->T1();
			states->state = states->Idle_1;
		}
	}

	void States::State_Base::MH_Conf_INACTIVE() {
		if(states->state == states->Idle_1) {
			transitions->T11();
			states->state = states->Inactive_0;
		}
	}

	void States::State_Base::PL_Transfer_req(uint8_t Data) {
		if(states->state == states->GetMessage_2) {
			transitions->T3();
			states->state = states->GetMessage_2;
		} 
		(void)Data; //TODO: was soll mit den Daten geschehen?
	}
	
	PL_Transfer::Status States::State_Base::PL_Transfer_ind(uint8_t Data) {
		if(states->state == states->Idle_1) {
			transitions->T2();
			states->state = states->GetMessage_2;
		}
		(void)Data; //TODO: was soll mit den Daten geschehen?
		return PL_Transfer::Status::SUCCESS; //TODO: wie kommt der Rückgabewert zustande?
	}

	void States::State_Base::PL_Transfer_rsp() {
		//PL->PL_Transfer_rsp();
	}
}
