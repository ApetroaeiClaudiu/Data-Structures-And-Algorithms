#pragma once
#include <algorithm>
#include <utility>
#include <vector>

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

class LSI {
private:
	int cap = 10;
	std::vector<TElem> elems;
	std::vector<int> next;
	int prim, primLiber;
	const int aloca();
	void dealoca(const int i);
	void initSpatiuLiber();
public:
	LSI(){
		prim = -1, primLiber = 0;
		next.resize(10);
		initSpatiuLiber();
		elems.resize(10);
		std::fill(elems.begin(), elems.end(), std::make_pair(-1, -1));
	}
	const int get_prim() const;
	const TCheie c(const int i) const;
	const TValoare v(const int i) const;
	const int urmator(const int i) const;
	void adauga_inainte(const int i, const TElem& e);
	const std::vector<TCheie> chei() const;
	const std::vector<TValoare> valori(const TCheie& c) const;
	const int creeaza_nod(const TElem& e);
	bool sterge(const int i);
	bool cauta(const TElem& el) const;
	bool empty() const;
	const unsigned int dim() const;
	void adauga(const TElem& el);
};