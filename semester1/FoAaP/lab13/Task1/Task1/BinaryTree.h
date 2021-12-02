struct TREE {
	long double d;
	TREE* left;
	TREE* right;
};

void enterNumberI(int& n);
void enterNumberIR(long double& n);


void first(TREE*&, long double);
TREE* search(TREE*, long double);
void add(TREE*, long double);
void print_tree_level(TREE*, int);
void del_tree(TREE*& top);

long double summLevel(TREE* tree, int lvl, long double& count);
long double recSumm(TREE* tree, int lvl);