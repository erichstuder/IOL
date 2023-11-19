#pragma once

class ITimer {
	public:
		virtual void start(float time_ms) = 0;
		virtual void stop() = 0;
};
