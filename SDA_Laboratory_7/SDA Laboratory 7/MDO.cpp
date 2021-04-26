#include "MDO.h"
#include <algorithm>

MDO::MDO(Relatie r) : r(r), root(nullptr)
{
	
}

Node* MDO::add(Node *root, TCheie c, TValoare v)
{
	if(root == nullptr)
	{
		return new Node({ c, v });
	}
	if(r(c, root->key()))
	{
		root->lf = add(root->lf, c, v);
	}else
	{
		root->rg = add(root->rg, c, v);
	}
	return root;
}

void MDO::adauga(TCheie c, TValoare v)
{
	root = add(root, c, v);
}

void MDO::find(Node *root, TCheie c, vector <TValoare> &ret) const
{
	if(root == nullptr)
	{
		return;
	}
	if(r(c, root->key()))
	{
		find(root->lf, c, ret);
		if (c == root->key())
		{
			ret.push_back(root->value());
		}
	}else
	{
		find(root->rg, c, ret);
	}
}

vector<TValoare> MDO::cauta(TCheie c) const
{
	vector <TValoare> ret;
	find(root, c, ret);
	return ret;
}

Node* MDO::get_max_postorder(Node *root) const
{
	if(root->rg != nullptr)
	{
		return get_max_postorder(root->rg);
	}
	return root;
}

Node* MDO::remove(Node* root, TCheie c, TValoare v, bool &deleted){
	if(root == nullptr){
		return nullptr;
	}
	if(c == root->key() && v == root->value()){
		deleted = true;
		if(root->lf == nullptr && root->rg == nullptr){
			return nullptr;
		}else if(root->lf == nullptr){
			return root->rg;
		}else if(root->rg == nullptr){
			return root->lf;
		}else{
			Node *tmp = get_max_postorder(root->lf);
			tmp->lf = remove(root->lf, tmp->key(), tmp->value(), deleted);
			tmp->rg = root->rg;
			return tmp;
		}
	}else if(r(c, root->key())){
		root->lf = remove(root->lf, c, v, deleted);
	}else{
		root->rg = remove(root->rg, c, v, deleted);
	}
	return root;
}

bool MDO::sterge(TCheie c, TValoare v)
{
	bool deleted = false;
	root = remove(root, c, v, deleted);
	return deleted;
}

int MDO::get_dim(Node *root) const
{
	if(root == nullptr)
	{
		return 0;
	}
	return 1 + get_dim(root->lf) + get_dim(root->rg);
}

int MDO::dim() const
{
	return get_dim(root);
}

bool MDO::vid() const
{
	return root == nullptr;
}

IteratorMDO MDO::iterator() const
{
	return IteratorMDO(*this);
}


void MDO::get_elems_inorder(Node *root, vector <TElem> &ret) const
{
	if(root == nullptr)
	{
		return;
	}
	get_elems_inorder(root->lf, ret);
	ret.push_back(root->val);
	get_elems_inorder(root->rg, ret);
}

vector <TElem> MDO::get_elems_inorder() const
{
	vector <TElem> ret;
	get_elems_inorder(root, ret);
	return ret;
}

IteratorMDO::IteratorMDO(const MDO& c) : c(c)
{	
	elems = c.get_elems_inorder();
	p = 0;
}
//reseteaza pozitia iteratorului la inceputul containerului
void IteratorMDO::prim()
{
	p = 0;
}

//muta iteratorul in container
// arunca exceptie daca iteratorul nu e valid
void IteratorMDO::urmator()
{
	p++;
}

//verifica daca iteratorul e valid (indica un element al containerului)
bool IteratorMDO::valid() const
{
	return p < elems.size();
}

//returneaza valoarea elementului din container referit de iterator
//arunca exceptie daca iteratorul nu e valid
TElem IteratorMDO::element() const
{
	return elems[p];
}
