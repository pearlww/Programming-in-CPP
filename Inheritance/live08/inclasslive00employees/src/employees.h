/*
 * employees.h
 *
 *  Created on: 4 Nov 2019
 *      Author: andrea
 */

#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_

#include <string>

using namespace std;

class Employee {
//private:
protected:
	string name;
public:
	//Employee();
	Employee(string name);
	string getName();
	//virtual string getName();
	virtual double computePay()=0;
	virtual ~Employee(){}
};

class HourlyEmployee : public Employee{
public:
	HourlyEmployee(string name,double hoursSalary);
	double computePay();
	void setWorkingHours(int numberOfHours);
	string getName();

private:
	double hoursSalary;
	int numberOfHours;
};

class SalariedEmployee : public Employee{
public:
	SalariedEmployee(string name,double salary);
	double computePay();

private:
	double salary;
};

#endif /* EMPLOYEES_H_ */
