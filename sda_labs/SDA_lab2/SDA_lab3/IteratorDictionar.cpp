#include "IteratorDictionar.h"
#include "Dictionar.h"
#include <iostream>
#include <utility>
using namespace std;

//complexitate O(1)
IteratorDictionar::IteratorDictionar(const Dictionar& dic):con(dic) {
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

//complexitate O(n)
bool IteratorDictionar::valid() {
	if (it == NULL) {
		return false;
	}
	return true;
}

//complexitate O(n)
TElem IteratorDictionar::element() {
	return make_pair(it->element.first, it->element.second);
}



