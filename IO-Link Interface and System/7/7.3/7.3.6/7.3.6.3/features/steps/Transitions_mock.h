#pragma once

#include <gmock/gmock.h>
#include "Transitions.h"

namespace State_machine_of_the_Master_ISDU_handler {
	class Transitions_mock : public Transitions {
		public:
			MOCK_METHOD(void,  T1, (), (override));
			MOCK_METHOD(void,  T2, (), (override));
			MOCK_METHOD(void,  T3, (), (override));
			MOCK_METHOD(void,  T4, (), (override));
			MOCK_METHOD(void,  T5, (), (override));
			MOCK_METHOD(void,  T6, (), (override));
			MOCK_METHOD(void,  T7, (), (override));
			MOCK_METHOD(void,  T8, (), (override));
			MOCK_METHOD(void,  T9, (), (override));
			MOCK_METHOD(void,  T10, (), (override));
			MOCK_METHOD(void,  T11, (), (override));
			MOCK_METHOD(void,  T12, (), (override));
			MOCK_METHOD(void,  T13, (), (override));
			MOCK_METHOD(void,  T14, (), (override));
			MOCK_METHOD(void,  T15, (), (override));
			MOCK_METHOD(void,  T16, (), (override));
			MOCK_METHOD(void,  T17, (), (override));
			MOCK_METHOD(void,  T18, (), (override));
			MOCK_METHOD(void,  T19, (), (override));
	};
}
