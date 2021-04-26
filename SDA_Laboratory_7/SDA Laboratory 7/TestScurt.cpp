#include <assert.h>

#include "MDO.h"

#include <exception>
#include <vector>

using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

#include <iostream>

void test_vali()
{
	MDO mdo(relatie1);
	mdo.adauga(1, 1);
	mdo.adauga(1, 2);
	mdo.adauga(2, 1);
	mdo.adauga(0, 1);
	mdo.sterge(1, 1);
	assert(mdo.dim() == 3);
}

void testAll() {
	test_vali();
	MDO dictOrd = MDO(relatie1);
	assert(dictOrd.dim() == 0);
	assert(dictOrd.vid());
	dictOrd.adauga(1, 2);
	dictOrd.adauga(1, 3);
	assert(dictOrd.dim() == 2);
	assert(!dictOrd.vid());
	vector<TValoare> v = dictOrd.cauta(1);
	assert(v.size() == 2);
	v = dictOrd.cauta(3);
	assert(v.size() == 0);
	IteratorMDO it = dictOrd.iterator();
	it.prim();
	while (it.valid()) {
		TElem e = it.element();
		it.urmator();
	}
	assert(dictOrd.sterge(1, 2) == true);
	assert(dictOrd.sterge(1, 3) == true);
	assert(dictOrd.sterge(2, 1) == false);
	assert(dictOrd.vid());
}
