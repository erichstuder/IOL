#pragma once

#include "MHInfo_ind.h"

class DL_mode_handler_mock:
	public MHInfo_ind__Interface
{
	public:
		void MHInfo_ind(MHInfo::Argument_type Argument) override {
			(void)Argument;
			ind_called = true;
		}

		void reset_mock() {
			ind_called = false;
		}

		bool ind_called;
};
