#include <iostream>
#include <cmath>

using namespace std;

const int PREDEFINEDSIZE=3;

void GaussianSum(int n, int array[]){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=array[i];
	}
	cout << "The sum of the numbers in the array is " << sum << "\n";
}

void printArray(int n, int array[]){
	cout << "The array contains: \n\t";
	for(int i=0;i<n;i++){
		cout << array[i] << " ";
	}
	cout << "\n";
}

int main(){

	/*
	 * An array specified at compile time
	 */
	int aGiven [] = { 3, 1, 2};
	printArray(3,aGiven);
	GaussianSum(3,aGiven);

	cout << "\n\n";

	/*
	 * An array of length specified at compile time
	 */
	int aLengthComp [PREDEFINEDSIZE]; //this is use stack
	cout << "Give me the " << PREDEFINEDSIZE << " numbers:\n";
	for(int i=0;i<PREDEFINEDSIZE;i++){
		cin >> aLengthComp[i];
	}
	printArray(PREDEFINEDSIZE,aLengthComp);
	GaussianSum(PREDEFINEDSIZE,aLengthComp);

	cout << "\n\n";

	/*
	 * An array of length specified at runtime
	 */
	int n=0;
	int *aLengthRun;
	cout << "Give me the size of the array:\n";
	cin >> n;

	aLengthRun = new int[n];//this pointer point to this array,new is use heap.(dynamic allocation always use heap)

	cout << "Give me the " << n << " numbers:\n";
	for(int i=0;i<n;i++){
		cin >> aLengthRun[i];
	}
	printArray(n,aLengthComp);
	GaussianSum(n,aLengthComp);

	delete[] aLengthRun;//release the space

	cout << "\n\n";


	/*
	 * An matrix of size n*n, where n is specified at runtime
	 */
	cout << "Give me the size of the n*n squared matrix:\n";
	cin >> n;
	int **squaredMatrix=new int*[n];
	for(int i=0;i<n;i++){
		squaredMatrix[i]=new int[n];
	}

	for(int i=0;i<n;i++){
		delete[] squaredMatrix[i];
	}
	delete[] squaredMatrix;
	system("pause");
	return 0;
}
