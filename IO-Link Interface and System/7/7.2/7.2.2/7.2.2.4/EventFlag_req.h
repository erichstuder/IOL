#pragma once

#include "components/EventFlag.h"

class EventFlag_req__Interface {
	public:
		virtual void EventFlag_req(EventFlag::Argument_type* Argument) = 0;
};
