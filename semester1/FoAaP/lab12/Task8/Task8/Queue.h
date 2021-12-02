struct Node_q {
	char d;
	Node_q* p;
};

Node_q* first_q(char d);
void add_q(Node_q** pbeg, char d);
char del_q(Node_q** pbeg);
