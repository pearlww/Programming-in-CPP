//============================================================================
// Name        : live02-test02-imprecision.cpp
// Description : Examples of arithmetic imprecision
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    float x=1.3232324423;
    float y=1.543454554;
    float z=0.5000000894069671353303618843710864894092082977294921875;

    cout << "x is " << x << " and y is " << y << endl;
    cout << "Is " << std::setprecision(20) << (x+y)/z <<
    " equal to " << std::setprecision(20) << (x/z)+(y/z) << " ?\n" ;

    cout  << ((x+y)/z==(x/z)+(y/z)?"yes!":"no!") <<endl ;

    cout << "What is 0.1 + 0.2 - 0.3? It's... ";
    cout << ( 0.1 + 0.2 ) - 0.3 << endl;
	system("pause");
    return 0;
}
