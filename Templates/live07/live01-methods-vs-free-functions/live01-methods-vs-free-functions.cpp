//============================================================================
// Name        : live02-methods-vs-free-functions.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Solution of the assignment, and discussion on methods and free functions
//============================================================================

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class fraction{

private:
    // Internal representation of a fraction as two integers
    int numerator;
    int denominator;

public:
    // Class constructor
    fraction(int n, int m);	// Construct the n/m
    fraction(int n);			// n/1

    // Accessor methods to get
    int getNumerator() const;       // Get the numerator (as fraction)
    int getDenominator() const;      // Get denominator (as fraction)

    // Methods to update the fraction
    void add(fraction f);   // Add a fraction
    void mult(fraction f);  // Multiply by a fraction
    void div(fraction f);   // Divide by a fraction

    // Method to simplify a fraction
    void simplify(void);

    // Display method
    void display() const;

};

int fraction::getNumerator() const{
    // we simply return the internal represenation of the numerator
    return numerator;
}

int fraction::getDenominator() const{
    // we simply return the internal represenation of the denominator
    return denominator;
}

fraction::fraction(int n, int m){
    // to build the new object we just use n and m to update
    // the internal representation of the numerator and denominator
    numerator = n;
    denominator = m;

    // we can simplify the fraction after addition
    // but this is not required
    simplify();

    return;
}

fraction::fraction(int n){
    // to build the new object we just use n and m to update
    // the internal representation of the numerator and denominator
    numerator = n;
    denominator = 1;

    return;
}


// "Free" function to add fractions
// it takes two fractions as input
// and returns a fraction as output
fraction add(const fraction & f1, fraction f2){
    // compute the numerator and denominator
    int n = (f1.getNumerator() * f2.getDenominator()) + (f2.getNumerator() * f1.getDenominator());
    int m = f1.getDenominator() * f2.getDenominator();

    // create a new fraction
    fraction f3(n,m);

    // return the new fraction
    return f3;
}

void fraction::add(fraction f){
    // note that method has to update the current fraction
    // instead of creating a new one
    numerator = (numerator * f.denominator) + (f.numerator * denominator);
    denominator =  denominator * f.denominator;

    // we can simplify the fraction after addition
    // but this is not required
    simplify();

    return;
}

// Free fraction for multiplication
// here

fraction mult(fraction f1, fraction f2){
    // this time we use the method mult
    fraction f3 = f1;
    f1.mult(f2);
    return f3;
}

void fraction::mult(fraction f){
    // similar as add
    numerator = numerator * f.numerator;
    denominator = denominator * f.denominator;

    // we can simplify the fraction after addition
    // but this is not required
    simplify();
    return;

}

// Free function for dividing fractions
fraction div(fraction f1, fraction f2){
    // this time we use the method mult
    fraction f3 = f1;
    f1.div(f2);
    return f3;
}

void fraction::div(fraction f){
    // similar as div
    numerator = numerator * f.denominator;
    denominator = denominator * f.numerator;

    // we can simplify the fraction after addition
    // but this is not required
    simplify();

    return;
}

void fraction::simplify() {
    // we first compute the greatest common divisor of
    // denominator and numerator
    // using, for example, the Euclidean algorithm
    // see https://en.wikipedia.org/wiki/Euclidean_algorithm
    int a = numerator;      // the gcd will be stored in a
    int b = denominator;
    while (b != 0)  {
        int t = b;
        b = a % b;
        a = t;
    }

    // once the gcd has been computed in a
    // all we have to do is to simplify the numerator
    // and the denominator
    numerator = numerator / a;
    denominator = denominator / a;

    // this is not necessary but we may want to choose
    // where to put the negative sign
    // in this case I choose to have it in the numerator
    if (denominator < 0){
        numerator = - numerator;
        denominator = - denominator;
    }
    return;
}

void fraction::display() const{
    cout << numerator << " / " << denominator << endl ;
    return;
}

int main(){

    // we declare some useful variables here
    int a,b,c,d;
    string s,op;

    fraction ff(1);

    // we will loop until we decide to break
    while(true){

        // read first fraction
        cin >> a;
        // if there was nothing useful to read, just break
        if(cin.fail()) break;
        cin >> s;
        cin >> b;
        // once we have read a and b we can build the first fraction
        fraction f1(a,b);

        // read operation
        cin >> op;

        // read second fraction
        cin >> c;
        cin >> s;
        cin >> d;
        fraction f2(c,d);

        // decide what to do depending on the operation
        if ( op == "+" ){
            // using methods
            //f1.add(f2);
            // using free functions
            f1 = add(f1,f2);
        } else if ( op == "*" ){
            // using methods
            // f1.mult(f2);
            // using free functions
            f1 = mult(f1,f2);
        } else if ( op == "div" ){
            // using methods
            // f1.div(f2);
            // using free functions
            f1 = div(f1,f2);
        }

        // simplify the fraction
        f1.simplify();
        // display it
        f1.display();

    }

    cout << "I terminate\n";

}

/* Test cases

2 / 3 + 4 / 5
22 / 15

1 / 4 + 1 / 2
3 / 4

1 / 2 * 3 / 4
3 / 8

1 / 2 * 2 / 4
1 / 4

1 / 2 div 1 / 2
1 / 1

1 / 2 div 4 / 2
1 / 4

*/
