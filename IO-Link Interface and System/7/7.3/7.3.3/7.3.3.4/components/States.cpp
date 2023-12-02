#include "States.h"
#include "Transitions_Interface.h"
#include <cstddef>

namespace State_machine_of_the_Master_message_handler {



	// void States::State_Base::PL_Transfer_req(uint8_t Data) {
	// 	if(states->state == states->GetMessage_2) {
	// 		transitions->T3();
	// 		states->state = states->GetMessage_2;
	// 	}
	// 	(void)Data; //TODO: was soll mit den Daten geschehen?
	// }

	// PL_Transfer::Status States::State_Base::PL_Transfer_ind(uint8_t Data) {
	// 	if(states->state == states->Idle_1) {
	// 		transitions->T2();
	// 		states->state = states->GetMessage_2;
	// 	}
	// 	(void)Data; //TODO: was soll mit den Daten geschehen?
	// 	return PL_Transfer::Status::SUCCESS; //TODO: wie kommt der Rückgabewert zustande?
	// }

	// void States::State_Base::PL_Transfer_rsp() {
	// 	//PL->PL_Transfer_rsp();
	// }

	class _Inactive_0: public States::State_Base {
		public:
			using State_Base::State_Base;

			void MH_Conf_COMx() override {
				transitions->T1();
				states->state = states->AwaitReply_1;
			}
	};

	class _AwaitReply_1: public States::State_Base {
		public:
			using State_Base::State_Base;

			void tick(Guard guard) {
				switch(guard) {
					case Guard::Response_OK:
						transitions->T2();
						states->state = states->Startup_2;
						return;
					case Guard::Response_not_OK:
						transitions->T3();
						states->state = states->Inactive_0;
						return;
					default:
						return;
				} 
			}

			void tm_event() override {
				transitions->T4();
				states->state = states->Inactive_0;
			}
	};

	class _Startup_2: public States::State_Base {
		public:
			using State_Base::State_Base;

			void DL_Read() override {
				transitions->T5();
				states->state = states->Response_3;
			}
	};

	class _Response_3: public States::State_Base {
		public:
			using State_Base::State_Base;
	};

	class _Preoperate_6: public States::State_Base {
		public:
			using State_Base::State_Base;
	};

	class _GetOD_7: public States::State_Base {
		public:
			using State_Base::State_Base;
	};

	class _Response_8: public States::State_Base {
		public:
			using State_Base::State_Base;
	};

	class _CheckHandler_11: public States::State_Base {
		public:
			using State_Base::State_Base;
	};

	class _Operate_12: public States::State_Base {
		public:
			using State_Base::State_Base;
	};

	class _GetPD_13: public States::State_Base {
		public:
			using State_Base::State_Base;
	};

	class _GetOD_14: public States::State_Base {
		public:
			using State_Base::State_Base;
	};

	class _Response_15: public States::State_Base {
		public:
			using State_Base::State_Base;
	};

	States::States(Administration* administration, Transitions_Interface* transitions):
	 	Inactive_0(new _Inactive_0(this, transitions, administration)),
		AwaitReply_1(new _AwaitReply_1(this, transitions, administration)),
		Startup_2(new _Startup_2(this, transitions, administration)),
		Response_3(new _Response_3(this, transitions, administration)),
		Preoperate_6(new _Preoperate_6(this, transitions, administration)),
		GetOD_7(new _GetOD_7(this, transitions, administration)),
		Response_8(new _Response_8(this, transitions, administration)),
		CheckHandler_11(new _CheckHandler_11(this, transitions, administration)),
		Operate_12(new _Operate_12(this, transitions, administration)),
		GetPD_13(new _GetPD_13(this, transitions, administration)),
		GetOD_14(new _GetOD_14(this, transitions, administration)),
		Response_15(new _Response_15(this, transitions, administration))
	{}
}
