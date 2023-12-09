#pragma once

#include "components/DL_ReadParam.h"

class DL_ReadParam_rsp__Interface {
	public:
		virtual DL_ReadParam::Result_type DL_ReadParam_rsp() = 0;
};

