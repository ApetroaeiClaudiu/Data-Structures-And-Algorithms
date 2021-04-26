#include <iostream>
#include "TestExtins.h"
#include "TestScurt.h"
#include "Colectie.h"
using std::cout;

//TAD Mulțime – reprezentare folosind o TD cu rezolvare coliziuni prin liste întrepătrunse
int main()
{
	testAll();
	cout << "TestScurt - passed\n";
	testAllExtins();
	cout << "\nTestExtins - passed\n";
	return 0;
}