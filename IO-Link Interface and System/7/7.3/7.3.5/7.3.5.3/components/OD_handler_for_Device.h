#pragma once

#include "OD_ind.h"

class OD_handler_for_Device: public OD_ind__Interface
{
	public:
		void OD_ind(OD::Argument_type Argument) override = 0;
};
