#include "ex02-library.h"
#include <iostream>

//Do not modify
void printSet(set<string> s){
  if(s.size()==0){
    cout << " No nodes\n";
  }
  else{
    set<string>::iterator it;
    for (it=s.begin(); it!=s.end(); ++it){
      cout << ' ' << *it << "\n";
    }
  }
  cout << "\n";
}

//Exercise 2 (a) Check and correct if necessary
void computeLeaves(Node *n, set<string> & leaves){
	if (n == nullptr)
		return;
	
  else if(n->left == nullptr && n->right == nullptr){
    leaves.insert(n->name);
	return;
  }
  else{
    computeLeaves(n->left,leaves);
    computeLeaves(n->right,leaves);
  }
}

//Exercise 2 (b) Implement this function
int countDescendants(Node * n){
  //Put your code here
	int m1,m2;
	if (n == nullptr)
		return 0;
	if (n->left == nullptr && n->right == nullptr)
		return 0;
	if (n->left != nullptr && n->right == nullptr){
		return 1 + countDescendants(n->left);
	}
	if (n->left == nullptr && n->right != nullptr){
		return 1 + countDescendants(n->right);
	}
	else
		return 2 + countDescendants(n->left) + countDescendants(n->right);
}
