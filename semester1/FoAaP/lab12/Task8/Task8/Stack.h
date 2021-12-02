#include <iostream>

struct Node_s {
	char d;
	Node_s* p;
};

Node_s* first_s(char d);
void push_s(Node_s** top, char d);
char pop_s(Node_s** top);