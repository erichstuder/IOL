#pragma once

#include "DL_Read_req.h"
#include "DL_Write_req.h"
#include "Behavioral_description.h"

namespace State_machine_of_the_Master_message_handler {
	class State_Interface:
		public DL_Read_req__Interface,
		public DL_Write_req__Interface,
		public Behavioral_description
	{
		public:
			enum class Guard {
				NoGuard,
				Response_OK,
				Response_not_OK,
				No_error,
				Retry_less_than_MaxRetry,
				Retry_equals_MaxRetry
			};

			virtual void tick(Guard guard) = 0;

			void tm_event() override = 0;

			virtual void MH_Conf_COMx() = 0;
			virtual void MH_Conf_PREOPERATE() = 0;
			virtual void MH_Conf_OPERATE() = 0;

			void DL_Read_req(DL_Read::Argument_type* Argument) override = 0;
			void DL_Write_req(DL_Write::Argument_type* Argument) override = 0;
	};
}
