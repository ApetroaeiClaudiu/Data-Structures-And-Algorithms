#include "MD.h"
#include "IteratorMD.h"

void MD::cauta_nod(const TCheie & c, const TValoare& v, int& prec, int& nod){
	if (lista.get_prim() == -1) {
		return;
	}
	if (lista.get_prim() != -1 && lista.c(lista.get_prim()) == c && lista.v(lista.get_prim()) == v) {
		nod = lista.get_prim();
		prec = -1;
	}
	else {
		auto p = lista.get_prim();
		bool gasit = false;
		while (lista.urmator(p) != -1 && !gasit) {
			if (lista.c(lista.urmator(p)) == c && lista.v(lista.urmator(p)) == v) {
				gasit = true;
				prec = p;
				nod = lista.urmator(p);
			}
			else {
				p = lista.urmator(p);
			}
		}
		prec = p;
		if (lista.v(p) == v) {
			gasit = true;
		}
		if (gasit) {
			nod = lista.urmator(p);
		}
		else {
			nod = -1;
		}
	}
}

void MD::adauga(TCheie c, TValoare v){
	auto element = std::make_pair(c, v);
	lista.adauga(element);
}

std::vector<TValoare> MD::cauta(TCheie c) const{
	return lista.valori(c);
}

bool MD::sterge(TCheie c, TValoare v){
	int prec = -1, nod = -1;
	cauta_nod(c, v, prec, nod);
	if (nod != -1) {
		lista.sterge(prec);
		return true;
	}
	else {
		return false;
	}
}

int MD::dim() const{
	return lista.dim();
}

bool MD::vid() const{
	return lista.empty();
}

IteratorMD MD::iterator() const{
	return IteratorMD(*this);
}


int MD::adaugaInexistente(MD& md) {
	auto count = 1;
	auto p = md.lista.get_prim();
	while (md.lista.urmator(p) != -1 ) {
		auto el = std::make_pair(md.lista.c(md.lista.urmator(p)), md.lista.v(md.lista.urmator(p)));
		if (this->lista.cauta(el) == false) {
			this->adauga(md.lista.c(md.lista.urmator(p)), md.lista.v(md.lista.urmator(p)));
			count++;
			p = lista.urmator(p);
		}
		else {
			p = lista.urmator(p);
		}
	}
	return count;
}
