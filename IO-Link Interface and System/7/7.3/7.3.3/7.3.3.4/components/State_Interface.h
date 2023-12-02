#pragma once

// #include "PL_Transfer_req.h"
// #include "PL_Transfer_ind.h"
// #include "PL_Transfer_rsp.h"
#include "Behavioral_description.h"

namespace State_machine_of_the_Master_message_handler {
	class State_Interface:
	// 	public PL_Transfer_req__Interface,
	// 	public PL_Transfer_ind__Interface,
	// 	public PL_Transfer_rsp__Interface,
		public Behavioral_description
	{
		public:
			enum class Guard {
				NoGuard,
				Response_OK,
				Response_not_OK
			};

			virtual void tick(Guard guard) = 0;

			void tm_event() override = 0;

	// 		void PL_Transfer_req(uint8_t Data) override = 0;
	// 		PL_Transfer::Status PL_Transfer_ind(uint8_t Data) override = 0;
	// 		void PL_Transfer_rsp() override = 0;
	};
}
