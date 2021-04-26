#include "Dictionar.h"
#include "IteratorDictionar.h"
//#include <iostream>



//complexitate O(n )
TValoare Dictionar::adauga(TCheie c, TValoare v) {
	TValoare aux;
	LSI* temp = head;
	if (head == NULL) {
		LSI *dic = new LSI;
		dic->element.first = c;
		dic->element.second = v;
		dic->next = NULL;
		head = dic;
	}
	else {
		LSI* trail = temp;
		while (temp != NULL) {
			if (temp->element.first == c) {
				aux = temp->element.second;
				temp->element.second = v;
				return aux;
			}
			trail = temp;
			temp = temp->next;
		}
		if (trail->next == NULL) {
			LSI *dic = new LSI;
			dic->element.first = c;
			dic->element.second = v;
			dic->next = head;
			head = dic;
		}
	}
	return NULL_TVALOARE;
}

//complexitate O(n)
TValoare Dictionar::sterge(TCheie c) {
	LSI *temp = head;
	LSI *trail = NULL;
	TValoare aux = NULL_TVALOARE;
	while (temp != NULL) {
		if (temp->element.first == c) {
			aux = temp->element.second;
			if (trail == NULL) {
				head = head->next;
				return aux;
			}
			else {
				trail->next = temp->next;
				//temp->next = NULL;
				//delete temp;
				return aux;
			}
		}
		trail = temp;
		temp = temp->next;
	}
	return aux;
}

//complexitate O(n)
TValoare Dictionar::cauta(TCheie c) const {
	LSI *temp = head;
	while (temp != NULL) {
		if (temp->element.first == c)
			return temp->element.second;
		temp = temp->next;
	}
	return NULL_TVALOARE;
}

//complexitate O(n), n - dimensiunea 
int Dictionar::dim() const {
	LSI *temp = head;
	int count = 0;
	while (temp != NULL) {
		++count;
		temp = temp->next;
	}
	return count;
}

//complexitate O(1)
bool Dictionar::vid() const {
	if (dim() == 0)
		return true;
	return false;
}

//complexitate O(1)
IteratorDictionar Dictionar::iterator() {
	return IteratorDictionar(*this);
}

//complexitate O(1)
Dictionar::~Dictionar() {
	delete head;
}
