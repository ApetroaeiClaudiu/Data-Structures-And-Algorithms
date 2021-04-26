#include "VectorDinamic.h"


VectorDinamic::VectorDinamic(int capacitate)
{
	if (capacitate < 0)
	{
		//ii bai;
		return;
	}
	x = new TElem[capacitate];
	this->capacitate = capacitate;
	this->lungime = 0;
}

int VectorDinamic::dim() const
{
	return this->lungime;
}

TElem VectorDinamic::element(int i) const
{
	if (i<0 || i>lungime || lungime==0)
	{
		//ii bai aici
		return 0;
	}
	return this->x[i];
}


TElem VectorDinamic::modifica(int i, TElem e)
{
	if (i<0 || i>=lungime)
	{
		//ii bai;
		return 0;
	}
	TElem auxiliar = x[i];
	x[i] = e;
	return auxiliar;
}

void VectorDinamic::adaugaSfarsit(TElem e)
{
	if (capacitate == lungime)
	{
		this->resize();
	}
	x[lungime++] = e;
}

void VectorDinamic::adauga(int i, TElem e)
{
	if (i<0 || i>lungime)
	{
		//ii bai
		return;
	}
	if(capacitate == lungime)
	{
		this->resize();
	}
	for (int poz = lungime-1; poz >= i; poz--)
	{
		x[poz + 1] = x[poz];
	}
	x[i] = e;
	lungime++;
}

TElem VectorDinamic::sterge(int i)
{
	if (i<0 || i>=lungime || lungime==0)
	{
		//ii bai
		return 0;
	}
	TElem auxiliar = x[i];
	for (int poz = i; poz < lungime-1; poz++)
	{
		x[poz] = x[poz + 1];
	}
	lungime--;
	return auxiliar;
}

void VectorDinamic::resize()
{
	TElem *y;
	y = new TElem [capacitate * 2];

	for (int i = 0; i < lungime; i++)
	{
		y[i] = x[i];
	}
	delete[] x;
	x = y;
	capacitate = capacitate * 2;
}


IteratorVectorDinamic VectorDinamic::iterator()
{
	return IteratorVectorDinamic(*this);
}



VectorDinamic::~VectorDinamic()
{
	delete[] x;
	capacitate = -1;
	lungime = -1;
}