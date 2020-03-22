#include <iostream>
#include "ex02-library.h"
using namespace std;

void experimentLeafNodes(Node * n){
  set<string> leaves;
  computeLeaves(n,leaves);
  cout<<"Leaf nodes starting from " 
       << n->name << ":\n";
  printSet(leaves);
}

void experimentDescendants(Node * n){
  int descendants = countDescendants(n);
  cout<< n->name << "'s descendants:"
       << descendants << "\n";
}

int main() {
  /* Bob's family tree from text */
  Node *Alice = new Node;
  Alice->name="Alice";
  Node *Bob = new Node;
  Bob->name="Bob";
  Node *Carl = new Node;
  Carl->name="Carl";
  Node *Daisy = new Node;
  Daisy->name="Daisy";
  Node *Emma = new Node;
  Emma->name="Emma";
  Alice->left=Bob;
  Alice->right=Carl;
  Bob->left=Daisy;
  Bob->right=nullptr;  
  Carl->right=Emma;
  Carl->left=nullptr;
  Daisy->left=nullptr;
  Daisy->right=nullptr;
  Emma->left=nullptr;
  Emma->right=nullptr;

  cout << "Experiments about leaf nodes\n";
  experimentLeafNodes(Alice);
  experimentLeafNodes(Bob);
  experimentLeafNodes(Carl);
  experimentLeafNodes(Daisy);
  experimentLeafNodes(Emma);


  cout << "Experiments about descendants\n";
  experimentDescendants(Alice);
  experimentDescendants(Bob);
  experimentDescendants(Carl);
  experimentDescendants(Daisy);
  experimentDescendants(Emma);

  system("pause");
  return 0;
}