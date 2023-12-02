#pragma once

#include "components/DL_Read.h"

class DL_Read_ind__Interface {
	public:
		virtual void DL_Read_ind(DL_Read::Argument_type* Argument) = 0;
};
