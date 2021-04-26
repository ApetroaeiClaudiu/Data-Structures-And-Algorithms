//MDO.h

#include <vector>

using std::pair;
using std::vector;

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

typedef bool(*Relatie)(TCheie, TCheie);

class IteratorMDO;

class Node
{
public:
	Node(const TElem &val) : val(val), lf(nullptr), rg(nullptr) {}
	TCheie key() const
	{
		return val.first;
	}

	TValoare value() const
	{
		return val.second;
	}

	TElem val;
	Node *lf;
	Node *rg;
};

class MDO {
	friend class IteratorMDO;
private:
	Relatie r;
	Node *root;
	/* aici e reprezentarea */
public:

	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	Node* add(Node *root, TCheie c, TValoare v);
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	void find(Node *root, TCheie c, vector <TValoare> &ret) const;
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	Node* get_max_postorder(Node* root) const;
	Node* remove(Node* root, TCheie c, TValoare v, bool &deleted);
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	int get_dim(Node *root) const;
	int dim() const;

	void get_elems_inorder(Node* root, vector <TElem> &ret) const;
	vector <TElem> get_elems_inorder() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile ordine dupa relatia de ordine
	IteratorMDO iterator() const;

	// destructorul 	
	~MDO() {}



};

//iterator unidirectional pe un Container
class IteratorMDO {
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	
	//contine o referinta catre containerul pe care il itereaza
	vector <TElem> elems;
	int p = 0;
	const MDO& c;

	/* aici e reprezentarea specifica a iteratorului*/

public:
	IteratorMDO(const MDO& c);
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
