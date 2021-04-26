#pragma once
#include "LSI.h"
typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

class IteratorContainer;

class MD {

private:
	LSI l;
	void cauta_nod(const TCheie& c, const TValoare& v, int& prec, int& nod);
public:
	friend class IteratorContainer;

	// constructorul implicit al MultiDictionarului
	MD() :l{} {
	}

	// adauga o pereche (cheie, valoare) in MD	
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	std::vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MD 
	int dim() const;

	//verifica daca MultiDictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe MD
	IteratorContainer iterator() const;

	//returneaza un vector cu toate valorile din multidictionar
	std::vector<TValoare> colectiaValorilor() const;

	// destructorul MultiDictionarului	
	~MD() = default;
};