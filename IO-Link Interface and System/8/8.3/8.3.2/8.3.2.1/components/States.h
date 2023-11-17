#pragma once

#include "ITransitions.h"
#include "AL_Read.h"

namespace OD_state_machine_of_the_Master_AL {
	class States {
		public:
			enum class Event {
				AL_Service_Portx,
				AL_Read,
				AL_Write,
				AL_Service,
				AL_Abort,
				DL_RWParam,
				DL_ReadParam,
				DL_WriteParam,
				DL_ISDUTransport,
				AL_Abort_Portx
			};

			enum class Guard {
				NoGuard,
				Argument_Error,
				//there is more to come
			};

			class State: public AL_Read {
				public:
					State(States* states, ITransitions* transitions);
					virtual State* tick(Guard guard) = 0;

					void AL_Read_req(uint8_t Port, uint16_t Index, uint8_t Subindex);
					void AL_Read_ind(uint16_t Index, uint8_t Subindex);
					Result_type AL_Read_rsp();
					Result_type AL_Read_cnf();
				protected:
					States* states;
					ITransitions* transitions;
			};

			State* const OnReq_Idle_0;
			State* const Build_DL_Service_1;
			State* const Await_DL_Param_cnf_2;
			State* const Await_DL_ISDU_cnf_3;
			State* const Build_AL_cnf_4;
			State* state;

			States(ITransitions* transitions);
	};
}
