
#include "fibonacci-trees.h"
#include <algorithm>
#include <iostream>

FibonacciTree::FibonacciTree(){
		this->value = 1;
		this->left = nullptr;
		this->right = nullptr;

}
FibonacciTree * FibonacciTree::ConstructTree(int n){

	FibonacciTree * p;
	vector<FibonacciTree *> f;

	for (int i = 0; i <=n; i++){
		p = new FibonacciTree();
		f.push_back(p);

		if (i >= 2){
			f[i]->value = f[i - 2]->value + f[i - 1]->value;
			f[i]->left = f[i - 1];
			f[i]->right = f[i - 2];
		}	
	}
	return f[n];

}

FibonacciTree::~FibonacciTree(){
	if (left != nullptr)
		delete left;
	if (right != nullptr)
		delete right;
}
int FibonacciTree::size(){
	if (value==1)
		return 1;
	else
		return 1 + left->size() + right->size();
}
int FibonacciTree::depth(){
	if (value == 1)
		return 1;
	else
		return 1 + max(left->depth(), right->depth());
}
int FibonacciTree::leaves(){
	if (value == 1)
		return 1;
	else
		return left->leaves() + right->leaves();
}
void FibonacciTree::pre_order(){
	if (value == 1)
		cout << value<<' ';
	else{
		cout << value << ' ';
		left->pre_order();
		right->pre_order();
	}


}