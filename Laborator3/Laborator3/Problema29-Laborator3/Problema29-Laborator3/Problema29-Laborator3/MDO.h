#pragma once
#include<iostream>
#include<vector>
#include "IteratorMDO.h"

using namespace std;

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

typedef bool(*Relatie)(TCheie, TCheie);




class nodValoare
{
public:
	class nodValoare* urmatorValoare;
	TValoare valoare;
};

class nodCheie
{
public:
	class nodCheie* urmatorCheie;
	class nodValoare* urmatorValoare;
	TCheie cheie;
};


class MDO {

private:
	friend class IteratorMDO;
	Relatie r;
	nodCheie* head;

	/* aici e reprezentarea */
public:

	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//returneaza un vector care sa contina toate cheile
	vector<TCheie> multimeChei() const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile ordine dupa relatia de ordine
	IteratorMDO iterator();

	// destructorul 	
	~MDO();



};
