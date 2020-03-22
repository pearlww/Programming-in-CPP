//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Any circle    is a shape.
//			 	 Any rectangle is a shape.
//			 	 Any square    is a rectangle (and hence a shape)
//============================================================================

#include <iostream>
#include <vector>
#include "shapes.h"

using namespace std;

int main(void){

    vector<Shape *> shapes;

    Rectangle u(2,5);
    shapes.push_back(&u);
    Square v(3);
    shapes.push_back(&v);
    Circle w(2);
    shapes.push_back(&w);


    // Enumerating all areas
    cout << "Areas..." << endl;
    double area = 0;
    for(int i=0;i<shapes.size();i++){
    		Shape * p = shapes[i];
        cout << p->area() << " ";
        area += p->area();
    }
    cout << endl << "Total area is " << area << endl;

    // Enumerating all areas
    cout << "Perimeters..." << endl;
    double perimeter = 0;
    for(int i=0;i<shapes.size();i++){
        	Shape * p = shapes[i];
        cout << p->perimeter() << " ";
        perimeter += p->perimeter();
    }
    cout << endl << "Total perimeter is " << perimeter << endl;

    // I want to put them side-by-side
    // And see how much space they use (width and height)
    cout << "Placing side-by-side..." << endl;
    double width = 0;
    double height = 0;
    for(int i=0;i<shapes.size();i++){
        	Shape * p = shapes[i];
        width += p->width();
        if(height < p->height()){
            height = p->height();
        }
    }
    cout << "Total width is " << width << endl;
    cout << "Total height is " << height << endl;

    // I now try to do the same, but minimizing width
    // First, I rotate those shapes that need it
    for(int i=0;i<shapes.size();i++){
        	Shape * p = shapes[i];
        if(p->width() > p->height()) {
            p->rotate();
        }
    }
    // Then I proceed as before
    cout << "Placing side-by-side..." << endl;
    width = 0;
    height = 0;
    for(int i=0;i<shapes.size();i++){
        	Shape * p = shapes[i];
        width += p->width();
        if(height < p->height()){
            height = p->height();
        }
    }
    cout << "Total width is " << width << endl;
    cout << "Total height is " << height << endl;

	system("pause");
    return 0;

}
