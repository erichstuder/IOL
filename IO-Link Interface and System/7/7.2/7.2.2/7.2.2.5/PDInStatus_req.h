#pragma once

#include "components/PDInStatus.h"

class PDInStatus_req__Interface {
	public:
		virtual void PDInStatus_req(PDInStatus::Argument_type Argument) = 0;
};
