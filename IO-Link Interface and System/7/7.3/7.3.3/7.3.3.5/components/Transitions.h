#pragma once

#include "ITransitions.h"
#include "Administration.h"

namespace State_machine_of_the_Device_message_handler {
	class Transitions: public ITransitions{
		public:
			Transitions(Administration* administration);
			void T1();
			void T2();
			void T3();
			void T4();
			void T5();
			void T6();
			void T7();
			void T8();
			void T9();
			void T10();
			void T11();
		
		private:
			Administration* const administration;
	};
}
