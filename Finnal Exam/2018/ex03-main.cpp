#include <iostream>
#include "ex03-library.h"

int main() {
	TemperatureScalesConverter tsc;
	cout << "Default measurement of 0C = 32F :" << endl;
	tsc.print();
	cout << endl;
	
	double f = tsc.convertToF(20);
	cout << "20 Celsius = " << f << " Fahrenheit" << endl;
	double c = tsc.convertToC(30);
	cout << "30 Fahrenheit = " << c << " Celsius" << endl;
	
	bool res = tsc.addMeasurement("C", 20);
	if(!res){
		cout << "tsc.addMeasurement(\"C\", 20); FAILED" << endl;
	}
	res = tsc.addMeasurement("F", 30);
	if(!res){
		cout << "tsc.addMeasurement(\"F\", 30); FAILED" << endl;
	}
	tsc.print();	cout << endl;
	
	res = tsc.addMeasurement("K", 50);
	if(!res){
		cout << "tsc.addMeasurement(\"K\", 50); FAILED" << endl;
	}
	tsc.print();
	
	return 0;
}