#pragma once


/*
 * ListaOrdonata.h
 *
 *  Created on: 26 mar. 2019
 *      Author: George
 */

//#ifndef LISTAORDONATA_H_
//#define LISTAORDONATA_H_


//LO.h


//class Nod;

typedef int TComparabil;

typedef TComparabil TElement;

typedef bool(*Relatie)(TElement, TElement);


//typedef Nod* PNod;




#define NULL_TELEMENT -1

class LO;


class IteratorLO;

/*class Nod {
	friend class LO;
	friend class IteratorLO;
private:
	TElement e;
	PNod urm, prec;

public:
	Nod(PNod precedent, TElement e, PNod urmator);

	PNod urmator();
	TElement element();
	PNod precedent();
	//Nod nu are nevoie de destructor - va fi distrus de dictionar
};*/




class LO{
	friend class IteratorLO;
	//friend class Nod;
private:
	/* aici e reprezentarea */
	//PNod primul, ultimul;


	int countElems;

	Relatie relatie;



	int cp;
	TElement* e;
	int* urm;
	int* prec;
	int primul,primulLiber,ultimul;


	void initSpLiber();
	int aloca();
	void dealoca(int i);
	int creeazaNod(TElement e);

public:


	// constructor
	LO (Relatie r);

	// returnare dimensiune
	int dim() const;

	// verifica daca LO e vida
	bool vida() const;

	// prima pozitie din LO
	IteratorLO prim() const;

	// returnare element de pe pozitia curenta
	//arunca exceptie daca poz nu e valid
	TElement element(IteratorLO poz) const;

	// adaugare element in LO
	void adauga(TElement e);

	// sterge element de pe o pozitie poz si returneaza elementul sters
	//dupa stergere poz e pozitionat pe elementul de dupa cel sters
	//arunca exceptie daca poz nu e valid
	TElement sterge(IteratorLO& poz);

	// cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
	IteratorLO cauta(TElement e) const;


	//destructor
	~LO();

};


//#endif /* LISTAORDONATA_H_ */
