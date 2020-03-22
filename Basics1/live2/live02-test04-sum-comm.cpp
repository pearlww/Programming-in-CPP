//============================================================================
// Name        : live02-test07-choose.cpp
// Description : Examples showing that side-effects in expressions
//				 violate arithmetic axioms such as commutativity
//============================================================================

#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    int y = 0;

    cout << "Hello, world!" << endl;
    cout << "Give me a number please: ";
    cin >> x ;
    y = x ;

    cout << "Is x++ + 2*x equal to 2*x + x++ ?" << endl ;
    cout << " In your case..." << endl ;
    cout << "  Is "        << x++ + 2*x <<
            " equal to " << 2*y + y++ << "?" << endl ;
    // The main point is that ++ increments a variable within an expression
    // We have thus a "side effect"
    // Side effects are a bad practice
    // and should be avoided when possible
    // They may result in undesired/undefined results
    // see http://en.cppreference.com/w/cpp/language/eval_order
	system("pause");
    return 0;
}
