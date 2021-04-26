#pragma once
#include "IteratorColectie.h"
typedef int TElem;

typedef bool(*Relatie) (TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

//interfata colectiei nu se modifica
class Colectie {
private:
	/* aici e reprezentarea */
	TElem_pair *data = nullptr;
	int size = 0;
	int capacity = 0;

public:
	//constructorul implicit
	Colectie() = default;

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;

	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//binary search
	int binarysearch(TElem e) const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;


	// destructorul colectiei
	~Colectie();

};
