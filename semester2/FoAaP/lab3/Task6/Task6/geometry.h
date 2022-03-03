#pragma once

class Point {
	long double x;
	long double y;
public:
	Point(long double x, long double y);
	
	long double get_x();
	long double get_y();
};

class Vector {
	long double x;
	long double y;
public:
	Vector(Point p1, Point p2);
	long double scalar_product(Vector v2);
	static Vector vector_sum(Vector v1, Vector v2);
	void multiply_by_scalar(long double scalar);
	long double get_lenght();

	long double get_x();
	long double get_y();
	void info();
};

class Circle {
	Point center;
	long double radius;
public:
	Circle(Point Center, double R);
	long double get_area();

	Point get_center();
	long double get_radius();
	void info();
};

class Sector: public Circle {
	long double radius;
	Point p1;
	Point p2;
	Vector rad_vector1;
	Vector rad_vector2;
public:
	Sector(Circle circle, Point P1, Point P2);
	long double get_area();
};