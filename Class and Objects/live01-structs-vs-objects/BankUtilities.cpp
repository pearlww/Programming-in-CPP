#include "BankUtilities.h"
#include <iostream>

bool trasnferMoney(BankAccountStruct &from,BankAccountStruct &to, double value){
	if(value < 0 ||from.balance < value){
		std::cout << "Transfer failed.\n";
		return false;
	}
	else{
		from.balance-=value;
		to.balance+=value;
		std::cout << "Transfer succeeded.\n";
		return true;
	}
}

void printAccount(const BankAccountStruct &acc){
	std::cout << "Account number " << acc.number << " owned by " << acc.owner << " contains " << acc.balance << ".\n";
}


