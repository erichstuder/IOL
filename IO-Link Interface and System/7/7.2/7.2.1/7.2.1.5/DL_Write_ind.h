#pragma once

#include "components/DL_Write.h"

class DL_Write_ind__Interface {
	public:
		virtual void DL_Write_ind(DL_Write::Argument_type* Argument) = 0;
};
