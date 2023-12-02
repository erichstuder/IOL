#pragma once

#include "components/DL_Read.h"

class DL_Read_rsp__Interface {
	public:
		virtual DL_Read::Result_type DL_Read_rsp() = 0;
};
