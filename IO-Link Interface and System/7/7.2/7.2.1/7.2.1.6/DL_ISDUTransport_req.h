#pragma once

#include "components/DL_ISDUTransport.h"

class DL_ISDUTransport_req__Interface {
	public:
		virtual void DL_ISDUTransport_req(DL_ISDUTransport::Argument_type* Argument) = 0;
};
