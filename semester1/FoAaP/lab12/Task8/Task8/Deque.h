struct Node_d {
	char d;
	Node_d* p;
};

Node_d* first_d(char d);
char delFirst_d(Node_d** pbeg);
char delLast_d(Node_d** pend);
void addLast_d(Node_d** pend, char d);
void addFirst_d(Node_d** pbeg, char d);