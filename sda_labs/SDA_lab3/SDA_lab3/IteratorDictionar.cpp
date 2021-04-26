#include "IteratorDictionar.h"
#include "Dictionar.h"
#include <iostream>
#include <utility>
using namespace std;

//complexitate O(1)
IteratorDictionar::IteratorDictionar(const Dictionar& dic) :con(dic) {
	prim();
}

//complexitatea O(1)
void IteratorDictionar::prim() {
	it = con.head;
}

//complexitate O(1)
void IteratorDictionar::urmator() {
	it = it->next;
	if (it == NULL) {
		return;
	}
}

//complexitate O(1)
bool IteratorDictionar::valid() {
	if (it == NULL) {
		return false;
	}
	return true;
}

//complexitate O(1)
TElem IteratorDictionar::element() {
	return make_pair(it->element.first, it->element.second);
}

//complexitate O(k)
void IteratorDictionar::avanseazaKPasi(int k) {
	if (k <= 0) {
		throw exception();
	}
	for (int i = 1; i <= k; i++) {
		it = it->next;
		if (it == NULL) {
			throw exception();
		}
	}

}

