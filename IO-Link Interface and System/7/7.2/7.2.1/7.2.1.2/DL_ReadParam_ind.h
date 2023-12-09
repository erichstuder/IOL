#pragma once

#include "components/DL_ReadParam.h"

class DL_ReadParam_ind__Interface {
	public:
		virtual void DL_ReadParam_ind(DL_ReadParam::Argument_type* Address) = 0;
};
