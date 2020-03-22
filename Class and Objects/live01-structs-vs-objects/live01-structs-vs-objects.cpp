//============================================================================
// Name        : live01-structs-vs-objects.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Main differences among structs andf objects - encapsulation
//============================================================================

#include <iostream>
#include "BankUtilities.h"
#include "BankAccount.h"
using namespace std;

void exampleWithStructs();
void exampleWithOO();

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	exampleWithStructs();

	exampleWithOO();
	system("pause");
	return 0;
}

void exampleWithStructs(){
	cout << "\n!!!Example with structs!!!\n" << endl;

	//Create Alice's bank account, containing 1000 DKK
	BankAccountStruct accA={1,"Alice",1000};
	//Create BOB's bank account, containing 500 DKK
	BankAccountStruct accB={2,"Bob",500};

	//Print information of the two accounts
	printAccount(accA);
	printAccount(accB);

	//Transfer money from Alice's account to Bob's one, and then print information of the two accounts
	trasnferMoney(accA,accB,10);
	printAccount(accA);
	printAccount(accB);

	//Attempt to transfer money from Alice's account to Bob's one that will fail: Alice does not have 5000 DKK.
	trasnferMoney(accA,accB,5000);
	printAccount(accA);
	printAccount(accB);

	//Sadly, it is posiblw to access and modift the internal fields of structs.
	cout << "\nBut unfortunately no one can guarantee that such methods are used...\n" << endl;
	accA.balance-=100;
	printAccount(accA);
	accA.owner="Bob";
	printAccount(accA);
}

void exampleWithOO(){
	cout << "\n!!!Example with OO!!!\n" << endl;

	//Create Alice's bank account, containing 1000 DKK
	BankAccount accA(1,"Alice",1000);
	//Create BOB's bank account, containing 500 DKK
	BankAccount accB(2,"Bob",500);

	//Print information of the two accounts
	accA.print();
	accB.print();

	//Transfer money from Alice's account to Bob's one, and then print information of the two accounts
	accA.trasnferMoney(accB,10);
	accA.print();
	accB.print();

	//Attempt to transfer money from Alice's account to Bob's one that will fail: Alice does not have 5000 DKK.
	accA.trasnferMoney(accB,5000);
	accA.print();
	accB.print();

	//WRONG Transfer money from Alice's account to Bob's one, and then print information of the two accounts
	//We will actually withdraw money from Alice's account (from 990 to 980), but we will not add such money to Bob's account (which will remain with 510).
	//This is because this time we pass accB by value, hence a copy of the account is passed to the method, and modified. Instead the original accB will stay unchanged.
	accA.wrongTrasnferMoney(accB,10);
	accA.print();
	accB.print();

	
	

	//Thanks to OO encapsulation, we don't run the risk of unauthorized modifications of accounts' internal fields. Both commands belowe lead to compilation errors
	//accA.balance-=100;
	//accA.owner="Bob";
}
