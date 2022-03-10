#pragma once

class complex {
private:
	long double Re;
	long double Im;

public:
	complex(long double Re, long double Im);
	long double get_Re();
	long double get_Im();

	complex operator - (complex second);
	complex operator / (complex second);
};