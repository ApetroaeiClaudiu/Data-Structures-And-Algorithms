#pragma once
#include "Dictionar.h"
//iterator unidirectional pe un Container
#include <utility>

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

class IteratorDictionar {
	//friend class Multime;
private:
	friend class Dictionar;
	//iteratorul va referi primul element din container
	IteratorDictionar(const Dictionar& dic);
	//contine o referinta catre containerul pe care il itereaza
	const Dictionar& con;
	class LSI* it;
	/* aici e reprezentarea specifica a iteratorului*/
public:
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
