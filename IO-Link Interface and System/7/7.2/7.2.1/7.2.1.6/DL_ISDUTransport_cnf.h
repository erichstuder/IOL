#pragma once

#include "components/DL_ISDUTransport.h"

class DL_ISDUTransport_cnf__Interface {
	public:
		virtual DL_ISDUTransport::Result_type DL_ISDUTransport_cnf() = 0;
};
