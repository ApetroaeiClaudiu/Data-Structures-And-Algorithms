#pragma once
#include "IteratorColectie.h"
typedef int TElem;

class Colectie
{
	class pair
	{
	public:
		TElem element;
		//next: -2 =>element is free and is the end of the linked list, -1 =>is the end of the linked list
		int next;
	};
private:
	friend class IteratorColectie;
	/* aici e reprezentarea */
	pair *elements;
	int size;
	int capacity;
	int first_free;
	void resize();
	int next_prime(int capacity);
	bool prime(int number);
	int hash(TElem element) const;
	int next_free();
	unsigned abs(int number)const;

public:
	//constructorul implicit
	Colectie();

	//adauga un element in Colectie
	//returneaza adevarat daca elementul a fost adaugat (nu exista deja in Colectie)
	bool adauga(TElem elem);

	//sterge un element din Colectie
	//returneaza adevarat daca elementul a existat si a fost sters
	bool sterge(TElem elem);

	//verifica daca un element se afla in Colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;

	//intoarce numarul de elemente din Colectie;
	int dim() const;

	//verifica daca Colectiea e vida;
	bool vida() const;

	//returneaza un iterator pe Colectie
	IteratorColectie iterator() const;

	// destructorul multimii
	~Colectie();
};