//============================================================================
// Name        : live02-test05-evaluation-order.cpp
// Description : Example showing that the order of evaluation matters
// 				 Evaluation order is not always defined in C++
// 				 see http://en.cppreference.com/w/cpp/language/eval_order
//============================================================================

#include <iostream>
#include <string>
using namespace std;

// This function computes some property of an integer number
// ... with help of the program user :)
bool f(int x){

    string answer;

    cout << "Help! Does f(" << x << ") hold? (yes/no): ";
    cin >> answer ;

    if (answer == "yes" ) {
        return true;
    }
    else if (answer == "no"){
        return false;
    }
    else {
        cout << "I will take that for a no." << endl;
        return false;
    }

}

int main()
{
    int x = 0;

    cout << "Hello, world!" << endl;
    cout << "Give me a number please: ";
    cin >> x ;

    // In the condition of the "if" we first check f(x) and then x < 2
    cout << "\nDeciding if " << "\n\t" << "f(x) and x < 2..." << endl;
    if( f(x) && x < 2 ){
        cout << "Yes :)" << endl;
    } else {
        cout << "No :(" << endl;
    }

    // Now we do first the test x < 2 and then f(x)
    cout << "\nDeciding if " << "\n\t" << "x < 2 and f(x)..." << endl;
    if( x < 2 && f(x) ){
        cout << "Yes :)" << endl;
    } else {
        cout << "No :(" << endl;
    }
	system("pause");
    return 0;
}
