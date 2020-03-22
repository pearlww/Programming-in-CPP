#include "include.h"

using namespace std;

fraction::fraction(int n, int d)
{
	numenator = n;
	denominator = d;
}
fraction::~fraction()
{
}

int fraction::findGCD(int num, int den)
{
	int gcd = 1;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			if (den % i == 0) {
				gcd = i;
			}
		}
	}
	return gcd;
}

void fraction::add(fraction f)
{
	int num = f.numenator * denominator + f.denominator * numenator;
	int den = f.denominator * denominator;
	int GCD = findGCD(num, den);

	numenator = num / GCD;
	denominator = den / GCD;
}

void fraction::sub(fraction f)
{
	int num = f.denominator * numenator - f.numenator * denominator;
	int den = f.denominator * denominator;
	int GCD = findGCD(num, den);

	numenator = num / GCD;
	denominator = den / GCD;
}

void fraction::mult(fraction f)
{
	int num = f.numenator * numenator;
	int den = f.denominator * denominator;
	int GCD = findGCD(num, den);

	numenator = num / GCD;
	denominator = den / GCD;
}

void fraction::div(fraction f)
{
	int num = f.denominator * numenator;
	int den = f.numenator * denominator;
	int GCD = findGCD(num, den);

	numenator = num / GCD;
	denominator = den / GCD;
}

void fraction::display(void)
{
	cout << numenator << "/" << denominator<<endl;
}

int* fraction::findPrime(int num)  //prime[0] is the number of prime from 1 to num and prime here do not consider 1.
{
	static int prime[255] = { 0 };
	int index = 1;
	for (int i = 2; i <= num; i++) {
		bool primeFlag = true;
		for (int j = 2; j < i; j++) {		
			if (i % j != 0) continue;
			else {
				primeFlag = false;
				break;
			}
		}
		if (primeFlag == true) {
			prime[index++] = i;
		}
	}
	prime[0] = index - 1;
	return prime;
}

int fraction::pow(int num, int exp)
{
	int result;
	if (exp == 0)
		result = 1;
	else {
		for (int i = 0; i < exp - 1; i++) {
			num *= num;
		}
		result = num;
	}	
	return result;
}

void fraction::challengeAdd(fraction f)
{
	int prime_n1_Cnt[1024];
	int prime_n2_Cnt[1024];
	int prime_d1_Cnt[1024];
	int prime_d2_Cnt[1024];
	int num1[1024];
	int den1[1024];
	int num2[1024];
	int den2[1024];

    int *prime_num1 = findPrime(numenator);
	
	cout << "prime_num1's array:  ";
	for (int i = 1; i <= prime_num1[0]; i++) {
		printf("%3d ", prime_num1[i]);
	}
	cout << endl;

	cout << "prime_num1's number: ";
	int num = numenator;
	for (int i = 1; i <= prime_num1[0]; i++) {
		int cnt = 0;
		while (true) {
			if (num % prime_num1[i] == 0) {
				cnt++;
				num /= prime_num1[i];
			}
			else {
				break;
			}
		}
		prime_n1_Cnt[i] = cnt;  //i start from 1 but not 0
		printf("%3d ", cnt);
	}
	cout << endl;


	int *prime_num2 = findPrime(f.numenator);

	cout << "prime_num2's array:  ";
	for (int i = 1; i <= prime_num2[0]; i++) {
		printf("%3d ", prime_num2[i]);
	}
	cout << endl;

	cout << "prime_num2's number: ";
	num = f.numenator;
	for (int i = 1; i <= prime_num2[0]; i++) {
		int cnt = 0;
		while (true) {
			if (num % prime_num2[i] == 0) {
				cnt++;
				num /= prime_num2[i];
			}
			else {
				break;
			}
		}
		prime_n2_Cnt[i] = cnt;  //i start from 1 but not 0
		printf("%3d ", cnt);
	}
	cout << endl;


	int *prime_den1 = findPrime(denominator);

	cout << "prime_den1's array:  ";
	for (int i = 1; i <= prime_den1[0]; i++) {
		printf("%3d ", prime_den1[i]);
	}
	cout << endl;

	cout << "prime_den1's number: ";
	int den = denominator;
	for (int i = 1; i <= prime_den1[0]; i++) {
		int cnt = 0;
		while (true) {
			if (den % prime_den1[i] == 0) {
				cnt++;
				den /= prime_den1[i];
			}
			else {
				break;
			}
		}
		prime_d1_Cnt[i] = cnt;  //i start from 1 but not 0
		printf("%3d ", cnt);
	}
	cout << endl;


	int *prime_den2 = findPrime(f.denominator);

	cout << "prime_den2's array:  ";
	for (int i = 1; i <= prime_den2[0]; i++) {
		printf("%3d ", prime_den2[i]);
	}
	cout << endl;

	cout << "prime_den2's number: ";
	den = f.denominator;
	for (int i = 1; i <= prime_den2[0]; i++) {
		int cnt = 0;
		while (true) {
			if (den % prime_den2[i] == 0) {
				cnt++;
				den /= prime_den2[i];
			}
			else {
				break;
			}
		}
		prime_d2_Cnt[i] = cnt;  //i start from 1 but not 0
		printf("%3d ", cnt);
	}

	//start caculate
	int count = 0;

	//n1
	if (prime_num1[0] > prime_den2[0]) {
		count = prime_den2[0];
		for (int i = 1; i <= count; i++) {
			num1[i - 1] = prime_n1_Cnt[i] + prime_d2_Cnt[i];
		}
		int n1 = 0;
		for (int i = 0; i < count; i++) {
			n1 *= pow(prime_den2[i + 1], num1[i]);
		}
	}
	else {
		count = prime_num1[0];
		for (int i = 1; i <= count; i++) {
			num1[i - 1] = prime_n1_Cnt[i] + prime_d2_Cnt[i];
		}
		int n1 = 0;
		for (int i = 0; i < count; i++) {
			n1 *= pow(prime_num1[i + 1], num1[i]);
		}
	}
	
}

void fraction::challengeSub(fraction f)
{

}

void fraction::challengeMult(fraction f)
{

}

void fraction::challengeDiv(fraction f)
{

}

