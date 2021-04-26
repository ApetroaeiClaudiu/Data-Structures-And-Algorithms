#include "IteratorMDO.h"
#include <iostream>
#include <utility>
using namespace std;

IteratorMDO::IteratorMDO(const MDO& c) : con(c)
{
	prim();
}

//IteratorMDO::IteratorMDO(const MDO& c) : this->con(c)
//{
//	this->con = c;
//}


void IteratorMDO::prim()
{
	itNodCheie = con.head->urmatorCheie;
	if (itNodCheie != NULL)
		itNodValoare = itNodCheie->urmatorValoare;
}

void IteratorMDO::urmator()
{
	itNodValoare = itNodValoare->urmatorValoare;
	if (itNodValoare == NULL)
	{
		itNodCheie = itNodCheie->urmatorCheie;
		if (itNodCheie == NULL)
		{
			//ii bai, arunca exceptie
			return;
		}
		itNodValoare = itNodCheie->urmatorValoare;
	}
}

bool IteratorMDO::valid() const
{
	if (itNodCheie == NULL)
		return false;
	return true;
}

TElem IteratorMDO::element() const
{
	return make_pair(itNodCheie->cheie, itNodValoare->valoare);
}