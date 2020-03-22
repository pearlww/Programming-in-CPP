//============================================================================
// Name        : live02-test03-exponentiation.cpp
// Description : Four possible implementations of the exponentiation function (1. using math::pow, 2. recursive, 3.4. iterative)
//============================================================================

#include <iostream>
#include <math.h> // library with some mathematical functions
using namespace std;

// we declare here several exponentiation functions
// with the same signature/header
// they all compute a^n
double exp1(int a, int n);
double exp2(int a, int n);
double exp3(int a, int n);
double exp4(int a, int n);

// this version just uses the "pow" function of library "math"
double exp1(int a, int n){
    return pow((double)a,(double)n);
}

// recursive formulation
double exp2(int a, int n){

    if (n==0) {
        return 1.0 ;
    }

    if (n<0) {
        return 1.0/exp2(a,-n);
    }
    else {
        return a*exp2(a,n-1);
    }
}

// iterative implementation
double exp3(int a, int n){

    int i = 0;
    double result = 1;
    double factor = 0.0;

    result = 1;
    //factor = (n>=0?a:1.0/a);
    if (n>=0)
        factor = a;
    else
        factor = 1.0/a;

    for (i=1; i<=abs(n); i=i+1) {
        result = result * factor;
    }

    return result;
}

// yet another implementation
double exp4(int a, int n){

    int i;
    double result;

    result = 1;

    for (i=1; i<=abs(n); i++) {
        result = result * a;
    }

    if (n<0) {
        result = 1.0 / result ;
    }

    return result;
}

int main(){

    int a = 0;
    int n = 0;

    cout << "Please enter a and n in what follows." << endl;
    cout << "a = " ;
    cin >> a;
    cout << "n = " ;
    cin >> n;

    cout << "Results computed with several functions:" << endl ;
    cout << "(1) " << a << " ^ " << n << " = " << exp1(a,n) << endl;
    cout << "(2) " << a << " ^ " << n << " = " << exp2(a,n) << endl;
    cout << "(3) " << a << " ^ " << n << " = " << exp3(a,n) << endl;
    cout << "(4) " << a << " ^ " << n << " = " << exp4(a,n) << endl;

	system("pause");
    return 0;

}
