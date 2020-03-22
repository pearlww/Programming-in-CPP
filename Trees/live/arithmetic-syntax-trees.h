#ifndef __ARITHMETIC_SYNTAX_TREES__
#define __ARITHMETIC_SYNTAX_TREES__

using namespace std;

class ArithmeticSyntaxTree {
    
public:
	ArithmeticSyntaxTree(unsigned int value);   // constructor for leaf nodes (just numbers)
	ArithmeticSyntaxTree(char oper, ArithmeticSyntaxTree * leftExpr,ArithmeticSyntaxTree * rightExpr); //constructor for compund nodes (leftExpr + rightExpr, or  leftExpr * rightExpr)
    ~ArithmeticSyntaxTree();                    // destructor
    int size() const;             // size of the tree
    int height() const;           // height of the tree
    int leaves() const;           // number of leaves in the tree (the number of constants)
    void traverse_pre();    // print nodes in pre-order (prefix notation)
    void traverse_in();		//print nodes in in-order (in-fix notation)
    
private:
    bool isConstant;	// flag to specify it the node is a number of an compound operator (+,*)
    int value;		// if the node is a leaf, this member contains the value of the node
    char op;	// if the node is not a leaf, then it is eithe a sum ('+') or a multiplication ('*') among expressions
    ArithmeticSyntaxTree *leftExpr;     // pointer to the left sub-expression (sub-tree)
    ArithmeticSyntaxTree *rightExpr;    // pointer to the right sub-expression (sub-tree)
};

#endif
