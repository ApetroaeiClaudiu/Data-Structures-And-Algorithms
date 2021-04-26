#pragma once
#include<stack>
#include<vector>
using namespace std;

class MDO;
class Nod;
typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

typedef bool(*Relatie)(TCheie, TCheie);

bool rel(TCheie, TCheie);

//iterator unidirectional pe un Container
class IteratorMDO {
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container

	//contine o referinta catre containerul pe care il itereaza
	vector <TElem> elemente;
	int curent = 0;
	const MDO& mdo;

	/* aici e reprezentarea specifica a iteratorului*/

public:

	IteratorMDO(const MDO& mdo);

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
