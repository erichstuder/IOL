#pragma once

#include "components/PDInStatus.h"

class PDInStatus_ind__Interface {
	public:
		virtual void PDInStatus_ind(PDInStatus::Argument_type Argument) = 0;
};
