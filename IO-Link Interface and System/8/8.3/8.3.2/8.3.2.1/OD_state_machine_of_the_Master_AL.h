#pragma once

#include "components/States.h"
#include "components/Transitions.h"
#include "AL_Read.h"

namespace OD_state_machine_of_the_Master_AL {
	class OD_state_machine_of_the_Master_AL: public AL_Read {
		public:
			OD_state_machine_of_the_Master_AL();

			void tick();

			void AL_Read_req(uint8_t Port, uint16_t Index, uint8_t Subindex);
			void AL_Read_ind(uint16_t Index, uint8_t Subindex);
			Result_type AL_Read_rsp();
			Result_type AL_Read_cnf();

		private:
			Transitions* transitions;
			States* states;
			States::State* state;
	};
};
