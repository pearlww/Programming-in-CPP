#include <iostream>

using namespace std;

void reverse(){
	int n;
	cin >> n;
	if (cin.fail())  //cin.fail() detects whether the value entered fits the value defined in the variable.
		return;
	else{
		reverse();
		cout << n<<' ';
	}
		


}

int main(){

	reverse();
	system("pause");
	return 0;
}