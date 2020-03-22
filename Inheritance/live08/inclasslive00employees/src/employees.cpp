/*
 * employees.cpp
 *
 *  Created on: 4 Nov 2019
 *      Author: andrea
 */

#include "employees.h"

//Employee::Employee(){}
Employee::Employee(string name){
	this->name=name;
}
string Employee::getName(){
	return name;
}

HourlyEmployee::HourlyEmployee(string name,double hoursSalary) : Employee(name){
//	this->name=name;
	this->hoursSalary=hoursSalary;
	this->numberOfHours=37;
}
double HourlyEmployee::computePay(){
	return hoursSalary*numberOfHours;
}
void HourlyEmployee::setWorkingHours(int numberOfHours){
	this->numberOfHours=numberOfHours;
}

//If Employee::getName() is virtual, then this version of the method will be actually used.
string HourlyEmployee::getName(){
	return "H"+name;
}


SalariedEmployee::SalariedEmployee(string name,double salary) : Employee(name){
	this->salary=salary;
}
double SalariedEmployee::computePay(){
	return salary;
}
