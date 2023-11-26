#pragma once

#include "PD_handler_for_Device.h"

class PD_handler_mock:
	public PD_handler_for_Device
{
	public:
		void PD_ind(PD::Argument_type Argument) override {
			(void)Argument;
			ind_called = true;
		}

		void reset() {
			ind_called = false;
		}

		bool ind_called;
};
