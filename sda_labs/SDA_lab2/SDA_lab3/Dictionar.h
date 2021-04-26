#pragma once
#include <iostream>
#include <utility>
#include "IteratorDictionar.h"
using namespace std;

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

class LSI {
public:
	TElem element;
	class LSI* next;
};

#define NULL_TVALOARE -1

class Dictionar {

private:
	friend class IteratorDictionar;
	/* aici e reprezentarea */
	LSI* head =NULL;
public:
	// constructorul implicit al dictionarului
	Dictionar() =default;

	// adauga o pereche (cheie, valoare) in dictionar	
	//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
	// daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
	TValoare adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
	TValoare cauta(TCheie c) const;

	//sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
	TValoare sterge(TCheie c);

	//returneaza numarul de perechi (cheie, valoare) din dictionar 
	int dim() const;

	//verifica daca dictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe dictionar
	IteratorDictionar iterator();


	// destructorul dictionarului	
	~Dictionar();

};