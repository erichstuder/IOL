#pragma once

#include "components/DL_ReadParam.h"

class DL_ReadParam_req__Interface {
	public:
		virtual void DL_ReadParam_req(DL_ReadParam::Argument_type* Argument) = 0;
};
