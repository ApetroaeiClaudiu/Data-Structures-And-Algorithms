/*
 * IteratorListaOrdonata.cpp
 *
 *  Created on: 26 mar. 2019
 *      Author: George
 */

#include <iostream>
using namespace std;

#include "IteratorListaOrdonata.h"
class LO;

 // initializare curent si alte atribute specifice
IteratorLO::IteratorLO(const LO& c) : con(c) {// complexitate teta de 1
	this->curent = c.primul;
}



/*
 * pre : i apartine I
 * post : curent refera 'primul' element din container
 */
void IteratorLO::prim() {// complexitate teta de 1
	this->curent = this->con.primul;
}



/*
 * pre : i apartine I, curent este valid
 * post : [i].curent'=[[i].curent].urmator refera 'urmatorul' element din container fata de cel referit de curent
 */
// arunca exceptie daca iteratorul nu e valid
void IteratorLO::urmator() {// complexitate teta de 1

	if (this->curent == -1)
		throw exception();

		this->curent = this->con.urm[this->curent];

}


/*
 * pre : i apartine  I
 * post : valid = adev, daca curent refera o pozitie valida din container
				= fals, altfel
 */
bool IteratorLO::valid() const {// complexitate teta de 1
	return this->curent != -1;
}


/*
 * pre : i apartine I, curent este valid (refera un element din container)
 * post : e apartine TElementent, e este elementul curent din iteratie
 * (elementul din container referit de curent)
 */
// arunca exceptie daca iteratorul nu e valid
TElement IteratorLO::element() const {// complexitate teta de 1

	if (this->curent == -1)
		throw exception();

	return this->con.e[this->curent];
}
