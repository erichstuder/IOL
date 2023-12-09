#pragma once

#include "ITimer.h"

class MaxUARTframeTime_timer_mock: public ITimer {
	public:
		void start() override {
			start_called = true;
		}

		void restart() override {
			restart_called = true;
		}

		void reset() override {
			reset_called = true;
		}

		void reset_mock() {
			start_called = false;
			reset_called = false;
		}

		bool start_called;
		bool restart_called;
		bool reset_called;
};

class MaxCycleTime_timer_mock: public ITimer {
	public:
		void start() override {
			start_called = true;
		}
		
		void restart() override {
			restart_called = true;
		}

		void reset() override {
			reset_called = true;
		}

		void reset_mock() {
			start_called = false;
			restart_called = false;
			reset_called = false;
		}

		bool start_called;
		bool restart_called;
		bool reset_called;
};
