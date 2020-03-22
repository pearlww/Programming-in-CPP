#ifndef SHAPES_H_
#define SHAPES_H_

#include <math.h>

using namespace std;

const double PI = 3.141592653589793238463;

class Shape{
public:
	Shape(double h,double w);
	virtual double area()=0;
	virtual double perimeter()=0;
    double height();
    double width();
    void rotate();
protected:
	double w;
	double h;

};

class Rectangle : public Shape{
public:
	Rectangle(double w, double h);
	double area();
	double perimeter();
};
class Circle : public Shape{
public:
	Circle(double r);
	double area();
	double perimeter();
private:
	double radius;
};
class Square : public Rectangle{
public:
	Square(double s);
};
#endif