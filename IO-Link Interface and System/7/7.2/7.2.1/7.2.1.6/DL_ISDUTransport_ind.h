#pragma once

#include "components/DL_ISDUTransport.h"

class DL_ISDUTransport_ind__Interface {
	public:
		virtual void DL_ISDUTransport_ind(DL_ISDUTransport::Argument_type* Argument) = 0;
};
