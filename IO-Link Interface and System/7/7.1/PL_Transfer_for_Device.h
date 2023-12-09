#pragma once

#include "PL_Transfer_req.h"
#include "PL_Transfer_rsp.h"

class PL_Transfer_for_Device__Message_handler_Interface:
	public PL_Transfer_req__Interface,
	public PL_Transfer_rsp__Interface
{
	public:
		void PL_Transfer_req(uint8_t Data) override = 0;
		void PL_Transfer_rsp() override = 0;
};
