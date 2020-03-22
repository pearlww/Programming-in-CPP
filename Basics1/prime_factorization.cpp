#include <iostream>
#include <string>

using namespace std;
void function(void);

int function(int x)
{
	//int a[100];
	//int j = 0;
	int i;
	for (i =2 ; i <= x; i++)
	{
		if (x % i == 0)
		{		
			if (i<x)
				cout << i << " * ";
			else
				cout << i << endl;
            x = x / i;
			i = 1;
		}
	}
		
	return 0;
}

int main()
{
    int n;
	cin >> n;
	function(n);
	//cout << result << endl;
	system("pause");
	return 0;

}