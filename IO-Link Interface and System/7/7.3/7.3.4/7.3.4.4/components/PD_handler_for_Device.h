#pragma once

#include "PD_ind.h"

class PD_handler_for_Device: public PD_ind__Interface
{
	public:
		void PD_ind(PD::Argument_type Argument) override = 0;
};
