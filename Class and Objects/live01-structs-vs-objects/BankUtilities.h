#ifndef BANKUTIL_H_ //what this?
#define BANKUTIL_H_

#include<string>

struct BankAccountStruct{
	int number;
	std::string owner;
	double balance;
};

/**
  * Print information on the bank account passed as parameter.
  */
void printAccount(const BankAccountStruct &acc);

/**
 * Transfer 'value' money from 'from' account to the account 'to'.
 * Given that we pass the accounts by reference (using BankAccountStruct &name), any change to the accounts will persist in the original accounts passed as parameters.
 * Instead, when passing objects by value (using BankAccountStruct name) we actually create a copy of the struct passed by parameter, and changes done by the function will NOT persist in the original account passed as parameter.
 */
bool trasnferMoney(BankAccountStruct &from,BankAccountStruct &to, double value);

#endif /* BANKUTIL_H_ */
