#include "IteratorVectorDinamic.h"
#include "VectorDinamic.h"


IteratorVectorDinamic::IteratorVectorDinamic(const VectorDinamic& c) : referintaVector{c} {

	pozitie = 0;
}


TElem IteratorVectorDinamic::element()
{
	return referintaVector.x[pozitie];
}

bool IteratorVectorDinamic::valid() {
	
	if (pozitie < referintaVector.dim())
	{
		return true;
	}
	return false;
}

void IteratorVectorDinamic::urmator() {
	pozitie++;
}

void IteratorVectorDinamic::prim() {
	pozitie = 0;
}
