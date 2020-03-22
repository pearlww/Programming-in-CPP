#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){


	vector<int> a;
	vector<int> b;
	char c;
	int n;
	int flag = 1;
	while (flag){
		cin >> c;
		cin >> n;
		if (c == 'a')
		   a.push_back(n);
		else
		   b.push_back(n);

		if (getchar()=='\n')
			flag = 0;

	}

	/* 1
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i : a){
		cout << i<<' ';
	}
	for (int i : b){
		cout << i << ' ';
	}
	*/
	/* 2
	int m = max(a.size(), b.size());
	for (int i = 0; i < m; i++){
		if (i<a.size())
		  cout << a[i]<<' ';
		if (i<b.size())
		  cout << b[i]<<' ';
	}
	*/

	// 3
	int product = 0;
	int m = max(a.size(), b.size());
	for (int i = 0; i < m; i++)
		product += a[i] * b[i];

	cout << product << endl;

	system("pause");
	return 0;
}