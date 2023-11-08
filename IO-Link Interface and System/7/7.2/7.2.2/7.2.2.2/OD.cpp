#include "OD.h"

void OD::req(OD::Argument_type Argument) {
	(void)Argument;
}

void OD::ind(OD::Argument_type Argument) {
	(void)Argument;
}

OD::Result_type OD::rsp() {
	OD::Result_type dummy(18);
	return dummy;
}

OD::Result_type OD::cnf() {
	OD::Result_type dummy(23);
	return dummy;
}
