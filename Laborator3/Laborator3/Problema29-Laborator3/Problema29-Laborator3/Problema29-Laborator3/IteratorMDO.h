#pragma once
#include <utility>
#include "MDO.h"


typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

typedef bool(*Relatie)(TCheie, TCheie);

//iterator unidirectional pe un Container
class IteratorMDO {
private:
	friend class MDO;
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMDO(const MDO& c);

	//contine o referinta catre containerul pe care il itereaza
	const MDO& con;
	class nodCheie *itNodCheie;
	class nodValoare *itNodValoare;

	/* aici e reprezentarea specifica a iteratorului*/

public:

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
