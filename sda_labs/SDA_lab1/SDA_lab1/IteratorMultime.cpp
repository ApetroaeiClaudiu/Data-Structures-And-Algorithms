#include "IteratorMultime.h"
#include "Multime.h"

//complexitate O(1)
IteratorMultime::IteratorMultime(TElem *data,int size,int cap) {
	elements = data;
	iterator_size = size;
	iterator_cap = cap;
}
	
//complexitatea O(1)
void IteratorMultime::prim() {
	current = 0;
}

//complexitate O(1)
void IteratorMultime::urmator() {
	current++;
}

//complexitate O(n)
bool IteratorMultime::valid() {
	int dim = 0;
	for (int i = 0; i < iterator_size; i++)
		dim = dim + 1;
	if (dim > current)
		return true;
	return false;
}

//complexitate O(n)
TElem IteratorMultime::element() {
	int dim = -1;
	for (int i = 0; i < iterator_size; i++) {
		dim++;
		if (current == dim)
			return elements[i];
	}
	return -1;
}



