#pragma once
#include "Multime.h"
//iterator unidirectional pe un Container
typedef int TElem;

//class Multime;

class IteratorMultime {
	//friend class Multime;
private:
	/* aici e reprezentarea specifica a iteratorului*/
	TElem *elements;
	int current = 0;
	int iterator_size ;
	int iterator_cap ;
public:
	//iteratorul va referi primul element din container
	IteratorMultime(TElem *data, int size, int cap);
	//reseteaza pozitia iteratorului la inceputul containerului
	void prim();
	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator();
	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid();
	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	TElem element();
};
