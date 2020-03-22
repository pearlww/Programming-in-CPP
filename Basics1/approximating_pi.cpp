#include <iostream>
#include <string>
#include <math.h>

using namespace std;
void function(void);

double pi(int x)
{
	double result=0.0;
	for (int i = 0; i < x; i++)
		result +=( pow(-1, i) / (2 * i + 1));
	
	result *= 4;
	return result;
}

int main()
{
	int n;
	cin >> n;
	double result=pi(n);
	cout << result << endl;
	system("pause");
	return 0;

}