#include "MD.h"
#include "IteratorMD.h"

IteratorContainer::IteratorContainer(const MD& md) :c{ md }, curent{ md.l.get_prim() }{

}

void IteratorContainer::prim()
{
	curent = c.l.get_prim();
}

void IteratorContainer::urmator()
{
	if (!valid()) {
		throw(std::exception("Nu"));
	}
	curent = c.l.urmator(curent);
}

bool IteratorContainer::valid() const
{
	return curent != -1;
}

TElem IteratorContainer::element() const
{
	return std::make_pair(c.l.c(curent), c.l.v(curent));
}
