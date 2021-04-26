#pragma once
#include "LSI.h"
typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

class IteratorMD;

class MD {

private:
	/* aici e reprezentarea */
	LSI lista;
	void cauta_nod(const TCheie& c, const TValoare& v, int&prec, int& nod);
public:
	friend class IteratorMD;
	// constructorul implicit al MultiDictionarului
	MD() :lista{} {
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
	IteratorMD iterator() const;

	// destructorul MultiDictionarului	
	~MD() = default;

	int adaugaInexistente(MD& md);

};