#include <iostream>

#include "arithmetic-syntax-trees.h"

#include <math.h>
#include <algorithm>

using namespace std;

//Constructor for leaves nodes: constants
ArithmeticSyntaxTree::ArithmeticSyntaxTree(unsigned int value){
	isConstant=true;
	this->value=value;
	op=' ';
	leftExpr=nullptr;
	rightExpr=nullptr;
}

//Constructor for leaves nodes: constants
ArithmeticSyntaxTree::ArithmeticSyntaxTree(char op, ArithmeticSyntaxTree * leftExpr,ArithmeticSyntaxTree * rightExpr){
	isConstant=false;
	value=-1;
	this->op=op;
	this->leftExpr=leftExpr;
	this->rightExpr=rightExpr;
}

//destructor
ArithmeticSyntaxTree::~ArithmeticSyntaxTree(){
	if(leftExpr!=nullptr){
		delete leftExpr;
	}
	if(rightExpr!=nullptr){
		delete rightExpr;
	}
}

int ArithmeticSyntaxTree::size(void) const{

	// The size of a constant is 1
	if(isConstant){
		return 1;
	}
	else{
		// The size of a compound expression is 1
		//plus the number of nodes in the sub-trees
		return 1 + leftExpr->size() + rightExpr->size();
	}
}

int ArithmeticSyntaxTree::height(void) const{

	// The height of a constant is 1
	if(isConstant){
		return 1;
	}
	else{
		// The height of a compound expression is 1
		// plus the maximum height of its sub-trees
		return 1 + max(leftExpr->height(),rightExpr->height());
	}
}

// The number of leaves can be computed in a similar fashion to
// size() and height()

int ArithmeticSyntaxTree::leaves(void) const{

	// The size of a constant is 1
	if(isConstant){
		return 1;
	}
	else{
		// The number of leaves of a compound expression is
		//the number of leaves in the sub-trees
		return leftExpr->leaves() + rightExpr->leaves();
	}

}


// Methods that implement the three (in, pre, post) traversal methods

void ArithmeticSyntaxTree::traverse_pre(void){
	if(isConstant){
		cout << value;
	}
	else{
		cout << op << "(";
		leftExpr->traverse_pre();
		cout << ",";
		rightExpr->traverse_pre();
		cout << ")";
	}
}
//+(+(*(2,3),*(4,5)),1)

void ArithmeticSyntaxTree::traverse_in(void){
	if(isConstant){
		cout << value;
	}
	else{
		cout << "(";
		leftExpr->traverse_in();
		cout << ")" << op << "(";
		rightExpr->traverse_in();
		cout << ")";
	}
}
//(((2)*(3))+((4)*(5)))+(1)

/*
void Expression::traverse_in(void){
	if(isNumber){
		cout << value;
	}
	else{
		if(!leftExpr->isNumber){
			cout << "(";
		}
		leftExpr->traverse_in();
		if(!leftExpr->isNumber){
			cout << ")";
		}
		cout << op;
		if(!rightExpr->isNumber){
			cout << "(";
		}
		rightExpr->traverse_in();
		if(!rightExpr->isNumber){
			cout << ")";
		}
	}
}
*/
//((2*3)+(4*5))+1


