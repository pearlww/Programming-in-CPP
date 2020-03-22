//============================================================================
// Name        : inclasslive00employees.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "employees.h"

using namespace std;


int main() {
	cout << "!!!Hello Employees!!!" << endl; // prints !!!Hello World!!!

	vector<Employee *> employees;

	HourlyEmployee * andrea = new HourlyEmployee("Andrea", 400);
	andrea->setWorkingHours(40);
	employees.push_back(andrea);

	SalariedEmployee * alberto = new SalariedEmployee("Alberto", 30000);
	employees.push_back(alberto);

	Employee * current;
	for(int i=0;i<employees.size();i++){
		current = employees[i];
		cout << "The salary of " << current->getName() <<
				" is " << current->computePay() << endl;
	}


	return 0;
}
