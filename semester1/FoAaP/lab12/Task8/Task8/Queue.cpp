#include "Queue.h";

//Forming of queue
Node_q* first_q(char d) {
	Node_q* pv = new Node_q; 
	pv->d = d;
	pv->p = 0;
	return pv;
}

//Adding into end of queue
void add_q(Node_q** pend, char d) {
	Node_q* pv = new Node_q;
	pv->d = d;
	pv->p = 0;
	(*pend)->p = pv;
	*pend = pv;
}

//Output of first element
char del_q(Node_q** pbeg) {
	char temp = (*pbeg)->d;
	Node_q* pv = *pbeg;
	*pbeg = (*pbeg)->p;
	delete pv;
	return temp;
}