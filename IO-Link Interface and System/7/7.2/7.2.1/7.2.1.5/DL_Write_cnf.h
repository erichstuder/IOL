#pragma once

#include "components/DL_Write.h"

class DL_Write_cnf__Interface {
	public:
		virtual DL_Write::Result_type DL_Write_cnf() = 0;
};
