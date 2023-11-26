#pragma once

class MaxUARTframeTime_timer_mock: public ITimer {
	public:
		void start() override {
			start_called = true;
		}

		void stop() override {
			stop_called = true;
		}

		void reset() {
			start_called = false;
			stop_called = false;
		}

		bool start_called;
		bool stop_called;
};

class MaxCycleTime_timer_mock: public ITimer {
	public:
		void start() override {
			start_called = true;
		}

		void stop() override {
			stop_called = true;
		}

		void reset() {
			start_called = false;
			stop_called = false;
		}

		bool start_called;
		bool stop_called;
};
