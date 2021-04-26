#include "MDO.h"
#include <vector>
using namespace std;



vector<TCheie> MDO::multimeChei() const
{
	nodCheie *auxNodCheie = head->urmatorCheie;
	vector<TCheie> v;
	while (auxNodCheie != NULL)
	{
		v.push_back(auxNodCheie->cheie);
		auxNodCheie = auxNodCheie->urmatorCheie;
	}
	return v;
}

MDO::MDO(Relatie r)
{
	this->r = r;
	this->head = new nodCheie;
	this->head->urmatorCheie = NULL;
	this->head->urmatorValoare = NULL;
	this->head->cheie = -1;
}

//O(n), n nr de noduri cheie
void MDO::adauga(TCheie c, TValoare v)
{
	nodCheie *auxNodCheie = this->head;
	
	//creez nodul valoare care trebuie adaugat in dictionar
	nodValoare *nodValoareNou = new nodValoare;
	nodValoareNou->valoare = v;
	nodValoareNou->urmatorValoare = NULL;

	//incerc sa adaug nodul valoare in dictionar la un nod cheie deja existent
	while (auxNodCheie != NULL)	//parcurg toate nodurile cheie
	{
		if (auxNodCheie->cheie == c)	//daca este gasita cheia in dictionar
		{
			nodValoare *auxNodValoare = auxNodCheie->urmatorValoare;
			//cum arata
			// auxNodCheie->urmatorValoare ----> auxNodValoare ----> auxNodValoare->urmatorValoare
			
			nodValoareNou->urmatorValoare = auxNodValoare;
			auxNodCheie->urmatorValoare = nodValoareNou;

			//cum va arata
			// auxNodCheie->urmatorValoare ----> nodValoareNou ----> auxNodValoare ----> auxNodValoare->urmatorValoare
			return;
		}
		auxNodCheie = auxNodCheie->urmatorCheie;
	}

	//nu am reusit sa adaug nodul valoare la un nod cheie deja existent
	//asa ca voi crea un nou nod cheie care va contine nodul valoare
	nodCheie *precedentNodCheie = NULL;
	
	//creez nodul cheie
	nodCheie *nodCheieNou = new nodCheie;
	nodCheieNou->urmatorValoare = nodValoareNou;
	nodCheieNou->urmatorCheie = NULL;
	nodCheieNou->cheie = c;

	//parcurg toate nodurile cheie cu scopul de a ma plasa dupa un nod ales
	auxNodCheie = this->head;
	precedentNodCheie = this->head;

	while (auxNodCheie != NULL && this->r(auxNodCheie->cheie, c) == true)
	{
		precedentNodCheie = auxNodCheie;
		auxNodCheie = auxNodCheie->urmatorCheie;
	}
	//cum arata
	//precedentNodCheie
	//		|
	//auxNodCheie

	nodCheieNou->urmatorCheie = auxNodCheie;
	precedentNodCheie->urmatorCheie = nodCheieNou;

	//cum va arata
	//precedentNodCheie
	//		|
	//nodCheienou
	//		|
	//auxNodCheie
}


vector<TValoare> MDO::cauta(TCheie c) const
{
	vector<TValoare> v;
	nodCheie *auxNodCheie = this->head;
	while (auxNodCheie != NULL && auxNodCheie->cheie != c)
	{
		auxNodCheie = auxNodCheie->urmatorCheie;
	}

	if (auxNodCheie == NULL)
	{
		//ii bai!!!
		//cheia nu a fost gasita in dictionar
		return v;
	}
	
	//cheia a fost gasita in dicitionar
	if (auxNodCheie->cheie == c)
	{
		nodValoare *auxNodValoare = auxNodCheie->urmatorValoare;
		while (auxNodValoare != NULL)	//se parcurg toate nodurile valoare si se baga in vector
		{
			v.push_back(auxNodValoare->valoare);
			auxNodValoare = auxNodValoare->urmatorValoare;
		}
		return v;
	}
	return v;
}


bool MDO::sterge(TCheie c, TValoare v)
{
	nodCheie *auxNodCheie = this->head;
	nodCheie *precedentNodCheie = this->head;
	
	//caut cheia in dictionar
	while (auxNodCheie != NULL && auxNodCheie->cheie != c)	
	{
		precedentNodCheie = auxNodCheie;
		auxNodCheie = auxNodCheie->urmatorCheie;
	}

	// daca s-a gasit cheia in dictionar
	if (auxNodCheie != NULL && auxNodCheie->cheie == c)
	{
		nodValoare *auxNodValoare = auxNodCheie->urmatorValoare;
		nodValoare *precedentNodValoare = auxNodCheie->urmatorValoare;

		//caut valoarea in dictionar
		while (auxNodValoare != NULL && auxNodValoare->valoare != v)
		{
			precedentNodValoare = auxNodValoare;
			auxNodValoare = auxNodValoare->urmatorValoare;
		}

		//daca s-a gasit valoarea in dictionar
		if (auxNodValoare != NULL && auxNodValoare->valoare == v)
		{
			//daca este prima valoare din lista de valori
			if (precedentNodValoare == auxNodValoare)
			{
				//cum arata
				//auxNodCheie->urmatorValoare ----> auxNodValoare ----> auxNodValoare->urmatorValoare

				auxNodCheie->urmatorValoare = auxNodValoare->urmatorValoare;
				delete auxNodValoare;

				//cum va arata
				//auxNodCheie->urmatorValoare ----> auxNodValoare->urmatorValoare
			}
			else //daca nu este prima valoare din lista de valori
			{
				//cum arata
				//precedentNodValoare ----> auxNodValoare ----> auxNodValoare->urmatorValoare

				precedentNodValoare->urmatorValoare = auxNodValoare->urmatorValoare;
				delete auxNodValoare;

				//cum va arata
				//precedentNodValoare ----> auxNodValoare->urmatorValoare

			}

			//daca nodul cheie a ramas fara valori
			if (auxNodCheie->urmatorValoare == NULL)
			{
				//cum arata
				//precedentNodCheie
				//		|
				//auxNodCheie
				//		|
				//auxNodCheie->urmatorCheie

				precedentNodCheie->urmatorCheie = auxNodCheie->urmatorCheie;
				delete auxNodCheie;

				//cum va arata
				//precedentNodCheie
				//		|
				//auxNodCheie->urmatorCheie
			}
			return true;
		}
		return false;
	}
	return false;
}

int MDO::dim() const
{
	nodCheie *auxNodCheie = this->head->urmatorCheie;
	nodValoare *auxNodValoare;
	int contor = 0;

	//parcurg toate cheile
	while (auxNodCheie != NULL)
	{
		auxNodValoare = auxNodCheie->urmatorValoare;
		//parcurg toate valorile din fiecare cheie
		while (auxNodValoare != NULL)
		{
			contor++;
			auxNodValoare = auxNodValoare->urmatorValoare;
		}
		auxNodCheie = auxNodCheie->urmatorCheie;
	}
	return contor;
}

bool MDO::vid() const
{
	if (dim() == 0)
		return true;
	return false;
}

IteratorMDO MDO::iterator()
{
	return IteratorMDO(*this);
}


MDO::~MDO()
{
	nodCheie *auxNodCheie = this->head;
	nodCheie *precedentNodCheie;

	nodValoare *auxNodValoare;
	nodValoare *precedentNodValoare;

	//parcurg toate cheile
	while (auxNodCheie != NULL)
	{
		auxNodValoare = auxNodCheie->urmatorValoare;

		//parcurg toate valorile din fiecare cheie
		while (auxNodValoare != NULL)
		{
			precedentNodValoare = auxNodValoare;
			auxNodValoare = auxNodValoare->urmatorValoare;
			delete precedentNodValoare;
		}
		precedentNodCheie = auxNodCheie;
		auxNodCheie = auxNodCheie->urmatorCheie;
		delete precedentNodCheie;
	}
}



