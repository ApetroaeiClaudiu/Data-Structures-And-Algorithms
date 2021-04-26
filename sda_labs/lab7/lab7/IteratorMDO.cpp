#include"IteratorMDO.h"
#include"MDO.h"
#include<stack>

using namespace std;

IteratorMDO::IteratorMDO(const MDO& mdo) : mdo{ mdo }{
	elemente = mdo.lista_elemente();
	curent = 0;
}


void IteratorMDO::prim(){
	curent = 0;
}


void IteratorMDO::urmator() {
	curent++;
}


bool IteratorMDO::valid() const{
	return curent < elemente.size();
}


TElem IteratorMDO::element() const{
	return elemente[curent];
}