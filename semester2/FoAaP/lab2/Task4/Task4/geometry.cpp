/***************************************************************
 *                                                             *
 * Файл     : geometry.cpp                                     *
 *                                                             *
 * Описание : модуль, содержащий реализацию методов классов    *
 *            для решения геометрических задач                 *
 *                                                             *
 ***************************************************************/

#include <math.h>
#include "geometry.h"
#include <iostream>

using namespace std;

// -------------------------------------------------------------
//       Методы класса "Точка" 
// -------------------------------------------------------------

// конструктор: точка задается своими координатами
Point::Point(double X, double Y) {
  x=X; y=Y;
}

Point::Point() {
    this->x = 0;
    this->y = 0;
}

// прочитать координату Х
double Point::getX() {
  return x;
  }

// прочитать координату У
double Point::getY() {
  return y;
  }

// -------------------------------------------------------------
//       Методы класса "Окружность" 
// -------------------------------------------------------------

// конструктор: окружность задается центром и радиусом
Circle::Circle(Point Center, double R):center(Center) {
  r=R;
  }

// прочитать центр окружности
Point Circle::getCenter() {
  return center;
  }

// прочитать радиус окружности
double Circle::getR() {
  return r;
  }

void Circle::info() {
    cout << "Центр окружности расположен в точке ("
        << this->getCenter().getX() << ',' << this->getCenter().getY()
        << "), радиус = " << this->getR() << endl;
}

// -------------------------------------------------------------
//       Методы класса "Прямая" 
// -------------------------------------------------------------

// конструктор: прямая задается своими коэффициентами
Line::Line(double a,double b,double c) {
  A=a; B=b; C=c;
  }

// конструктор: прямая, которая проходит через две заданные точки
Line::Line(Point p1,Point p2) {
  B=p1.getY()-p2.getY();
  A=p2.getX()-p1.getX();
  C=p1.getX()*p2.getY() - p2.getX() * p1.getY();
  }

// найти точку пересечения с заданной прямой
Point Line::getIntersect(Line line) {
    double d = A * line.B - B * line.A,
        d1 = -(C * line.B - B * line.C),
        d2 = -(A * line.C - C * line.A);
    return Point(d1 / d, d2 / d);
}

// построить перпендикулярную прямую, проходящую через заданную точку
Line Line::getPerpendicular(Point p) {
  return Line(B,-A,-B*p.getX()+A*p.getY());
  }

// -------------------------------------------------------------
//       Методы класса "Отрезок" 
// -------------------------------------------------------------

// конструктор: отрезок задается двумя точками
Segment::Segment(Point p1,Point p2) {
  x1=p1.getX(); y1=p1.getY();
  x2=p2.getX(); y2=p2.getY();
  }

Segment::Segment() {
    this->x1 = 0;
    this->x2 = 0;
    this->y1 = 0;
    this->y2 = 0;
}

// найти середину отрезка
Point Segment::getMidpoint() {
  return Point( (x1+x2)/2,(y1+y2)/2 );
  }

// найти длину отрезка
double Segment::getLength() {
  return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
  }

// -------------------------------------------------------------
//       Методы класса "Вектор" 
// -------------------------------------------------------------

Vector::Vector(Point p1, Point p2) {
    this->x = p2.getX() - p1.getX();
    this->y = p2.getY() - p1.getY();
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

// -------------------------------------------------------------
//       Методы класса "Треугольник" 
// -------------------------------------------------------------

Triangle::Triangle(Point A, Point B, Point C) {
    this->A = A;
    this->B = B;
    this->C = C;

    this->AB = Segment(A, B);
    this->BC = Segment(B, C);
    this->AC = Segment(A, C);

    if ((AB.getLength() + BC.getLength() > AC.getLength()
        && AB.getLength() + AC.getLength() > BC.getLength()
        && BC.getLength() + AC.getLength() > AB.getLength()) 

        &&((A.getX() != B.getX() && A.getY() != B.getY())
        ||(B.getX() != C.getX() && B.getY() != C.getY())
        ||(A.getX() != C.getX() && A.getY() != C.getY()))
        ) {
        cout << "\n" << "Всё нормально, треугольник существует ;)" << endl;
    }
    else {
        throw std::invalid_argument("Введены неверные значения");
    }
}

Point Triangle::get_heights_point() {
    Line BC_line = Line(this->B, this->C);
    Line AC_line = Line(this->A, this->C);

    Line height1 = BC_line.getPerpendicular(this->A);
    Line height2 = AC_line.getPerpendicular(this->B);

    return height1.getIntersect(height2);
}

Point Triangle::get_median_point() {
    Point AC_center = Point(this->AC.getMidpoint());
    Point BC_center = Point(this->BC.getMidpoint());

    Line median1 = Line(this->B, AC_center);
    Line median2 = Line(this->A, BC_center);

    return median1.getIntersect(median2);
}


// ============== конец модуля =================================
