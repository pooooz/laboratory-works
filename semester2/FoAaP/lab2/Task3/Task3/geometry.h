/***************************************************************
 *                                                             *
 * Файл     : geometry.h                                       *
 *                                                             *
 * Описание : заголовочный файл с описанием набора классов     *
 *            для решения геометрических задач                 *
 *                                                             *
 ***************************************************************/

#ifndef GEOMETRY_H
#define GEOMETRY_H

// --------- Класс "Точка" ---------------

class Point {
    double x,y; // координаты точки
  public:
    Point(double X, double Y); // конструктор класса
    double getX();             // чтение поля X
    double getY();             // чтение поля Y
};


// --------- Класс "Окружность" ----------

class Circle {
    Point center; // центр окружности
    double r;     // радиус окружности
  public:
    Circle(Point Center, double R);   // конструктор класса
    Point getCenter();                // чтение поля Center
    double getR();                    // чтение поля
    void info();                      // Вывод информации об объекте в консоль
};

// --------- Класс "Прямая" --------------

class Line {
    double A,B,C; // коэффициенты прямой
  public:
    Line(double a,double b,double c); // конструктор класса
    Line(Point p1,Point p2);          // еще один конструктор
    Point getIntersect(Line line);    // найти точку пересечения с заданной прямой
    Line getPerpendicular(Point p);   // найти перпендикулярную прямую,
                                      // проходящую через заданную точку
};

// --------- Класс "Отрезок" -------------

class Segment {
    double x1,y1,x2,y2; // координаты концов отрезка
  public:
    Segment(Point p1,Point p2);       // конструктор класса
    Point getMidpoint();              // найти середину отрезка
    double getLength();               // найти длину отрезка
};

// --------- Класс "Вектор" --------------

class Vector {
    long double x;
    long double y;
public:
    Vector(Point p1, Point p2);
    long double scalar_product(Vector v2);
    static Vector vector_sum(Vector v1, Vector v2);
    void multiply_by_scalar(long double scalar);

    long double get_x();
    long double get_y();
    void info();
};



#endif

// =============== конец заголовочного файла  ==================
