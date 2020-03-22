#ifndef EX03_LIBRARY_H_
#define EX03_LIBRARY_H_

#include <string>
#include <map>
#include <set>
using namespace std;
class CurrencyConverter {
private:
	set<string> currencies;
	/*
	 * Map from a currency to its exchange rate to DKK
	 */
	map<string,double> currencyToExchangeRate;
public:
	//Do not modify
	/*
	 * Create a currency converter with one currency only: DKK, and exchange rate 1
	 * DKK will be used as the base currency. All further introduced currencies will be provided with the exchange rate to DKK
	 */
	CurrencyConverter();

	//Do not modify
	/*
	 * Return true if the converter has an exchange rate for the provided currency
	 */
	bool supportsCurrency(string currencyCode);

	//Exercise 3 (a) Check and correct if necessary
	/*
	 * Print information on the supported currencies:
	 * 	currency DKK has exchange rate 1
	 * 	...
	 */
	void print();

	//Exercise 3 (b) Check and correct if necessary
	/*
	 * Add a new currency, providing the exchange rate from the currency to DKK.
	 * In other words, we can exchange an amount from the currency to DKK by multiplying it by the exhcange rate.
	 * Special cases:
	 * 	If the currency was already supported, ignore the request, and return false.
	 * 	If the exchange rate is not positive, ignore the request, and return false.
	 */
	bool addCurrency(string currencyCode, double exchangeRateToDKK);

	//Exercise 3 (c) Implement this function
	/*
	 * Update the exchange rate of an existing currency.
	 * Special cases:
	 * 	If the currency was NOT already supported, ignore the request, and return false.
	 * 	If the new exchange rate is not positive, ignore the request, and return false.
	 * 	If currencyCode is DKK, ignore the request and return false.
	 */
	bool updateExchangeRate(string currencyCode, double newExchangeRate);

	//Exercise 3 (d) Implement this function
	/*
	 * This method should convert (and return) amount from currencyCodeOfSource to DKK.
	 * Special cases:
	 * 	If the source currency is not supported return -1
	 * 	If the amount is not positive, return -1
	 */
	double convertToDKK(double amount,string currencyCodeOfSource);

	//Exercise 3 (e) Implement this function
	/*
	 * Convert the given DKK in the target currency.
	 * Special cases:
	 * 	If the target currency is not supported return -1
	 * 	If the amount is not positive, return -1
	 */
	double convertFromDKK(double amountDKK,string currencyCodeOfTarget);
};

#endif /* EX03_LIBRARY_H_ */
