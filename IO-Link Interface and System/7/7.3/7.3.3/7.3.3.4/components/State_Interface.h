#pragma once

#include "Behavioral_description.h"
#include "DL_Read_req.h"
#include "DL_Write_req.h"
#include "DL_ReadParam_req.h"
#include "DL_WriteParam_req.h"
#include "DL_ISDUTransport_req.h"
#include "EventFlag_req.h"
#include "COMx.h"

namespace State_machine_of_the_Master_message_handler {
	class State_Interface:
		public Behavioral_description,
		public DL_Read_req__Interface,
		public DL_Write_req__Interface,
		public DL_ReadParam_req__Interface,
		public DL_WriteParam_req__Interface,
		public DL_ISDUTransport_req__Interface,
		public EventFlag_req__Interface
	{
		public:
			enum class Guard {
				NoGuard,
				Response_OK,
				Response_not_OK,
				No_error,
				Retry_less_than_MaxRetry,
				Retry_equals_MaxRetry,
				Idle,
				Not_Idle,
				Tcyc
			};

			virtual void tick(Guard guard) = 0;

			void tm_event() override = 0;

			virtual void MH_Conf_COMx(COMx com_mode) = 0;
			virtual void MH_Conf_PREOPERATE() = 0;
			virtual void MH_Conf_OPERATE() = 0;
			virtual void MH_Conf_INACTIVE() = 0;
			virtual void MH_Conf_Startup() = 0;

			void DL_Read_req(DL_Read::Argument_type* Argument) override = 0;
			void DL_Write_req(DL_Write::Argument_type* Argument) override = 0;
			void DL_ReadParam_req(DL_ReadParam::Argument_type* Argument) override = 0;
			void DL_WriteParam_req(DL_WriteParam::Argument_type* Argument) override = 0;
			void DL_ISDUTransport_req(DL_ISDUTransport::Argument_type* Argument) override = 0;

			void EventFlag_req(EventFlag::Argument_type* Argument) override = 0;
	};
}
