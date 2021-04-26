#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> 

#include<iostream>
#include "VectorDinamic.h"
#include "IteratorVectorDinamic.h"
#include "TestExtins.h"
#include "TestScurt.h"

using namespace std;


int main()
{
	int cmd;
	{
		VectorDinamic v(3);
		v.adaugaSfarsit(1);
		v.adaugaSfarsit(2);
		v.adaugaSfarsit(3);
		v.adaugaSfarsit(4);
		IteratorVectorDinamic it = v.iterator();
	}
	testAll();
	testAllExtins();

	cin >> cmd;
	_CrtDumpMemoryLeaks();
}