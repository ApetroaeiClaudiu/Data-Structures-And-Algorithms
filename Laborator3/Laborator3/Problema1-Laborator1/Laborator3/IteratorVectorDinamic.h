#pragma once
#include "VectorDinamic.h"

class VectorDinamic;

typedef int TElem;
class IteratorVectorDinamic
{
	friend class VectorDinamic;

private:
	//iteratorul memoreaza o referinta catre container
	const VectorDinamic& referintaVector;
	//aici alte atribute specifice: curent, etc

	IteratorVectorDinamic(const VectorDinamic& c);
	int pozitie;

public:

	TElem element();
	bool valid();
	void urmator();
	void prim();
};
