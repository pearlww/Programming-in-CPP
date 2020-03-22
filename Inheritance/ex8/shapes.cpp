
#include "shapes.h"


Shape::Shape(double h, double w){
	this->w = w;
	this->h = h;
}
double Shape::height(){
	return this->h;
}
double Shape::width(){
	return this->w;
}
void Shape::rotate(){
	double t = this->h;
	this->h = this->w;
	this->w = t;
}

Rectangle::Rectangle(double h, double w) :Shape(3,4){
	this->w = w;
	this->h = h;
}
double Rectangle::area(){
	return w*h;
}
double Rectangle::perimeter(){
	return 2 * (w + h);
}


Circle::Circle(double r) : Shape(3,4){
	this->radius = r;
	this->h = 2*r;
	this->w = 2*r;
}
double Circle::area(){
	return PI*radius*radius;
}
double Circle::perimeter(){
	return 2 * PI *radius;
}

Square::Square(double s) : Rectangle(3, 4){
	this->w = s;
	this->h = s;
}