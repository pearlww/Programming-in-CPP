#include <iostream>


using namespace std;

int fibonacci(int a){
	if (a == 0)
		return 1;
	else if (a == 1)
		return 1;
	else{
		return fibonacci(a - 1) + fibonacci(a - 2);
	}

}

int main(){
	int n;
	while (1){
     	cin >>n;
		if (cin.fail()) 
			break;
		cout << fibonacci(n) << ' ';
	}

	system("pause");
	return 0;
}