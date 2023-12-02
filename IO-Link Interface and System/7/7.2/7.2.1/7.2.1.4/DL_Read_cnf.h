#pragma once

#include "components/DL_Read.h"

class DL_Read_cnf__Interface {
	public:
		virtual DL_Read::Result_type DL_Read_cnf() = 0;
};
