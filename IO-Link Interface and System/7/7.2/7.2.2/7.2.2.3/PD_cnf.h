#pragma once

#include "components/PD.h"

class PD_cnf__Interface {
	public:
		virtual PD::Result_type PD_cnf() = 0;
};
