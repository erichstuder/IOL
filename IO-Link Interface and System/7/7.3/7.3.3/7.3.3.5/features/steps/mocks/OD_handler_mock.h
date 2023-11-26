#pragma once

#include "OD_handler_for_Device.h"

class OD_handler_mock:
	public OD_handler_for_Device
{
	public:
		void OD_ind(OD::Argument_type Argument) override {
			(void)Argument;
			ind_called = true;
		}

		void reset() {
			ind_called = false;
		}

		bool ind_called;
};
