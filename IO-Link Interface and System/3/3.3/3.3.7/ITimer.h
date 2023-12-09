#pragma once

class ITimer {
	public:
		virtual void start() = 0;
		virtual void restart() = 0;
		virtual void reset() = 0;
};
