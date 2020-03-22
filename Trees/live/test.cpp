//============================================================================
// Name        : assignment11.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : From arithmetic expression to syntax tree
//============================================================================

#include <iostream>


#include "arithmetic-syntax-trees.h"

int main(){
	//(2 * 3) + (4 * 5) + 1
	//
	//				    +		//plus1
	//         /         \
	//		  +			  1		//plus2
	//     /     \
	//   *         *				//star1,star2
	// /   \      /  \
	//2     3    4     5
	//
	//
	//

	//ArithmeticSyntaxTree *one, two, three, four, five; WRONG! only one is a pointer
	ArithmeticSyntaxTree *one,* two,* three,* four,* five;
	ArithmeticSyntaxTree *plus1,* plus2,* star1,* star2;

	one = new ArithmeticSyntaxTree(1);
	two = new ArithmeticSyntaxTree(2);
	three = new ArithmeticSyntaxTree(3);
	four = new ArithmeticSyntaxTree(4);
	five = new ArithmeticSyntaxTree(5);

	star1 = new ArithmeticSyntaxTree('*',two,three);
	star2 = new ArithmeticSyntaxTree('*',four,five);
	plus2 = new ArithmeticSyntaxTree('+',star1,star2);
	plus1 = new ArithmeticSyntaxTree('+',plus2,one);

    ArithmeticSyntaxTree * root=plus1;
	//ArithmeticSyntaxTree * root = star2;
	//ArithmeticSyntaxTree * root = two;

    cout<< "The size is: "<<root->size() <<"\n";
    cout<< "The height is: "<<root->height() <<"\n";
    cout<< "The leaves are: "<<root->height() <<"\n";
    cout<< "Prefix notation:\n";
    root->traverse_pre();
    cout<< "\n";
    cout<< "In-fix notation:\n";
    root->traverse_in();
    cout<< "\n";
    return 0;
}






