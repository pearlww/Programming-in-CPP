//============================================================================
// Name        : live02-test07-choose.cpp
// Description : Implementation of the factorial and binomial (choose) functions
//============================================================================

#include <iostream>

#include <time.h>

using namespace std;

// factorial function
int fact(int n){

    int result;
    int i;

    result=1;

    for(i=1; i<=n; i++){
        result = result * i;
    }
    return result;
}

// choose based on factorial
int choose1(int n, int k){

	clock_t start_s=clock();

	int res = fact(n)/(fact(n-k)*fact(k));

	//Clock does not work on Windows machins using cygwin
	clock_t stop_s=clock();
	double seconds = ((double)(stop_s - start_s))/CLOCKS_PER_SEC;
	cout << "[ " << seconds << " seconds ] ";


    return res;

}

// choose based on http://en.wikipedia.org/wiki/Binomial_coefficient#Multiplicative_formula
int choose2(int n, int k){

	clock_t start_s=clock();

    int result;
    int i;

    result=1;

    for(i=1; i<=k; i++){
        result = result * ( ((n+1)-i) / (double)i);
    }

    clock_t stop_s=clock();
	double seconds = ((double)(stop_s - start_s))/CLOCKS_PER_SEC;
	cout << "[ " << seconds << " seconds ] ";

    return result;

}

int main(){

    int n = 0;
    int k = 0;

    cout << "Please enter n and k in what follows:" << endl;
    cout << "n = " ;
    cin >> n;
    cout << "k = " ;
    cin >> k;
    cout << "Results computed with several functions:\n" ;
    //cout<< "fact(n)" << fact(n) << endl;
    //cout<< "fact(n-k)" << fact(n) << endl;
    //cout<< "fact(k)" << fact(k) << endl;
    cout << "(1) " << choose1(n,k) << endl;
    cout << "(2) " << choose2(n,k) << endl;
	system("pause");
    return 0;
}
