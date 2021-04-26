#include "LSI.h"
#include "MD.h"
#include "IteratorMD.h"

IteratorMD::IteratorMD(const MD& md) :c{ md }, curent{ md.lista.get_prim() }{}

void IteratorMD::prim(){
	curent = c.lista.get_prim();
}

void IteratorMD::urmator(){
	if (!valid()) {
		throw(std::exception("Nevalid"));
	}
	curent = c.lista.urmator(curent);
}

bool IteratorMD::valid() const{
	return curent != -1;
}

TElem IteratorMD::element() const{
	return std::make_pair(c.lista.c(curent), c.lista.v(curent));
}
