#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

#include "geometry.h"


using namespace std;

Point::Point(long double x, long double y) {
	this->x = x;
	this->y = y;
}

long double Point::get_x() {
	return this->x;
}

long double Point::get_y() {
	return this->y;
}

Vector::Vector(Point p1, Point p2) {
	this->x = p2.get_x() - p1.get_x();
	this->y = p2.get_y() - p1.get_y();
}

long double Vector::scalar_product(Vector v2) {
	return this->x * v2.x + this->y * v2.y;
}

Vector Vector::vector_sum(Vector v1, Vector v2) {
	return Vector(Point(-v1.x, -v1.x), Point(v2.x, v2.y));
}

void Vector::multiply_by_scalar(long double scalar) {
	this->x *= scalar;
	this->y *= scalar;
}

long double Vector::get_lenght() {
	return sqrt(this->get_x()* this->get_x() + this->get_y()*this->get_y());
}

long double Vector::get_x() {
	return this->x;
}

long double Vector::get_y() {
	return this->y;
}

void Vector::info() {
	cout << "\n\n" <<
		"Координата x: " << this->x << "\n"
		"Координата y: " << this->y << endl;
}

Circle::Circle(Point Center, double radius):center(Center) {
	this->radius = radius;
}

long double Circle::get_radius() {
	return this->radius;
}

void Circle::info() {
	cout << "\nЦентр круга находится в точке (" 
		<< this->center.get_x() << "; " << this->center.get_y() << ")" 
		<< "\nРадиус круга: " << this->get_radius() << endl;
}

long double Circle::get_area() {
	return M_PI * this->radius * this->radius;
}

Point Circle::get_center() {
	return this->center;
}

Sector::Sector(Circle circle, Point P1, Point P2):Circle(circle), p1(P1), p2(P2), rad_vector1(Vector(circle.get_center(), P1)), rad_vector2(Vector(circle.get_center(), P2)) {
	this->radius = circle.get_radius();

	if (this->rad_vector1.get_lenght() == this->radius && this->rad_vector2.get_lenght() == this->radius) {
		cout << "\nВсё нормально, точки лежат на окружности ;)" << endl;
	}
	else {
		throw std::invalid_argument("Введены неверные координаты точек (они не лежат на окружности)");
	}
}

long double Sector::get_area() {
	long double angle = acos(this->rad_vector1.scalar_product(this->rad_vector2) / (this->rad_vector1.get_lenght() * this->rad_vector2.get_lenght()));
	return M_PI * this->get_radius() * this->get_radius() * angle / (2 * M_PI);
}

