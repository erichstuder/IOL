#pragma once

#include "components/DL_WriteParam.h"

class DL_WriteParam_ind__Interface {
	public:
		virtual void DL_WriteParam_ind(DL_WriteParam::Argument_type* Argument) = 0;
};
