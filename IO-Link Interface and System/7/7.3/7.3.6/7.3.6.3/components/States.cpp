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
				switch(event) {
					case States::Event::ISDUTrig:
						return handle_ISDUTrig(guard);
					case States::Event::IH_Conf_INACTIVE:
						transitions->T16();
						return states->Inactive_0;
					default:
						return this;
				}
			}

		private:
			IState* handle_ISDUTrig(States::Guard guard) {
				switch(guard) {
					case States::Guard::DL_ISDUTransport:
						transitions->T2();
						return states->ISDURequest_2;
					case States::Guard::ParamRequest:
						transitions->T13();
						return this;
					case States::Guard::NoGuard:
						transitions->T14();
						return this;
					default:
						return this;
				}
			}
	};

	class _ISDURequest_2: public States::IState {
		public:
			_ISDURequest_2(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {
				if(guard == States::Guard::Data_written) {
					transitions->T4();
					return states->ISDUWait_3;
				}
				else {
					return this;
				}
			}

			IState* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				switch(event) {
					case States::Event::ISDUTrig:
						transitions->T3();
						return this;
					case States::Event::DL_Mode_COMLOST:
						transitions->T12();
						return states->ISDUError_4;
					case States::Event::ISDUAbort:
						transitions->T19();
						return states->ISDUError_4;
					default:
						return this;
				}
			}
	};

	class _ISDUWait_3: public States::IState {
		public:
			_ISDUWait_3(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {
				switch(guard) {
					case States::Guard::ResponseStart:
						transitions->T6();
						return states->ISDUResponse_5;
					case States::Guard::Error:
						transitions->T9();
						return states->ISDUError_4;
					default:
						return this;
				}
			}

			IState* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				switch(event) {
					case States::Event::ISDUTrig:
						transitions->T5();
						return this;
					case States::Event::DL_ISDUAbort:
						transitions->T17();
						return states->ISDUError_4;
					default:
						return this;
				}
				return this;
			}
	};

	class _ISDUError_4: public States::IState {
		public:
			_ISDUError_4(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {(void)guard; return this; }

			IState* handle_event(States::Event event, States::Guard guard) {
				(void)guard;
				switch(event) {
					case States::Event::ISDUTrig:
						transitions->T11();
						return states->Idle_1;
					case States::Event::IH_Conf_INACTIVE:
						transitions->T15();
						return states->Inactive_0;
					default:
						return this;
				}
			}
	};

	class _ISDUResponse_5: public States::IState {
		public:
			_ISDUResponse_5(States* states, ITransitions* transitions) : IState(states, transitions) { }

			IState* tick(States::Guard guard) {
				if(guard == States::Guard::Error) {
					transitions->T10();
					return states->ISDUError_4;
				}
				return this;
			}

			IState* handle_event(States::Event event, States::Guard guard) {
				switch(event) {
					case States::Event::ISDUTrig:
						return handle_ISDUTrig(guard);
					case States::Event::DL_ISDUAbort:
						transitions->T18();
						return states->ISDUError_4;
					default:
						return this;
				}
			}

		private:
			IState* handle_ISDUTrig(States::Guard guard) {
				if(guard == States::Guard::Transmission_completed) {
					transitions->T8();
					return states->Idle_1;
				}
				else {
					transitions->T7();
					return this;
				}
			}
	};


	States::States(ITransitions* transitions):
		Inactive_0(new _Inactive_0(this, transitions)),
		Idle_1(new _Idle_1(this, transitions)),
		ISDURequest_2(new _ISDURequest_2(this, transitions)),
		ISDUWait_3(new _ISDUWait_3(this, transitions)),
		ISDUError_4(new _ISDUError_4(this, transitions)),
		ISDUResponse_5(new _ISDUResponse_5(this, transitions)) { }
}
