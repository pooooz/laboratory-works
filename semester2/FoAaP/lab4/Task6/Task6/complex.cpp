#include "complex.h"
#include <iostream>

complex::complex(long double Re, long double Im) {
	this->Re = Re;
	this->Im = Im;
}

long double complex::get_Re() {
	return this->Re;
}

long double complex::get_Im() {
	return this->Im;
}

complex complex::operator - (complex second) {
	return complex((this->get_Re() - second.get_Re()), (this->get_Im() - second.get_Im()));
}

complex complex::operator / (complex second) {
	if (second.get_Re() != 0 && second.get_Im() != 0) {
		long double Re = (this->get_Re() * second.get_Re() + this->get_Im() * second.get_Im()) /
			(second.get_Re() * second.get_Re() + second.get_Im() * second.get_Im());

		long double Im = (second.get_Re() * this->get_Im() - this->get_Re() * second.get_Im()) /
			(second.get_Re() * second.get_Re() + second.get_Im() * second.get_Im());

		return complex(Re, Im);
	}
	else {
		// Понимаю, что так не стоит делать, но это просто лабораторная. Такое поведение само по себе неправильное!
		throw std::invalid_argument("Были указаны некорректные значения");
		return complex(0, 0);
	}
}