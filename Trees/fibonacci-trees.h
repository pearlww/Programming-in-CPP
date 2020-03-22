#ifndef __FIBONACCI_TREES__
#define __FIBONACCI_TREES__

#include <vector>

using namespace std;

class FibonacciTree{
public:
	FibonacciTree();
	//FibonacciTree(int n);
	~FibonacciTree();
	FibonacciTree * ConstructTree(int n);
	int size();
	int depth();
	int leaves();
	void pre_order();
private:
	int value;
	FibonacciTree *left;
	FibonacciTree *right;
};



#endif