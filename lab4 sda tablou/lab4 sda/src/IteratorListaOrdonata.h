#pragma once


/*
 * IteratorLO.h
 *
 *  Created on: 20 mar. 2019
 *      Author: George
 */

//#ifndef IteratorListaOrdonata_H_
//#define IteratorListaOrdonata_H_

#include "ListaOrdonata.h"

class IteratorLO {
	friend class LO;
	//friend class Nod;
private:
	int curent;
	const LO& con;



public:

	IteratorLO(const LO& c);
	void prim();
	void urmator();
	bool valid() const;
	TElement element() const;
};



//#endif /* IteratorListaOrdonata_H_ */
