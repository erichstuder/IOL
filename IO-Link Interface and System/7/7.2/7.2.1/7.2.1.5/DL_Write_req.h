#pragma once

#include "components/DL_Write.h"

class DL_Write_req__Interface {
	public:
		virtual void DL_Write_req(DL_Write::Argument_type* Argument) = 0;
};
