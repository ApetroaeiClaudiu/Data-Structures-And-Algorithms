#pragma once

#include <algorithm>
#include <utility>
#include <vector>
typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

class LSI {
private:
	int cp{ 10 };
	std::vector<TElem> e;
	std::vector<int> urm;
	int prim, primLiber;
	const int aloca();
	void dealoca(const int i);
	void initSpLiber();
public:
	LSI() :prim{ -1 }, primLiber{ 0 }{
		urm.resize(10);
		initSpLiber();
		e.resize(10);
		std::fill(e.begin(), e.end(), std::make_pair(-1, -1));
	}
	const int get_prim() const;
	const TCheie c(const int i) const;
	const TValoare v(const int i) const;
	const int urmator(const int i) const;
	void adauga_inainte(const int i, const TElem& e);
	//void adauga_dupa(const int i, const TElem& e);
	const std::vector<TCheie> keys() const;
	const std::vector<TValoare> values(const TCheie& c) const;
	const int creeaza_nod(const TElem& e);
	bool sterge(const int i);
	bool find(const TElem& el) const;
	bool empty() const;
	const unsigned int size() const;
	void add(const TElem& el);
};