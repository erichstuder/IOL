#pragma once

#include "components/PD.h"

class PD_rsp__Interface {
	public:
		virtual PD::Result_type PD_rsp() = 0;
};
