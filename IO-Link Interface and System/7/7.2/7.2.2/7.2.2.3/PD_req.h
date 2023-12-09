#pragma once

#include "components/PD.h"

class PD_req__Interface {
	public:
		virtual void PD_req(PD::Argument_type Argument) = 0;
};
