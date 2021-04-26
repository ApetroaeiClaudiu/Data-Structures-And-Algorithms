#include "TestScurt.h"
#include "MD.h"
#include "IteratorMD.h"
#include <assert.h>
#include <vector>
#include<iostream>
using namespace std;

void testAll() {
	MD m;
	m.adauga(1, 100);
	m.adauga(2, 200);
	m.adauga(3, 300);
	m.adauga(1, 500);
	m.adauga(2, 600);
	m.adauga(4, 800);

	assert(m.dim() == 6);

	assert(m.sterge(5, 600) == false);
	assert(m.sterge(1, 500) == true);

	assert(m.dim() == 5);

	vector<TValoare> v;
	v = m.cauta(6);
	assert(v.size() == 0);

	v = m.cauta(1);
	assert(v.size() == 1);

	assert(m.vid() == false);

	IteratorMD im = m.iterator();
	assert(im.valid() == true);
	while (im.valid()) {
		im.element();
		im.urmator();
	}
	assert(im.valid() == false);
	im.prim();
	assert(im.valid() == true);
}

void test_func() {
	MD m1;
	MD m2; 
	m1.adauga(1, 100);
	m1.adauga(2, 200);
	m1.adauga(3, 300);
	m1.adauga(1, 500);
	m1.adauga(2, 600);
	m1.adauga(4, 800);

	m2.adauga(8, 7);
	m2.adauga(4, 2);
	m2.adauga(3, 300);
	m2.adauga(4, 800);
	m2.adauga(5, 6);

	auto x = m1.adaugaInexistente(m2);
	cout << x << " ";
	assert(x == 3); 

	/*
	IteratorMD im = m1.iterator();
	assert(im.valid() == true);
	while (im.valid()) {
		im.element();
		cout << im.element().first << " " << im.element().second << '\n';
		im.urmator();
	}
	*/
}
