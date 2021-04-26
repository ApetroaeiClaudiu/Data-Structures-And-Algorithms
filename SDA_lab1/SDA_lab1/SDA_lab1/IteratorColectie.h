#pragma once
typedef int TElem;

typedef struct TElem_pair {
	TElem element;
	int frequency;
}TElem_pair;

class IteratorColectie {
private:
	int current_dim = 0;
	TElem_pair *iterator_data;
	int iterator_data_size;
	int iterator_data_capacity;
public:
	//creeaza un iterator pentru colectia c
	IteratorColectie(TElem_pair *data,int size,int capacity);
	//returneaza True daca iteratorul este valid, False altfel
	bool valid();

	//returneaza elementul curent din iterator
	TElem element();

	//muta iteratorul la urmatorul element
	void urmator();


	//seteaza iteratorul la primul element
	void prim();
};
