/*
 * ListaOrdonata.cpp
 *
 *  Created on: 26 mar. 2019
 *      Author: George
 */
#include <iostream>
#include "ListaOrdonata.h"
#include "IteratorListaOrdonata.h"// TREBUIE PUS MEREU TOT CE TREBUIE
#include <stdexcept>

//class LO;
//class IteratorLO;
#include <exception>







/*
 * aloca spatiu liber de indice i
 * post: i este intreg
 */
int LO::aloca(){
	int i = this->primulLiber;
	if (i != -1){
		this->primulLiber = this->urm[i];
	}
	return i;
}


/*
 * dealoca loc de indice i (
 */
void LO::dealoca(int i){
	this->urm[i] = this->primulLiber;
	this->primulLiber = i;
}


void LO::initSpLiber(){
	for (int i=0;i<this->cp-1;i++){
		this->urm[i] = i+1;
		this->prec[i+1] = i;//+LDI
	}

	this->urm[this->cp-1]=-1; // setam urmatorul pentru ultimul element ca fiind NIL
	this->prec[0]=-1;//+LDI

	//this->prec[this->primulLiber]=-1;//+LDI		nu cred ca mai e nevoie...

	this->primulLiber=0;// ESTE 0 AICI PENTRU CA POINTEAZA PRIMUL ELEMENT DIN TABLOU, CARE ESTE LIBER (NU AVEM NICIUN NOD OCUPAT - LISTA E VIDA)
}


LO::LO(Relatie r){
	cp = 100;// 80000;
	this->countElems = 0;

	this->e = new TElement[cp];
	this->prec = new int[cp];
	this->urm = new int[cp];

	this->relatie = r;

	this->primulLiber = -1;
	this->primul = -1;
	this->ultimul = -1;//+LDI
	
	this->initSpLiber();
	
}


int LO::creeazaNod(TElement e){

	if (this->primulLiber == -1){// lista este plina
		;//TODO realoca
		;//TODO copiaza elementele + legaturile
		;//TODO reinitializeaza lista sp. liber
		
		TElement* newE = new TElement[cp*2];
		int* newU = new int[cp*2];
		int* newP = new int[cp*2];
		
		for(int i=0;i<cp;i++){
			newE[i]=this->e[i];
			newU[i]=this->urm[i];
			newP[i]=this->prec[i];
		}// copiem tot ce avwem deja existent in tablou


		this->primulLiber = cp;//pozitionam primul liber pe prima pozitie din a doua jumatate a noului tablou

		for(int i=cp;i<cp*2-1;i++){
			newU[i] = i+1;
			newP[i+1] = i;
		}// vom seta o ordine naturala intre elementele considerate libere. (nu am setat inca primul prec si ultimul urm)

		newU[cp*2-1] = -1;
		newP[cp] = -1; // acum am setat si capetele


		this->cp=this->cp*2;// actualizam capacitatea

		delete[] this->e;
		delete[] this->urm;
		delete[] this->prec;// trebuie sa stergem noi fostul tablou, destructorul nu va putea face asta aici


		this->e=newE;
		this->urm=newU;
		this->prec=newP;// asociem clasei noul tablou
	}


	int i = this->aloca();
	this->e[i]=e;
	this->urm[i]=-1;
	this->prec[i]=-1;//+LDI
	return i;
}



// returnare element de pe pozitia curenta
//arunca exceptie daca poz nu e valid
TElement LO::element(IteratorLO poz) const{
	if(!poz.valid()){
		throw std::invalid_argument("poz nu e valid");

	}
	if (poz.curent == -1)
		return NULL_TELEMENT;
	else{
		return this->e[poz.curent];
	}

}


// prima pozitie din LO
IteratorLO LO::prim() const{
	return IteratorLO(*this);
}

/*
 * {destructor}
 * pre: l apartine L
 * post: l a fost "distrusa" (spatiul de memorie alocat a fost eliberat)
 */
LO::~LO() {
	/*delete[] e;
	delete[] urm;
	delete[] prec;*/
	std::cout << "BEGIN DESTROY" << std::endl;
	
	

	delete this->e;
	
	delete this->urm;
	
	delete this->prec;
	//aveam problema ca facusem un precedent in afara range-ului...

	std::cout << "END DESTROY" << std::endl;
}




/*
 * // cauta element si returneaza prima pozitie pe care apare
 * // (sau iterator invalid)
 */
IteratorLO LO::cauta(TElement e) const{
	IteratorLO ic = this->prim();
	/*
	while(ic.valid() && ic.element()!=e){
		ic.urmator();
	}
	if(!ic.valid()){
		ic.curent=-1;
		return ic;
	}
	return ic;
	*/

	if (this->e[ic.curent] == e ) {
		return ic;
	}
	// ar trebui sa fac si fara sa aiba dependenta de iterator, sa lucrez direct pe reprezentare
	int j = this->primul;
	//if ((relatie(e,this->e[this->primul]) && e != this->e[this->primul]) || (relatie(this->e[this->ultimul], e) && e != this->e[this->ultimul])) {// daca este mai 'mic sau egal' ca primul sau mai 'mare' ca ultimul
	if (!relatie(this->e[this->primul],e) || !relatie(e, this->e[this->ultimul])) {
		ic.curent = -1;
		return ic;// iterator nevalid
	}
	//daca am ajuns aici, stim sigur ca elementul pe care il cautam este in range-ul listei
	while (j != -1 && !relatie(e, this->e[j])) {//mergem pana terminam sau am gasit locul "de inserare"
		j = this->urm[j];
	}
	//am gasit locul unde macar ar trebui sa fie
	if (j != -1 && this->e[j] == e){// aici am gasit elementul
		ic.curent = j;
		return ic;
	}
	else {// aici am gasit pozitia unde ar trebui sa fie elementul, dar nu si pe el...
		ic.curent = -1;
		return ic;
	}
}

/*
 * pre: l apartine L, p apartine TPozitie, valid(p), e apartine TElement
 * post: elementul e a fost inserat in lista l astfel incat sa fie respectata relatia r
 */
void LO::adauga(TElement e) {// complexitate O(n)
	//daca lista e vida
	int j = this->creeazaNod(e);
	if(this->primul==-1){// complexitate teta de 1
		this->primul=j;
		this->ultimul=j;
		this->countElems++;
	}
	else if(relatie(e,this->e[this->primul])){//Adaugam INAINTEA primului daca relatie este True(elementul de inseart < primul actual)		// complexitate teta de 1
		this->urm[j]=this->primul;
		this->prec[this->primul]=j;
		//this->e[this->primul]=j; in plus - deja efectual la creeazaNod
		this->primul = j;
		this->countElems++;
	}
	else if(relatie(this->e[this->ultimul],e)){//Adaugam DUPA ultimul daca relatie este True(ultimul actual < elementul de inserat)			// complexitate teta de 1
		this->prec[j]=this->ultimul;
		this->urm[this->ultimul]=j;
		//this->e[this->ultimul]=j; in plus - deja efectual la creeazaNod
		this->ultimul = j;
		this->countElems++;
	}
	else{//parcurgem lista pana putem adauga																							// complexitate O(n)
		int q = this->primul;
		while(!relatie(e,this->e[q])){//sa merg cu o pozitie in minus?... (dar totusi insereaza bine, vad...)
			q = this->urm[q];
		}// am gasit locul de inserat

		this->prec[j] = this->prec[q];
		this->urm[j] = q;
		//q->prec->urm=j;
		this->urm[this->prec[q]] = j;
		this->prec[q] = j;
		this->countElems++;


		//this->urm[this->prec[q]] = j;
		//this->prec[j] = this->prec[q];
		//this->urm[j] = q;
		//this->prec[q] = j;
		////////q->prec->urm=j;
		//this->countElems++;
	}
}


/*
 *  // sterge element de pe o pozitie poz si returneaza elementul sters
	//dupa stergere poz e pozitionat pe elementul de dupa cel sters
	//arunca exceptie daca poz nu e valid
 */
TElement LO::sterge(IteratorLO& poz) {// complexitate O(n)
	if (!poz.valid()) {
		//throw exception();
		throw std::invalid_argument("poz nu e valid");
	}
	int i = poz.curent;

	if(this->primul == this->ultimul && poz.curent==this->primul){// in lista se afla un singur element.
		this->primul=-1;
		this->ultimul=-1;
		this->countElems--;

		TElement old = this->e[poz.curent];
		poz.curent = -1;
		return old;
	}
	else if(poz.curent == this->primul){//stergem primul element din lista
		this->prec[this->urm[poz.curent]]=-1;
		this->primul=this->urm[poz.curent];
		this->countElems--;

		int pozNou = this->urm[poz.curent];
		
		TElement old = this->e[poz.curent];
		//poz.urmator();
		poz.curent = pozNou;
		return old;
	}
	else if(poz.curent == this->ultimul){//stergem ultimul element din lista
		this->urm[this->prec[poz.curent]]=-1;
		this->ultimul=this->prec[poz.curent];
		this->countElems--;

		TElement old = this->e[poz.curent];
		poz.curent = -1;
		return old;
	}
	else{

		int j = this->primul;
		while (j != poz.curent && this->urm[j] != -1) {
			j = this->urm[j];
		}

		int pozNou = this->urm[j];

		if (this->urm[j] != -1) {// am gasit, deci, elementul   (sigur nici primul, nici ultimul)
			this->urm[this->prec[j]]=this->urm[j];
			this->prec[this->urm[j]]=this->prec[j];
			this->countElems--;

			TElement old = this->e[poz.curent];
			//poz.urmator();//pozitionam pe poz dupa elementul sters.
			poz.curent = pozNou;
			return old;
		}
		else{
			return NULL_TELEMENT;
		}

		dealoca(i);
	}


}





int LO::dim() const {// complexitate teta de 1
	return this->countElems;
}


bool LO::vida() const {// complexitate teta de 1
	if (dim() == 0) return true;
	return false;
}
