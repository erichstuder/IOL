#pragma once

#include "ITimer.h"

namespace State_machine_of_the_Device_message_handler {
	class Administration {
		public:
			Administration(ITimer* timer);

			ITimer* const timer;
	};
}
