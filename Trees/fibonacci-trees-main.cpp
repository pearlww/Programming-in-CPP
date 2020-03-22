#include <iostream>
#include "fibonacci-trees.h"

using namespace std;

int main(){

	int n;
	cin >> n;

	FibonacciTree * root=new FibonacciTree();
	root=root->ConstructTree(n);

	cout << "Call tree in pre-order: ";
	root->pre_order();
	cout << endl;
	cout << "Call tree size: " << root->size() << endl;
	cout << "Call tree depth: " << root->depth() << endl;
	cout << "Call tree leafs: " << root->leaves() << endl;

	system("pause");
	return 0;
}
