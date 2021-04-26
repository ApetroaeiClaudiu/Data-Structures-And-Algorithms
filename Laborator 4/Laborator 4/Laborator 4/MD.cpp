#include "MD.h"
#include "IteratorMD.h"

void MD::cauta_nod(const TCheie & c, const TValoare& v, int& prec, int& nod)
{
	if (l.get_prim() == -1) {
		return;
	}
	if (l.get_prim() != -1 && l.c(l.get_prim()) == c && l.v(l.get_prim()) == v) {
		nod = l.get_prim();
		prec = -1;
	}
	else {
		auto p = l.get_prim();
		bool gasit = false;
		while (l.urmator(p) != -1 && !gasit) {
			if (l.c(l.urmator(p)) == c && l.v(l.urmator(p)) == v) {
				gasit = true;
				prec = p;
				nod = l.urmator(p);
			}
			else {
				p = l.urmator(p);
			}
		}
		prec = p;
		if (l.v(p) == v) {
			gasit = true;
		}
		if (gasit) {
			nod = l.urmator(p);
		}
		else {
			nod = -1;
		}
	}
}

void MD::adauga(TCheie c, TValoare v)
{
	auto aux = std::make_pair(c, v);
	l.add(aux);
}

std::vector<TValoare> MD::cauta(TCheie c) const
{
	return l.values(c);
}

bool MD::sterge(TCheie c, TValoare v)
{
	int prec{ -1 }, nod{ -1 };
	cauta_nod(c, v, prec, nod);
	if (nod != -1) {
		l.sterge(prec);
		return true;
	}
	else {
		return false;
	}
}

int MD::dim() const
{
	return l.size();
}

bool MD::vid() const
{
	return l.empty();
}

IteratorContainer MD::iterator() const
{
	return IteratorContainer(*this);
}

std::vector<TValoare> MD::colectiaValorilor() const
{
	auto v = l.get_prim();
	std::vector<TValoare> vec;
	while (v != -1) {
		vec.push_back(l.v(v));
		v = l.urmator(v);
	}
	return vec;
}
