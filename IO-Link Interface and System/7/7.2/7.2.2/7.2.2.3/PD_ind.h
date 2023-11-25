#pragma once

#include "components/PD.h"

class PD_ind__Interface {
	public:
		virtual void PD_ind(PD::Argument_type Argument) = 0;
};
