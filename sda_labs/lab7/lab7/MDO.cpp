#include "MDO.h"

MDO::MDO(Relatie rel) {
	r = rel;
}

void MDO :: adauga(TCheie c, TValoare v) {
	rad = add(rad, c, v);
}

Nod* MDO::add(Nod *rad, TCheie c, TValoare v){
	if (rad == nullptr){
		return new Nod({ c, v });
	}
	if ((r(c, rad->element.first) == 0) && (r(rad->element.first, c) == 0)) {
		rad->vect.push_back(v);
	}
	if (r(c, rad->element.first)){
		rad->st = add(rad->st, c, v);
	}
	else
	{
		rad->dr = add(rad->dr, c, v);
	}
	return rad;
}

vector<TValoare> MDO::cauta(TCheie c) const {
	vector <TValoare> rez;
	cauta_rec(rad, c, rez);
	return rez;
}

void MDO::cauta_rec(Nod *rad, TCheie c, vector <TValoare> &rez) const {
	if (rad == nullptr) {
		return;
	}
	if (r(c, rad->element.first)) {
		cauta_rec(rad->st, c, rez);
		if (c == rad->element.first) {
			rez.push_back(rad->element.second);
		}
	}
	else {
		cauta_rec(rad->dr, c, rez);
	}
}

bool MDO::sterge(TCheie c, TValoare v) {
	bool sters = false;
	rad = sterge_rec(rad, c, v, sters);
	return sters;
}

Nod* MDO::sterge_rec(Nod *rad, TCheie c,TValoare v,bool &sters){
	if (rad == nullptr) {
		return nullptr;
	}
	if (c == rad->element.first && v == rad->element.second) {
		sters = true;
		if (rad->st == nullptr && rad->dr == nullptr) {
			return nullptr;
		}
		else if (rad->st == nullptr) {
			return rad->dr;
		}
		else if (rad->dr == nullptr) {
			return rad->st;
		}
		else {
			Nod *temp = max_postordine(rad->st);
			temp->st = sterge_rec(rad->st, temp->element.first, temp->element.second,sters);
			temp->dr = rad->dr;
			return temp;
		}
	}
	else if (r(c, rad->element.first)) {
		rad->st = sterge_rec(rad->st, c, v,sters);
	}
	else {
		rad->dr = sterge_rec(rad->dr, c, v,sters);
	}
	return rad;
}

vector<TValoare> MDO::stergeValoriPentruCheie(TCheie cheie) {
	vector <TValoare> rez;
	rez = cauta(cheie);
	for (int i = 0; i < rez.size(); i++) {
		sterge(cheie, rez.at(i));
	}
	return rez;
}

Nod* MDO::max_postordine(Nod *rad) const{
	if (rad->dr != nullptr){
		return max_postordine(rad->dr);
	}
	return rad;
}

int MDO::dim() const {
	return get_dim(rad);
}

int MDO::get_dim(Nod *rad) const
{
	if (rad == nullptr)
	{
		return 0;
	}
	return 1 + get_dim(rad->st) + get_dim(rad->dr);
}

bool MDO::vid() const {
	return rad == nullptr;
}

IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}

MDO::~MDO() {
	while (dim() > 0){
		sterge(rad->element.first,rad->element.second);
	}
}


void MDO::elemente_inordine(Nod *rad, vector <TElem> &rez) const{
	if (rad == nullptr){
		return;
	}
	elemente_inordine(rad->st, rez);
	rez.push_back(rad->element);
	elemente_inordine(rad->dr, rez);
}

vector <TElem> MDO::lista_elemente() const{
	vector <TElem> rez;
	elemente_inordine(rad, rez);
	return rez;
}
