//============================================================================
// Name        : ex03.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Exercise 3 - Currency converter
//============================================================================

#include <iostream>
#include "ex03-library.h"

int main() {
	CurrencyConverter cc;
	cout << "\naddCurrency(\"EUR\",7.44416);\n";
	cc.addCurrency("EUR",7.44416);
	cc.print();

	cout << "\naddCurrency(\"EUR\",17.44416);\n";
	cc.addCurrency("EUR",17.44416);
	cc.print();

	cout << "\naddCurrency(\"USD\",16.31708);\n";
	cc.addCurrency("USD",16.31708);
	cc.print();

	cout << "\nupdateExchangeRate(\"USD\",6.31708);\n";
	cc.updateExchangeRate("USD",6.31708);
	cc.print();

	cout <<"\n\n";

	double amountDKK=100;
	double amountEUR=cc.convertFromDKK(amountDKK,"EUR");
	cout << amountDKK <<" DKK = " << amountEUR << " EUR\n";

	amountDKK = cc.convertToDKK(amountEUR,"EUR");
	cout << amountEUR <<" EUR = " << amountDKK << " DKK\n";

	system("pause");
	return 0;
}