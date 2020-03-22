#include <iostream>
#include <string>
#include <math.h>

using namespace std;
int FindMax(int n, int a[]);

int main(){
	int l = 0;
	int n = 0;
	int *array;

	cin >> l >> n;
	//use dynamic allocatation(heap), or just use stack:array =int[n]
	array =new int[n];
	for (int i = 0; i < n; i++)
		cin >> array[i];
	int max = FindMax(n, array);
	int k = ceil((float)max / l);

	for (int i = 0; i < l;i++){
		int num = 0;
		cout << i*k <<": ";
		for (int j = 0; j < n; j++){
			if (array[j] >= i*k && array[j] <(i + 1)*k)
				num++;
			if (i==l-1 && array[j] ==(i + 1)*k)
				num++;
		}
		cout << num << endl;
	}
	system("pause");
	delete[] array;//release the space
	return 0;
}

int FindMax(int n,int a[]){
	int max = 0;
	for (int i = 0; i < n; i++){
		if (a[i] > max)
			max = a[i];
	}
	return max;
}