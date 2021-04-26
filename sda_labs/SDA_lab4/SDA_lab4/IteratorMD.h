#pragma once
#include "MD.h"

//iterator unidirectional pe un Container
class IteratorMD {
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMD(const MD& md);

	//contine o referinta catre containerul pe care il itereaza
	const MD& c;

	/* aici e reprezentarea specifica a iteratorului*/
	int curent;
public:
	friend class MD;

	//reseteaza pozitia iteratorului la inceputul containerului
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	TElem element() const;

};

