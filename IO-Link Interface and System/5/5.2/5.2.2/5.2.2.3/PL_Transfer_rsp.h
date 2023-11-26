#pragma once

#include <cstdint>

class PL_Transfer_rsp__Interface {
	public:
		//not defined in this chapter but in other parts of the specification
		virtual void PL_Transfer_rsp() = 0;
};
