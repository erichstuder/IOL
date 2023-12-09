#pragma once

#include "components/OD.h"

class OD_req__Interface {
	public:
		virtual void OD_req(OD::Argument_type Argument) = 0;
};
