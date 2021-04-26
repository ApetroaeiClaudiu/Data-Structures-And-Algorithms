/*
29. TAD MultiDictionar ordonat - reprezentare sub forma unei LSI de chei distincte 
ordonate în raport cu o relație de ordine R între chei. Fiecare cheie va memora o 
LSI cu valorile asociate cheii.
*/
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> 
#include<iostream>

#include "TestScurt.h"
#include "TestExtins.h"
#include "MDO.h"
using namespace std;


typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

bool relatie(TCheie cheie1, TCheie cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}


int main()
{
	{
		MDO dictionar(relatie);
		dictionar.adauga(1, 2);
		dictionar.adauga(2, 3);
		dictionar.adauga(4, 5);
		dictionar.adauga(4, 7);
		vector<TCheie> v = dictionar.multimeChei();
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << "\n";
		}


	}
	testAll();
	testAllExtins();



	int cmd;
	cout << "introdu comanda: ";
	cin >> cmd;
	_CrtDumpMemoryLeaks();
}