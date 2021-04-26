#include "LSI.h"

const int LSI::aloca()
{
	int i = primLiber;
	if (i != -1) {
		primLiber = this->urm[i];
	}
	return i;
}

void LSI::dealoca(const int i)
{
	this->urm[i] = primLiber;
	primLiber = i;
}

void LSI::initSpLiber()
{
	for (int i = 0; i < cp - 1; i++) {
		this->urm[i] = i + 1;
	}
	this->urm[cp - 1] = -1;
	primLiber = 0;
}

const int LSI::get_prim() const
{
	return prim;
}

const TCheie LSI::c(const int i) const
{
	if (i < cp&&e[i] != std::make_pair(-1, -1)) {
		return e[i].first;
	}
	return -1;
}

const TValoare LSI::v(const int i) const
{
	if (i < cp&&e[i] != std::make_pair(-1, -1)) {
		return e[i].second;
	}
	return -1;
}

const int LSI::urmator(const int i) const
{
	return this->urm[i];
}

void LSI::adauga_inainte(const int i, const TElem & e)
{
	auto j = creeaza_nod(e);
	if (empty()) {
		prim = j;
	}
	else {
		if (i == prim) {
			this->urm[j] = prim;
			prim = j;
		}
		else {
			auto p = prim;
			while (this->urm[p] != i) {
				p = this->urm[p];
			}
			this->urm[j] = i;
			this->urm[i] = j;
		}
	}
}

/*void LSI::adauga_dupa(const int i, const TElem & e)
{
	auto j = creeaza_nod(e);
	if (i == prim) {
		urm[j] = prim;
		prim = j;
	}
	else {
		auto p = prim;
		while (urm[p] != i) {
			p = urm[p];
		}
		urm[j] = i;
		urm[i] = j;
	}
}*/

const std::vector<TCheie> LSI::keys() const
{
	std::vector<TCheie> aux;
	for (auto&x : e) {
		if (x.first != -1 && x.second != -1) {
			if (std::find(aux.begin(), aux.end(), x.first) != aux.end()) {
				aux.push_back(x.first);
			}
		}
	}
	return aux;
}

const std::vector<TValoare> LSI::values(const TCheie & c) const
{
	std::vector<TValoare> aux;
	auto p = prim;
	while (p != -1) {
		if (e[p].first == c) {
			aux.push_back(e[p].second);
		}
		p = urm[p];
	}
	return aux;
}

const int LSI::creeaza_nod(const TElem & el)
{
	if (primLiber == -1) {
		this->urm.resize(cp * 2);
		e.resize(cp * 2);
		cp *= 2;
		for (int i = cp / 2; i < cp -1; i++) {
			this->urm[i] = i + 1;
		}
		this->urm[cp - 1] = -1;
		primLiber = cp / 2;
	}
	auto i = aloca();
	e[i] = el;
	this->urm[i] = -1;
	return i;
}

/*bool LSI::sterge(const int i)
{
	if (!empty()) {
		if (i == prim) {
			dealoca(i);
			prim = -1;
			return true;
		}
		else {
			auto it = prim;
			while (this->urm[it] != i) {
				it = this->urm[it];
			}
			this->urm[it] = this->urm[i];
			dealoca(i);
			return true;
		}
	}
	else {
		return false;
	}
}*/

bool LSI::sterge(const int i)
{
	if (!empty()) {
		if (i != -1) {
			auto aux = urm[i];
			this->urm[i] = this->urm[urm[i]];
			dealoca(aux);
			return true;
		}
		else {
			auto aux = prim;
			prim = urm[prim];
			dealoca(aux);
			return true;
		}
	}
	else {
		return false;
	}
}

bool LSI::find(const TElem & el) const
{
	if (empty()) {
		return false;
	}
	else {
		auto it = prim;
		while (this->urm[it] != -1) {
			if (e[it] == el) {
				return true;
			}
			it = this->urm[it];
		}
		return false;
	}
}

bool LSI::empty() const
{
	return prim == -1;
}

const unsigned int LSI::size() const
{
	unsigned int i{ 0 };
	auto aux = prim;
	while (aux != -1) {
		aux = urm[aux];
		i++;
	}
	return i;
}

void LSI::add(const TElem & el)
{
	adauga_inainte(prim, el);
}
