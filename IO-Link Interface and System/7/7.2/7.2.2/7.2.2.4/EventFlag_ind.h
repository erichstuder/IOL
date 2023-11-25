#pragma once

#include "components/EventFlag.h"

class EventFlag_ind__Interface {
	public:
		virtual void EventFlag_ind(EventFlag::Argument_type Argument) = 0;
};
