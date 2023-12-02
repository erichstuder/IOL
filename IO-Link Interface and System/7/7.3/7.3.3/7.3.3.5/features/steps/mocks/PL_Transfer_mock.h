#pragma once

#include "PL_Transfer_for_Device.h"

class PL_Transfer_mock:	public PL_Transfer_for_Device__Message_handler_Interface
{
	public:
		void PL_Transfer_req(uint8_t Data) override {
			(void)Data;
			req_called = true;
		}

		void PL_Transfer_rsp() override {
			rsp_called = true;
		}

		void reset_mock() {
			req_called = false;
			rsp_called = false;
		}

		bool req_called;
		bool rsp_called;
};
