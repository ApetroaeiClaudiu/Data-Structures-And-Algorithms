#include "LSI.h"

const int LSI::aloca(){
	int i = primLiber;
	if (i != -1) {
		primLiber = this->next[i];
	}
	return i;
}

void LSI::dealoca(const int i){
	this->next[i] = primLiber;
	primLiber = i;
}

void LSI::initSpatiuLiber(){
	for (int i = 0; i < cap - 1; i++) {
		this->next[i] = i + 1;
	}
	this->next[cap - 1] = -1;
	primLiber = 0;
}

const int LSI::get_prim() const{
	return prim;
}

const TCheie LSI::c(const int i) const{
	if (i < cap&&elems[i] != std::make_pair(-1, -1)) {
		return elems[i].first;
	}
	return -1;
}

const TValoare LSI::v(const int i) const{
	if (i < cap&&elems[i] != std::make_pair(-1, -1)) {
		return elems[i].second;
	}
	return -1;
}

const int LSI::urmator(const int i) const{
	return this->next[i];
}

void LSI::adauga_inainte(const int i, const TElem & e){
	auto j = creeaza_nod(e);
	if (empty()) {
		prim = j;
	}
	else {
		if (i == prim) {
			this->next[j] = prim;
			prim = j;
		}
		else {
			auto p = prim;
			while (this->next[p] != i) {
				p = this->next[p];
			}
			this->next[j] = i;
			this->next[i] = j;
		}
	}
}

const std::vector<TCheie> LSI::chei() const{
	std::vector<TCheie> aux;
	for (auto&el : elems) {
		if (el.first != -1 && el.second != -1) {
			if (std::find(aux.begin(), aux.end(), el.first) != aux.end()) {
				aux.push_back(el.first);
			}
		}
	}
	return aux;
}

const std::vector<TValoare> LSI::valori(const TCheie & c) const{
	std::vector<TValoare> aux;
	auto p = prim;
	while (p != -1) {
		if (elems[p].first == c) {
			aux.push_back(elems[p].second);
		}
		p = next[p];
	}
	return aux;
}

const int LSI::creeaza_nod(const TElem & el){
	if (primLiber == -1) {
		this->next.resize(cap * 2);
		elems.resize(cap * 2);
		cap *= 2;
		for (int i = cap / 2; i < cap - 1; i++) {
			this->next[i] = i + 1;
		}
		this->next[cap - 1] = -1;
		primLiber = cap / 2;
	}
	auto i = aloca();
	elems[i] = el;
	this->next[i] = -1;
	return i;
}

bool LSI::sterge(const int i){
	if (!empty()) {
		if (i != -1) {
			auto aux = next[i];
			this->next[i] = this->next[next[i]];
			dealoca(aux);
			return true;
		}
		else {
			auto aux = prim;
			prim = next[prim];
			dealoca(aux);
			return true;
		}
	}
	else {
		return false;
	}
}

bool LSI::cauta(const TElem & el) const{
	if (empty()) {
		return false;
	}
	else {
		auto it = prim;
		while (this->next[it] != -1) {
			if (elems[it] == el) {
				return true;
			}
			it = this->next[it];
		}
		return false;
	}
}

bool LSI::empty() const{
	return prim == -1;
}

const unsigned int LSI::dim() const{
	unsigned int i = 0;
	auto aux = prim;
	while (aux != -1) {
		aux = next[aux];
		i++;
	}
	return i;
}

void LSI::adauga(const TElem & el){
	adauga_inainte(prim, el);
}
