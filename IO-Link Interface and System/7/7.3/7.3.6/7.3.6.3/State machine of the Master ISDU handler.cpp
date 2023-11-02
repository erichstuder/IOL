#include "State machine of the Master ISDU handler.h"

namespace State_machine_of_the_Master_ISDU_handler {
	/*enum class State {
		Inactive_0,
		Idle_1,
		ISDURequest_2,
		ISDUWait_3,
		ISDUError_4,
		ISDUResponse_5
	};*/

	enum class Trigger {
		IH_Conf_ACTIVE,
		IH_Conf_INACTIVE,
		ISDUTrig
		//there is more to come, see: Figure 51
	};

	static Trigger trigger;

	class IState {
		public:
			virtual void tick() = 0;
	};

	class Inactive_0 : public IState {
		public:
			virtual void tick() {
				if(trigger == Trigger::IH_Conf_ACTIVE) {
					T1();
				}
			}
	};

	class Idle_1 : public IState {
		public:
			virtual void tick() {
				//TBD
			}
	};

	class ISDURequest_2 : public IState {
		public:
			virtual void tick() {
				//TBD
			}
	};

	IState *state = new Inactive_0(); //TODO: Zeiger oder nicht??

	void tick() {
		state->tick();

		/*switch(state) {
			case State::Inactive_0:
				if(Trigger::IH_Conf_ACTIVE) {
					T1();
				}
				break;
			case State::Idle_1:
				if(Trigger::ISDUTrig && Guard::DL_ISDUTransport) {
					T2();
				}
				break;
			case State::ISDURequest_2:
				break;
			case State::ISDUWait_3:
				break;
			case State::ISDUError_4:
				break;
			case State::ISDUResponse_5:
				break;
			default:
				break;
		}*/
	}

	void T1() {
		state = new Idle_1();
		//TODO: don't forget the destructor
	}

	void T2() {
		state = new ISDURequest_2();
		//TODO: don't forget the destructor
	}
}
