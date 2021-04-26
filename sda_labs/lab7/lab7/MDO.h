//MDO.h
#pragma once
#include <vector>
#include "IteratorMDO.h"
using namespace std;
class IteratorMDO;

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

typedef bool(*Relatie)(TCheie, TCheie);

bool rel(TCheie, TCheie);


class Nod {
public:
	vector<int> vect;
	TElem element;
	Nod *st, *dr, *parinte;

	Nod(TCheie c, TValoare v){	
		element.first = c;
		element.second = v;
		st = dr = parinte = nullptr;
	}

	~Nod(){
		element.first = 0;
		element.second = 0;
		st = dr = parinte = nullptr;
	}
};

class MDO {

private:
	friend IteratorMDO;
	Nod *rad;
	Relatie r;

	int get_dim(Nod *rad) const;
	Nod* add(Nod* rad, TCheie c, TValoare v);
	Nod* max_postordine(Nod* rad)const;
	Nod* sterge_rec(Nod *arbore, TCheie c,TValoare v,bool& sters);
	void cauta_rec(Nod *rad, TCheie c, vector <TValoare> &rez) const;
	void elemente_inordine(Nod* rad, vector <TElem> &rez) const;
	vector <TElem> lista_elemente() const;
	/* aici e reprezentarea */
public:
	//Nod* sterge_valori(Nod *rad, TCheie c, vector<TValoare> &rez,bool& sters);
	vector<TValoare> stergeValoriPentruCheie(TCheie cheie);
	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie rel);
	// adauga o pereche (cheie, valoare) in MDO
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile ordine dupa relatia de ordine
	IteratorMDO iterator() const;

	// destructorul 	
	~MDO();



};
