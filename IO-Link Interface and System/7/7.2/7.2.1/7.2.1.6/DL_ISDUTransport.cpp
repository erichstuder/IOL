#include "DL_ISDUTransport.h"

void DL_ISDUTransport::req(DL_ISDUTransport::Argument_type Argument) {
	(void)Argument;
}

void DL_ISDUTransport::ind(DL_ISDUTransport::Argument_type Argument) {
	(void)Argument;
}

DL_ISDUTransport::Result_type DL_ISDUTransport::rsp() {
	DL_ISDUTransport::Result_type dummy;
	return dummy;
}

DL_ISDUTransport::Result_type DL_ISDUTransport::cnf() {
	DL_ISDUTransport::Result_type dummy;
	return dummy;
}
