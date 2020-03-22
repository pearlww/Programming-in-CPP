#include "BankAccount.h"
#include <iostream>


/*BankAccount::BankAccount() {
	// TODO Auto-generated constructor stub

}*/

BankAccount::BankAccount(int number, std::string owner, double balance) {
	this->number=number;
	this->owner=owner;
	this->balance=balance;
}


double BankAccount::getBalance() const {
	return balance;
}

int BankAccount::getNumber() const {
	return number;
}

const std::string BankAccount::getOwner() const {
	return owner;
}

void BankAccount::print() const {
	std::cout << "Account number " << number << " owned by " << owner << " contains " << balance << ".\n";
}

bool BankAccount::trasnferMoney(BankAccount& to, double value) {
	if(value < 0 ||balance < value){
		std::cout << "Transfer failed.\n";
		return false;
	}
	else{
		balance-=value;
		to.balance+=value;
		std::cout << "Transfer succeeded.\n";
		return true;
	}
}

bool BankAccount::wrongTrasnferMoney(BankAccount to, double value) {
	if(value < 0 ||balance < value){
		std::cout << "Transfer failed.\n";
		return false;
	}
	else{
		balance-=value;
		to.balance+=value;
		std::cout << "Transfer succeeded.\n";
		return true;
	}
}

/*
bool BankAccount::trasnferMoney(BankAccount& to, double value) {
	bool res = withdraw(value);
	if(res){
		res=deposit(value);
	}
	return res;
}
*/

bool BankAccount::withdraw(double value) {
	if(value < 0 ||balance < value){
		return false;
	}
	else{
		balance-=value;
		return true;
	}
}

bool BankAccount::deposit(double value) {
	balance+=value;
	return true;
}

/*
bool BankAccount::deposit(double value) {
	if(value <0){
		return false;
	}
	else{
		balance+=value;
	}
	return true;
}
*/
