#include "Multime.h"
//#include "IteratorMultime.h"
//#include <iostream>

//complexitate O(n^2)
bool Multime::adauga(TElem e) {
	int ok = 0;
	//cautarea elementului
	int pos = search(e);
	if (pos == -1) {
		if (size == cap) {
			if (cap == 0)
				cap = 1;
			cap *= 2;
			//realocare de memorie
			TElem* newEL = new TElem[cap];
			for (int i = 0; i < size; ++i)
				newEL[i] = data[i];
			delete data;
			data = newEL;
		}
		int i;
		for ( i = 0; i < size; i++) 
			if (!rel(data[i], e)) {
				for (int j = size; j > i; --j)
					data[j] = data[j - 1];
				break;
			}
		data[i] = e;
		size++;
		ok = 1;
	}
	if (ok == 1)
		return true;
	return false;
}

//complexitate O(log n)
bool Multime::sterge(TElem e) {
	int pos = search(e);
	if (pos == -1) {
		return false;
	}
	for (int i = pos; i < size-1; i++) {
		data[i] = data[i + 1];
	}
	--size;
	return true;
}

//complexitate O(log n)
bool Multime::cauta(TElem e) const {
	if (search(e) == -1) {
		return false;
	}
	return true;
}

//complexitate O(1)
int Multime::dim() const {
	return size;
}

//complexitate O(1)
bool Multime::vida() const {
	if (size == 0)
		return true;
	return false;
}

//complexitate tetha(n*m)
Multime Multime::Intersectie(Multime a, Multime b) {
	Multime m;
	for (int i = 0; i < a.size; i++)
		for (int j = 0; j < b.size; j++)
			if (a.data[i] == b.data[j]) {
				m.adauga(a.data[i]);
				break;
			}
	return m;
}


IteratorMultime Multime::iterator() const {
	return IteratorMultime(data, size, cap);
}

//complexitate O(1)
Multime::~Multime() {
	delete data;
	size = 0;
	cap = 0;
}

//complexitate O(log n)
int Multime::search(TElem e) const {
	int left = 0, right = size - 1;
	while (left <= right){
		int middle = (left + right) / 2;
		if (data[middle] == e){
			return middle;
		}
		else if (data[middle] < e){
			left = middle + 1;
		}
		else if (data[middle] > e){
			right = middle - 1;
		}
	}
	return -1;
}

//complexitate O(1)
bool rel(TElem el1, TElem el2) {
	return el1 <= el2;
}	